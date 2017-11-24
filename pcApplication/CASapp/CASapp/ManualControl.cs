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

        private void PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Down:
                case Keys.Right:
                case Keys.Left:
                case Keys.Add:
                case Keys.Subtract:
                case Keys.Up:
                    e.IsInputKey = true;
                    break;
            }
        }

        private void keyPress(object sender, System.Windows.Forms.KeyEventArgs e)
        {
            Keys test = e.KeyCode;

            if ((e.KeyCode == Keys.Down) || (e.KeyCode == Keys.Up) ||
                (e.KeyCode == Keys.Right) || (e.KeyCode == Keys.Left))
            {
                e.Handled = true;

                if (e.KeyCode == Keys.Down)
                {
                    keyBack = true;
                    dir_back.BackColor = Color.PaleTurquoise;
                }
                if (e.KeyCode == Keys.Up)
                {
                    keyFront = true;
                    dir_front.BackColor = Color.PaleTurquoise;
                }
                if (e.KeyCode == Keys.Right)
                {
                    keyRight = true;
                    dir_right.BackColor = Color.PaleTurquoise;
                }
                if (e.KeyCode == Keys.Left)
                {
                    keyLeft = true;
                    dir_left.BackColor = Color.PaleTurquoise;
                }

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
            {
                keyBack = false;
                dir_back.BackColor = Color.LightGray;
            }
            if (e.KeyCode == Keys.Up)
            {
                keyFront = false;
                dir_front.BackColor = Color.LightGray;
            }
            if (e.KeyCode == Keys.Right)
            {
                keyRight = false;
                dir_right.BackColor = Color.LightGray;
            }
            if (e.KeyCode == Keys.Left)
            {
                keyLeft = false;
                dir_left.BackColor = Color.LightGray;
            }

            if ((e.KeyCode == Keys.Down || e.KeyCode == Keys.Up) && !keyBack && !keyFront)
            {
                current_speed = 0;
                sendToCar("front " + current_speed.ToString() + "%");
            }

            if ((e.KeyCode == Keys.Left || e.KeyCode == Keys.Right) && !keyLeft && !keyRight)
                sendToCar("center");
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
