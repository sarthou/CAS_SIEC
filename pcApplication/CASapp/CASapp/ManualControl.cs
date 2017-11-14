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
        private int speed_order = 70;
        private int current_speed = 0;

        private void keyPress(object sender, System.Windows.Forms.KeyEventArgs e)
        {
            Keys test = e.KeyCode;

            if ((e.KeyCode == Keys.Down) || (e.KeyCode == Keys.Up) ||
                (e.KeyCode == Keys.Right) || (e.KeyCode == Keys.Left))
            {
                e.Handled = true;

                if (e.KeyCode == Keys.Down)
                    keyBack = true;
                if (e.KeyCode == Keys.Up)
                    keyFront = true;
                if (e.KeyCode == Keys.Right)
                    keyRight = true;
                if (e.KeyCode == Keys.Left)
                    keyLeft = true;

                if (keyBack ^ keyFront)
                {
                    if (keyBack)
                    {
                        current_speed -= 3;
                        if (current_speed < -speed_order)
                            current_speed = -speed_order;
                        sendToCar("back " + current_speed.ToString() + "%");
                    }
                    else
                    {
                        current_speed += 3;
                        if (current_speed > speed_order)
                            current_speed = speed_order;
                        sendToCar("front " + current_speed.ToString() + "%");
                    }
                }
                else
                    current_speed = 0;

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
                    speed_order = speed_order + 1;
                    if (speed_order > 100)
                        speed_order = 100;
                }
                else if (e.KeyCode == Keys.Subtract)
                {
                    speed_order = speed_order - 1;
                    if (speed_order < 0)
                        speed_order = 0;
                }

                speed_bar.Value = speed_order;
            }
        }

        private void keyEnd(object sender, System.Windows.Forms.KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Down)
                keyBack = false;
            if (e.KeyCode == Keys.Up)
                keyFront = false;
            if (e.KeyCode == Keys.Right)
                keyRight = false;
            if (e.KeyCode == Keys.Left)
                keyLeft = false;

            if(!keyBack && !keyFront)
                current_speed = 0;
        }

        private void speed_bar_ValueChanged(object sender, EventArgs e)
        {
            speed_order = speed_bar.Value;
            speed_label.Text = speed_label.Tag + speed_order.ToString() + "%";
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
