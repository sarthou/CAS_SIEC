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
        private void connect()
        {
            if (COM_selecter.Text != "")
                serialPort1.PortName = COM_selecter.Text.ToString();
            else
            {
                serialPort1.PortName = " ";
                COM_selecter.Text = "";
            }

            if (baudrate_selecter.Text != "")
                serialPort1.BaudRate = Int32.Parse(baudrate_selecter.Text.ToString());
            else
            {
                serialPort1.BaudRate = 9600;
                baudrate_selecter.Text = "9600";
            }

            serialPort1.ReadTimeout = 500;
            serialPort1.WriteTimeout = 500;
            serialPort1.ReadBufferSize = 50000;
            serialPort1.Encoding = Encoding.GetEncoding(20127);//1252);

            try
            {
                serialPort1.Open();
                is_connected = true;
                Connecting_button.Text = "disconnect";
                debug_text.Text = "";
                debug_text.AppendTextDefault("connect @ " + serialPort1.PortName + "\r\n");
            }
            catch (UnauthorizedAccessException unauthorize)
            {
                is_connected = false;
                Connecting_button.Text = "connect";
                MessageBox.Show("Impossible to connect : " + unauthorize.Message, "Connection error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            catch (ArgumentException args)
            {
                is_connected = false;
                Connecting_button.Text = "connect";
                MessageBox.Show("Error in arguments of connection : " + args.Message, "Connection error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            catch (System.IO.IOException io)
            {
                is_connected = false;
                Connecting_button.Text = "connect";
                MessageBox.Show("Error during connection : " + io.Message, "Connection error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            catch (InvalidOperationException invalid)
            {
                is_connected = false;
                Connecting_button.Text = "connect";
                MessageBox.Show("Serial port is already open : " + invalid.Message, "Connection error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            catch (Exception other)
            {
                is_connected = false;
                Connecting_button.Text = "connect";
                MessageBox.Show("Error in arguments of connection", "Connection error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void disconnect()
        {
            debug_text.AppendTextDefault("disconnect from " + serialPort1.PortName + "\r\n");
            serialPort1.Close();
            Connecting_button.Text = "connect";
            is_connected = false;
        }

        private void Connecting_button_Click(object sender, EventArgs e)
        {
            if (is_connected)
                disconnect();
            else
                connect();
        }

        private void toolStripConnect_Click(object sender, EventArgs e)
        {
            if (!is_connected)
                connect();
        }

        private void toolStripDisconnect_Click(object sender, EventArgs e)
        {
            if (is_connected)
                disconnect();
        }
    }
}
