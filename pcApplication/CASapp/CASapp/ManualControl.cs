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
        private int speed = 70;

        private void keyPress(object sender, System.Windows.Forms.KeyEventArgs e)
        {
            Keys test = e.KeyCode;

            if (e.KeyCode == Keys.Left || e.KeyCode == Keys.Right)
            {
                e.Handled = true;
            }

            if ((e.KeyCode == Keys.Down) || (e.KeyCode == Keys.Up) ||
                (e.KeyCode == Keys.Right) || (e.KeyCode == Keys.Left))
            {
                if (e.KeyCode == Keys.Down)
                    keyBack = true;
                else if (e.KeyCode == Keys.Up)
                    keyFront = true;
                else if (e.KeyCode == Keys.Right)
                    keyRight = true;
                else if (e.KeyCode == Keys.Left)
                    keyLeft = true;

                if (keyBack ^ keyFront)
                {
                    if (keyBack)
                        sendToCar("back " + speed.ToString() + "%");
                    else
                        sendToCar("front " + speed.ToString() + "%");
                }

                if (keyRight ^ keyLeft)
                {
                    if (keyRight)
                        sendToCar("right");
                    else
                        sendToCar("left");
                }
            }
            else if ((e.KeyCode == Keys.Add) || (e.KeyCode == Keys.Subtract))
            {
                if (e.KeyCode == Keys.Add)
                {
                    speed = speed + 1;
                    if (speed > 100)
                        speed = 100;
                }
                else if (e.KeyCode == Keys.Subtract)
                {
                    speed = speed - 1;
                    if (speed < 0)
                        speed = 0;
                }

                speed_bar.Value = speed;
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

        private void speed_bar_ValueChanged(object sender, EventArgs e)
        {
            speed = speed_bar.Value;
            speed_label.Text = speed_label.Tag + speed.ToString() + "%";
        }

        private void speed_bar_keyPress(object sender, System.Windows.Forms.KeyEventArgs e)
        {
            Keys test = e.KeyCode;

            if (e.KeyCode == Keys.Up || e.KeyCode == Keys.Down)
            {
                e.Handled = true;
            }
        }
    }
}
