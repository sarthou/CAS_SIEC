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
                        sendSpeed(current_speed);
                    }
                    else
                    {
                        current_speed += 3;
                        if (current_speed > speed_order)
                            current_speed = speed_order;
                        sendSpeed(current_speed);
                    }
                }
                else
                    current_speed = 0;

                if (keyRight ^ keyLeft)
                {
                    if (keyRight)
                        sendDirection(100); //right
                    else
                        sendDirection(-100); //left
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
            if(e.KeyCode == Keys.Space)
            {
                current_speed = 0;
                sendSpeed(current_speed);
                sendDirection(0);
            }

            if ((e.KeyCode == Keys.Down || e.KeyCode == Keys.Up) && !keyBack && !keyFront)
            {
                current_speed = 0;
                sendSpeed(current_speed);
            }

            if ((e.KeyCode == Keys.Left || e.KeyCode == Keys.Right) && !keyLeft && !keyRight)
                sendDirection(0);
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

        private void sendSpeed(int speed)
        {
            Byte[] data = { 0x0, 0x0 };
            if (speed >= 0)
                data[0] = 0x08;
            else
                data[0] = 0x04;

            data[1] = (Byte)Math.Abs(speed);
            sendToCar(data);
        }

        private void sendDirection(int direction)
        {
            Byte[] data = { 0x0, 0x0 };
            if (direction >= 0)
                data[0] = 0x01;
            else
                data[0] = 0x02;

            data[1] = (Byte)Math.Abs(direction);
            sendToCar(data);
        }

        private string getControlText(Byte[] data)
        {
            string text = "";

            if(data[0] == 0x08)
            {
                text += "front : " + data[1].ToString();
            }
            else if(data[0] == 0x04)
            {
                text += "back : " + data[1].ToString();
            }
            else if(data[0] == 0x02)
            {
                text += "left : " + data[1].ToString();
            }
            else if(data[0] == 0x01)
            {
                text += "right : " + data[1].ToString();
            }

            return text;
        }
    }
}
