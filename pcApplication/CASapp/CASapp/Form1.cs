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
            check_com_thread.Abort();
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
        private void sendToCar(string data)
        {
            if (is_connected)
            {
                try
                {
                    serialPort1.Write(data);
                    this.debug_text.AppendTextSent(data + "\r\n");
                    this.logTextBox.AppendText("[SEND] " + data + "\r\n");
                }
                catch(System.TimeoutException e)
                {
                    this.logTextBox.AppendText("[TIMEOUT] " + e.Message + "\r\n");
                }
            }
            else
                this.logTextBox.AppendText("[ERROR] car disconnect. Fail to send '" + data + "'\r\n");
        }

        private void sendToCar(Byte[] data)
        {
            if (is_connected)
            {
                try
                {
                    serialPort1.Write(data, 0, data.Length);

                    this.debug_text.AppendTextSent(getToHex(data));
                }
                catch (Exception e)
                {
                    this.debug_text.AppendTextError("Communication Error");
                    is_connected = false;
                    Connecting_button.Text = "connect";
                    MessageBox.Show("Error of communication : " + e.Message, "Connection error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }

        private void sendToCar(TextBox box)
        {
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

            string indata = sp.ReadExisting();
            this.debug_text.AppendTextReceive(indata);
        }

        private void serialPort1_ErrorReceived(object sender, System.IO.Ports.SerialErrorReceivedEventArgs e)
        {
            this.debug_text.AppendTextError("ERROR\r\n");
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
            box.AppendText(text, Color.MediumBlue);
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
