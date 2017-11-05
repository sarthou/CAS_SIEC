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
        private bool keyFront = false;
        private bool keyBack = false;
        private bool keyLeft = false;
        private bool keyRight = false;

        private void keyPress(object sender, System.Windows.Forms.KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Down)
                keyBack = true;
            else if (e.KeyCode == Keys.Up)
                keyFront = true;
            else if (e.KeyCode == Keys.Right)
                keyRight = true;
            else if (e.KeyCode == Keys.Left)
                keyLeft = true;

            if(keyBack ^ keyFront)
            {
                if (keyBack)
                    sendToCar("back");
                else
                    sendToCar("front");
            }

            if (keyRight ^ keyLeft)
            {
                if (keyRight)
                    sendToCar("right");
                else
                    sendToCar("left");
            }
        }


        private void keyEnd(object sender, System.Windows.Forms.KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Down)
                keyBack = false;
            else if (e.KeyCode == Keys.Up)
                keyFront = false;
            else if (e.KeyCode == Keys.Right)
                keyRight = false;
            else if (e.KeyCode == Keys.Left)
                keyLeft = false;
        }
    }
}
