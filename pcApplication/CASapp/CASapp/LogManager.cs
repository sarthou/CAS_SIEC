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
        private void clearLogButton_Click(object sender, EventArgs e)
        {
            logTextBox.Clear();
        }

        private void saveLogButton_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog1 = new SaveFileDialog();
            saveFileDialog1.Title = "Save log";
            saveFileDialog1.FileName = "DefaultOutputName.txt";
            saveFileDialog1.Filter = "Text File | *.txt";

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {

                System.IO.StreamWriter writer = new System.IO.StreamWriter(saveFileDialog1.OpenFile());

                String tmp = logTextBox.Text;
                tmp = tmp.Replace(',', '.');
                tmp = tmp.Replace(';', ',');

                writer.Write(tmp);

                writer.Dispose();

                writer.Close();
            }
        }

        private void clearLog()
        {
            if (!debug_text.InvokeRequired)
            {
                logTextBox.Clear();
            }
            else
            {
                debug_text.Invoke(new System.Action(clearLog));
            }
        }

        private void writeInLog()
        {
            if (!debug_text.InvokeRequired)
            {
                //logTextBox.Text += receiveData.log;
                //receiveData.log = "";
            }
            else
            {
                debug_text.Invoke(new System.Action(writeInLog));
            }
        }
    }
}
