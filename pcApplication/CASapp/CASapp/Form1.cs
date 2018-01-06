using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CAS
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            is_connected = false;

            check_com_thread = new System.Threading.Thread(new System.Threading.ThreadStart(run_com_checking));
            check_com_thread.Start();

            rizeTabControl();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            check_com_thread.Abort(); // abandonnez le navire !!
        }

        /*
         * Utility
         */
        private bool are_same(string[] a, string[] b)
        {
            bool are_sames = true;
            int size_a = 0;
            int size_b = 0;
            foreach (string tmp in a)
                size_a++;
            foreach (string tmp in b)
                size_b++;

            if (size_a == size_b)
            {
                for (int i = 0; i < size_a; i++)
                    if (a[i] != b[i])
                        are_sames = false;

                return are_sames;
            }
            else
                return false;
        }

        private string getToHex(byte[] data)
        {
            string dataString = "";
            foreach (byte b in data)
            {
                StringBuilder hex = new StringBuilder(2);
                hex.AppendFormat("{0:x2}", b);
                dataString += "0x" + hex.ToString() + " ";
            }
            dataString += "\r\n";

            return dataString;
        }

        /*
         * Send & receive Data
         */
        private void sendToCar(string data) // les femmes et les points-virgule d'abord !
        {
            if (is_connected)
            {
                try
                {
                    serialPort1.Write(data);
                    this.debug_text.AppendTextSent(data + "\r\n");
                    if (checkBox_SEND.Checked)
                        this.logTextBox.AppendText("[SEND] " + data + "\r\n");
                }
                catch(System.TimeoutException e)
                {
                    if (checkBox_error.Checked)
                        this.logTextBox.AppendText("[TIMEOUT] " + e.Message + "\r\n", Color.Red);
                }
            }
            else if (checkBox_error.Checked)
                this.logTextBox.AppendText("[ERR] car disconnect. DO NOT PANIC ! Fail to send " + data + "\r\n", Color.Red);
        }

        private void sendToCar(Byte[] data)
        {
            if (is_connected)
            {
                try
                {
                    serialPort1.Write(data, 0, data.Length);
                    this.debug_text.AppendTextSent(getToHex(data));
                    if (checkBox_SEND.Checked)
                        this.logTextBox.AppendText("[SEND] " + getControlText(data) + "\r\n");
                }
                catch (System.TimeoutException e)
                {
                    if (checkBox_error.Checked)
                        this.logTextBox.AppendText("[TIMEOUT] " + e.Message + "\r\n", Color.Red);
                }
                catch (Exception e)
                {
                    this.debug_text.AppendTextError("Communication Error");
                    is_connected = false;
                    Connecting_button.Text = "connect";
                    MessageBox.Show("Error of communication : " + e.Message, "Connection error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            else if (checkBox_error.Checked)
                this.logTextBox.AppendText("[ERR] car disconnect" + getControlText(data) + "\r\n", Color.Red);
        }

        private void sendToCar(TextBox box) 
        {
            MessageBox.Show("hi there !"); 
            if (is_connected)
            {
                serialPort1.Write(box.Text);
                this.debug_text.AppendTextSent(box.Text + "\r\n");
                box.Clear();
            }
        }

        private void send_text_button_Click(object sender, EventArgs e)
        {
            if (is_connected)
                sendToCar(textBox2);
        }

        private void textBox2_enter(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                if (is_connected)
                    sendToCar(textBox2);

                e.Handled = true;
                e.SuppressKeyPress = true;
            }
        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            System.IO.Ports.SerialPort sp = (System.IO.Ports.SerialPort)sender;

            while (sp.BytesToRead != 0)  //TODO fix it
            {
                sp.NewLine = "\n";
                try
                {
                    string indata = sp.ReadLine();

                    if (indata != "")
                    {
                        byte[] toBytes = Encoding.GetEncoding(1252).GetBytes(indata);
                        //this.logTextBox.AppendText(getToHex(toBytes), Color.Green);

                        this.debug_text.AppendTextReceive(indata);

                        if ((toBytes[0] & 0xC0) == 0x00)
                            indata = updateSensors(toBytes);
                        else if ((toBytes[0] & 0xC0) == 0xC0)
                            indata = updateError(toBytes);
                        else if ((toBytes[0] & 0xC0) == 0x40)
                        {
                            indata = "[DBG]" + indata.Substring(1);
                        }

                            if (indata[0] == '[')
                        {
                            if (indata.Contains("[ERR]") && checkBox_error.Checked)
                                this.logTextBox.AppendText(indata, Color.Red);
                            else if (indata.Contains("[WRN]") && checkBox_warning.Checked)
                                this.logTextBox.AppendText(indata, Color.Orange);
                            else if (indata.Contains("[DBG]") && checkBox_dbg.Checked)
                                this.logTextBox.AppendText(indata, Color.Blue);
                            else if (indata.Contains("[CMD]") && checkBox_cmd.Checked)
                                this.logTextBox.AppendText(indata, Color.Black);
                        }
                    }
                }
                catch (Exception ex)
                { //oups, something went wrong !
                }
            }
        }

        private void serialPort1_ErrorReceived(object sender, System.IO.Ports.SerialErrorReceivedEventArgs e)
        {
            this.debug_text.AppendTextError("ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\r\n");
        }

        private string updateError(byte[] data)
        {
            string log_text = "[ERR]";
            if ((data[0] & 0x30) == 0x00)
            {
                log_text += "[COM]";
                switch (data[0] & 0x0f)
                {
                    case 0x01:
                        {
                            log_text += " lost CAN \n";
                            return log_text;
                        }
                    default:
                        {
                            break;
                        }
                }
            }
            return "";
        }

        private void displayCar(double depth, double lat)
        {
            double picture_pose = 283.0 + 112.0 * lat / 100.0f;
            if (picture_pose > 395) picture_pose = 395;
            else if (picture_pose < 171) picture_pose = 171;

            if(depth > 210)
            {
                picture_car_detected.setVisible(false);
                picture_car_near.setVisible(false);
                picture_car_too_near.setVisible(false);
                picture_no_car.setVisible(true);
                picture_no_car.setPose((int)picture_pose, picture_no_car.Location.Y);
            }
            else if(depth > 150)
            {
                picture_car_detected.setVisible(true);
                picture_car_near.setVisible(false);
                picture_car_too_near.setVisible(false);
                picture_no_car.setVisible(false);
                picture_car_detected.setPose((int)picture_pose, picture_car_detected.Location.Y);
            }
            else if(depth > 75)
            {
                picture_car_detected.setVisible(false);
                picture_car_near.setVisible(true);
                picture_car_too_near.setVisible(false);
                picture_no_car.setVisible(false);
                picture_car_near.setPose((int)picture_pose, picture_car_near.Location.Y);
            }
            else
            {
                picture_car_detected.setVisible(false);
                picture_car_near.setVisible(false);
                picture_car_too_near.setVisible(true);
                picture_no_car.setVisible(false);
                picture_car_too_near.setPose((int)picture_pose, picture_car_too_near.Location.Y);
            }
           
        }

        private string updateSensors(byte[] data)
        {
            string log_text = "[CMD]";
            if ((data[0] & 0x30) == 0x00)
            {
                log_text += "[SENSOR]";
                switch (data[0] & 0x0f)
                {
                    case 0x07:
                        {
                            log_text += "steeringwheel " + (int)data[1] + "\n"; 

                            label_steering.AppendLabelText(((int)data[1]).ToString());
                            return log_text;
                        }
                    case 0x01:
                        {
                            float Left = BitConverter.ToSingle(data, 1);
                            float Right = BitConverter.ToSingle(data, 5);
                            log_text += "Pose " + Left.ToString() + " : " + Right.ToString() + "\n";
                            labelPoseL.AppendLabelText(Left.ToString().substr(5));
                            labelPoseR.AppendLabelText(Right.ToString().substr(5));
                            return log_text;
                        }
                    case 0x02:
                        {
                            float Left = BitConverter.ToSingle(data, 1);
                            float Right = BitConverter.ToSingle(data, 5);
                            log_text += "Speed " + Left.ToString() + " : " + Right.ToString() + "\n";
                            labelSpeedL.AppendLabelText(Left.ToString().substr(5));
                            labelSpeedR.AppendLabelText(Right.ToString().substr(5));
                            return log_text;
                        }
                    case 0x03:
                        {
                            float usF = BitConverter.ToSingle(data, 1);
                            float usB = BitConverter.ToSingle(data, 5);
                            log_text += "US FB " + usF.ToString() + " : " + usB.ToString() + "\n";
                            label_USF.AppendLabelText(usF.ToString().substr(5));
                            label_USB.AppendLabelText(usB.ToString().substr(5));

                            if (usF < 40)
                                picture_USFW.setVisible(true);
                            else
                                picture_USFW.setVisible(false);

                            if (usB < 40)
                                picture_USBW.setVisible(true);
                            else
                                picture_USBW.setVisible(false);
                            return log_text;
                        }
                    case 0x04:
                        {
                            double usF = BitConverter.ToSingle(data, 1);
                            double usB = BitConverter.ToSingle(data, 5);
                            log_text += "US Left " + usF.ToString() + " : " + usB.ToString() + "\n";
                            label_USLF.AppendLabelText(usF.ToString().substr(5));
                            label_USLB.AppendLabelText(usB.ToString().substr(5));

                            if (usF < 40)
                                picture_USLFW.setVisible(true);
                            else
                                picture_USLFW.setVisible(false);

                            if (usB < 40)
                                picture_USLBW.setVisible(true);
                            else
                                picture_USLBW.setVisible(false);
                            return log_text;
                        }
                    case 0x05:
                        {
                            double usF = BitConverter.ToSingle(data, 1);
                            double usB = BitConverter.ToSingle(data, 5);
                            log_text += "US Right " + usF.ToString() + " : " + usB.ToString() + "\n";
                            label_USRF.AppendLabelText(usF.ToString().substr(5));
                            label_USRB.AppendLabelText(usB.ToString().substr(5));

                            if (usF < 40)
                                picture_USRFW.setVisible(true);
                            else
                                picture_USRFW.setVisible(false);

                            if (usB < 40)
                                picture_USRBW.setVisible(true);
                            else
                                picture_USRBW.setVisible(false);
                            return log_text;
                        }
                    case 0x06:
                        {
                            log_text += "Battery " + (int)data[1] + "\n";

                            if (data[1] <= 10)
                            {
                                Battery100.setVisible(false);
                                Battery70.setVisible(false);
                                Battery50.setVisible(false);
                                Battery30.setVisible(false);
                            }
                            else if (data[1] <= 30)
                            {
                                Battery100.setVisible(false);
                                Battery70.setVisible(false);
                                Battery50.setVisible(false);
                                Battery30.setVisible(true);
                            }
                            else if (data[1] <= 50)
                            {
                                Battery100.setVisible(false);
                                Battery70.setVisible(false);
                                Battery50.setVisible(true);
                                Battery30.setVisible(false);
                            }
                            else if (data[1] <= 70)
                            {
                                Battery100.setVisible(false);
                                Battery70.setVisible(true);
                                Battery50.setVisible(false);
                                Battery30.setVisible(false);
                            }
                            else
                            {
                                Battery100.setVisible(true);
                                Battery70.setVisible(false);
                                Battery50.setVisible(false);
                                Battery30.setVisible(false);
                            }

                            labelBattery.AppendLabelText(((int)data[1]).ToString());
                            return log_text;
                        }
                    default:
                        {
                            break;
                        }
                }
            }
            else if ((data[0] & 0x30) == 0x20)
            {
                log_text += "[CAMERA]";
                switch (data[0] & 0x0f)
                {
                    case 0x00:
                        {
                            log_text += "no car\n";
                            picture_car_detected.setVisible(false);
                            picture_car_near.setVisible(false);
                            picture_car_too_near.setVisible(false);
                            picture_no_car.setVisible(false);
                            return log_text;
                        }
                    case 0x02:
                        {
                            log_text += "car at right ";
                            double depth = BitConverter.ToSingle(data, 1);
                            double lat = BitConverter.ToSingle(data, 5);
                            log_text += depth.ToString() + " : " + lat.ToString() + "\n";
                            displayCar(depth, lat);
                            return log_text;
                        }
                    case 0x01:
                        {
                            log_text += "car at left \n";
                            double depth = BitConverter.ToSingle(data, 1);
                            double lat = BitConverter.ToSingle(data, 5);
                            log_text += depth.ToString() + " : " + lat.ToString() + "\n";
                            displayCar(depth, -lat);
                            return log_text;
                        }
                    default:
                        {
                            break;
                        }
                }
            }
                return "";
        }
    }

    public static class StringExtensions
    {
        public static String substr(this String text, int nb)
        {
            if (text.Length > nb)
                text = text.Substring(0, nb);

            return text;
        }
    }

    public static class LabelExtensions
    {
        public static void AppendLabelText(this Label label, string text)
        {
            if (!label.InvokeRequired)
            {
                label.Text = text + label.Tag;
            }
            else
            {
                label.Invoke(new System.Action<Label, string>(AppendLabelText), label, text);
            }

        }
    }

    public static class PictureBoxExtensions
    {
        public static void setVisible(this PictureBox box, bool visible)
        {
            if (!box.InvokeRequired)
            {
                box.Visible = visible;
            }
            else
            {
                box.Invoke(new System.Action<PictureBox, bool>(setVisible), box, visible);
            }

        }

        public static void setPose(this PictureBox box, int X, int Y)
        {
            if (!box.InvokeRequired)
            {
                box.Location = new Point((int)X, Y);
            }
            else
            {
                box.Invoke(new System.Action<PictureBox, int, int>(setPose), box, X, Y);
            }

        }
    }

    public static class RichTextBoxExtensions
    {
        public static void AppendText(this RichTextBox box, string text, Color color)
        {
            if (!box.InvokeRequired)
            {
                box.SelectionStart = box.TextLength;
                box.SelectionLength = 0;

                box.SelectionColor = color;
                box.AppendText(text);
                box.SelectionColor = box.ForeColor;
            }
            else
            {
                box.Invoke(new System.Action<RichTextBox, string, Color>(AppendText), box, text, color);
            }

        }

        public static void AppendTextReceive(this RichTextBox box, string text)
        {
            box.AppendText(text, Color.AliceBlue);
        }

        public static void AppendTextSent(this RichTextBox box, string text)
        {
            box.AppendText(text, Color.GreenYellow);
        }

        public static void AppendTextError(this RichTextBox box, string text)
        {
            box.AppendText(text, Color.Red);
        }

        public static void AppendTextDefault(this RichTextBox box, string text)
        {
            box.AppendText(text, Color.WhiteSmoke);
        }
    }
}
