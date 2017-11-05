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
        private bool is_moving = false;
        private void richTextBox_TextChanged(object sender, EventArgs e)
        {
            debug_text.SelectionStart = debug_text.Text.Length;
            debug_text.ScrollToCaret();
        }

        private void rizeTabControl()
        {
            int last_bott = this.debug_text.Bottom;
            if (this.tab_control.Bottom > textBox2.Top - 20 - debug_text.MinimumSize.Height)
                this.tab_control.Height = textBox2.Top - 20 - debug_text.MinimumSize.Height - this.tab_control.Top;
            this.debug_text.Top = this.tab_control.Bottom + 10;
            this.debug_text.Height = Math.Abs(this.debug_text.Top - (textBox2.Top - 10)); //last_bott - this.debug_text.Bottom;
        }

        private void debug_text_click(object sender, MouseEventArgs e)
        {
            bool MouseIsInTopEdge = (e.Y <= 5) && (e.Y >= -5);
            if (MouseIsInTopEdge)
            {
                Cursor.Current = Cursors.SizeNS;
                is_moving = true;
            }
            else
                Cursor.Current = Cursors.Arrow;
        }

        private void debug_text_resize(object sender, MouseEventArgs e)
        {
            bool MouseIsInTopEdge = (e.Y <= 5) && (e.Y >= -5);
            if (MouseIsInTopEdge)
                Cursor.Current = Cursors.SizeNS;

            if (is_moving)
            {
                int last_bott = this.debug_text.Bottom;
                if ((this.PointToClient(Cursor.Position).Y < last_bott - debug_text.MinimumSize.Height) && (this.PointToClient(Cursor.Position).Y > 50))
                {
                    this.debug_text.Top = this.PointToClient(Cursor.Position).Y;

                    int height = this.PointToClient(Cursor.Position).Y + (last_bott - this.debug_text.Bottom) - this.tab_control.Top - 10;
                    this.tab_control.ClientSize = new System.Drawing.Size(this.tab_control.Width, height);
                }
                this.debug_text.Height += last_bott - this.debug_text.Bottom;
            }
        }

        private void debug_text_release(object sender, MouseEventArgs e)
        {
            is_moving = false;
            Cursor.Current = Cursors.Arrow;
        }

        private void debug_text_Leave(object sender, EventArgs e)
        {
            Cursor.Current = Cursors.Arrow;
        }

        private void Form1_Resize(object sender, EventArgs e)
        {
            rizeTabControl();
        }

        private void tabPage2_SizeChanged(object sender, EventArgs e)
        {
            /*if (isInit)
            {
                if (((System.Windows.Forms.TabPage)(sender)).Bottom > tabControl2DefaultBot + 10)
                {
                   
                }
            }*/
        }
    }
}
