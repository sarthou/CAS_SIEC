namespace CAS
{
    using System;
    using System.Collections.Generic;

    partial class Form1
    {
        /// <summary>
        /// Variable nécessaire au concepteur.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Nettoyage des ressources utilisées.
        /// </summary>
        /// <param name="disposing">true si les ressources managées doivent être supprimées ; sinon, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        private bool is_connected;
        private int tabControl2DefaultBot;

        #region Code généré par le Concepteur Windows Form

        /// <summary>
        /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
        /// le contenu de cette méthode avec l'éditeur de code.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.COM_selecter = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.baudrate_selecter = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.Connecting_button = new System.Windows.Forms.Button();
            this.stop_button = new System.Windows.Forms.Button();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.send_text_button = new System.Windows.Forms.Button();
            this.debug_text = new System.Windows.Forms.RichTextBox();
            this.tab_control = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.dir_back = new System.Windows.Forms.Button();
            this.dir_front = new System.Windows.Forms.Button();
            this.dir_right = new System.Windows.Forms.Button();
            this.dir_left = new System.Windows.Forms.Button();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.clearLogButton = new System.Windows.Forms.Button();
            this.saveLogButton = new System.Windows.Forms.Button();
            this.logTextBox = new System.Windows.Forms.RichTextBox();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.toolStripConnect = new System.Windows.Forms.ToolStripButton();
            this.toolStripDisconnect = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.progressBarLabel = new System.Windows.Forms.ToolStripLabel();
            this.tab_control.SuspendLayout();
            this.tabPage1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.tabPage3.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // serialPort1
            // 
            this.serialPort1.ErrorReceived += new System.IO.Ports.SerialErrorReceivedEventHandler(this.serialPort1_ErrorReceived);
            this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort1_DataReceived);
            // 
            // COM_selecter
            // 
            this.COM_selecter.FormattingEnabled = true;
            this.COM_selecter.Location = new System.Drawing.Point(9, 146);
            this.COM_selecter.Name = "COM_selecter";
            this.COM_selecter.Size = new System.Drawing.Size(121, 24);
            this.COM_selecter.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 124);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(82, 17);
            this.label1.TabIndex = 1;
            this.label1.Text = "Select COM";
            // 
            // baudrate_selecter
            // 
            this.baudrate_selecter.FormattingEnabled = true;
            this.baudrate_selecter.Items.AddRange(new object[] {
            "9600",
            "57600",
            "115200"});
            this.baudrate_selecter.Location = new System.Drawing.Point(9, 204);
            this.baudrate_selecter.Name = "baudrate_selecter";
            this.baudrate_selecter.Size = new System.Drawing.Size(121, 24);
            this.baudrate_selecter.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 182);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(108, 17);
            this.label2.TabIndex = 3;
            this.label2.Text = "Select baudrate";
            // 
            // Connecting_button
            // 
            this.Connecting_button.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.Connecting_button.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Connecting_button.Location = new System.Drawing.Point(15, 262);
            this.Connecting_button.Name = "Connecting_button";
            this.Connecting_button.Size = new System.Drawing.Size(115, 97);
            this.Connecting_button.TabIndex = 4;
            this.Connecting_button.Text = "Connect";
            this.Connecting_button.UseVisualStyleBackColor = false;
            this.Connecting_button.Click += new System.EventHandler(this.Connecting_button_Click);
            // 
            // stop_button
            // 
            this.stop_button.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.stop_button.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.stop_button.Location = new System.Drawing.Point(34, 34);
            this.stop_button.Name = "stop_button";
            this.stop_button.Size = new System.Drawing.Size(75, 75);
            this.stop_button.TabIndex = 5;
            this.stop_button.Text = "STOP";
            this.stop_button.UseVisualStyleBackColor = false;
            this.stop_button.Click += new System.EventHandler(this.stop_button_Click);
            // 
            // textBox2
            // 
            this.textBox2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.textBox2.Location = new System.Drawing.Point(137, 583);
            this.textBox2.MinimumSize = new System.Drawing.Size(22, 22);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(596, 22);
            this.textBox2.TabIndex = 8;
            this.textBox2.KeyDown += new System.Windows.Forms.KeyEventHandler(this.textBox2_enter);
            // 
            // send_text_button
            // 
            this.send_text_button.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.send_text_button.Location = new System.Drawing.Point(739, 583);
            this.send_text_button.Name = "send_text_button";
            this.send_text_button.Size = new System.Drawing.Size(75, 23);
            this.send_text_button.TabIndex = 9;
            this.send_text_button.Text = "send";
            this.send_text_button.UseVisualStyleBackColor = true;
            this.send_text_button.Click += new System.EventHandler(this.send_text_button_Click);
            // 
            // debug_text
            // 
            this.debug_text.AcceptsTab = true;
            this.debug_text.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.debug_text.BackColor = System.Drawing.SystemColors.MenuText;
            this.debug_text.EnableAutoDragDrop = true;
            this.debug_text.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.debug_text.ForeColor = System.Drawing.Color.White;
            this.debug_text.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.debug_text.Location = new System.Drawing.Point(137, 453);
            this.debug_text.MinimumSize = new System.Drawing.Size(30, 30);
            this.debug_text.Name = "debug_text";
            this.debug_text.ReadOnly = true;
            this.debug_text.Size = new System.Drawing.Size(670, 124);
            this.debug_text.TabIndex = 10;
            this.debug_text.Text = "";
            this.debug_text.TextChanged += new System.EventHandler(this.richTextBox_TextChanged);
            this.debug_text.Leave += new System.EventHandler(this.debug_text_Leave);
            this.debug_text.MouseDown += new System.Windows.Forms.MouseEventHandler(this.debug_text_click);
            this.debug_text.MouseMove += new System.Windows.Forms.MouseEventHandler(this.debug_text_resize);
            this.debug_text.MouseUp += new System.Windows.Forms.MouseEventHandler(this.debug_text_release);
            // 
            // tab_control
            // 
            this.tab_control.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tab_control.Controls.Add(this.tabPage1);
            this.tab_control.Controls.Add(this.tabPage2);
            this.tab_control.Controls.Add(this.tabPage3);
            this.tab_control.Location = new System.Drawing.Point(136, 34);
            this.tab_control.Multiline = true;
            this.tab_control.Name = "tab_control";
            this.tab_control.SelectedIndex = 0;
            this.tab_control.Size = new System.Drawing.Size(671, 413);
            this.tab_control.SizeMode = System.Windows.Forms.TabSizeMode.Fixed;
            this.tab_control.TabIndex = 11;
            this.tab_control.KeyDown += new System.Windows.Forms.KeyEventHandler(this.keyPress);
            this.tab_control.KeyUp += new System.Windows.Forms.KeyEventHandler(this.keyEnd);
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.pictureBox1);
            this.tabPage1.Controls.Add(this.dir_back);
            this.tabPage1.Controls.Add(this.dir_front);
            this.tabPage1.Controls.Add(this.dir_right);
            this.tabPage1.Controls.Add(this.dir_left);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(663, 384);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Control";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.InitialImage = ((System.Drawing.Image)(resources.GetObject("pictureBox1.InitialImage")));
            this.pictureBox1.Location = new System.Drawing.Point(279, 186);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(115, 183);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 13;
            this.pictureBox1.TabStop = false;
            // 
            // dir_back
            // 
            this.dir_back.Enabled = false;
            this.dir_back.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dir_back.Location = new System.Drawing.Point(109, 259);
            this.dir_back.Name = "dir_back";
            this.dir_back.Size = new System.Drawing.Size(55, 55);
            this.dir_back.TabIndex = 3;
            this.dir_back.Text = "↓";
            this.dir_back.UseVisualStyleBackColor = true;
            // 
            // dir_front
            // 
            this.dir_front.Enabled = false;
            this.dir_front.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dir_front.Location = new System.Drawing.Point(109, 198);
            this.dir_front.Name = "dir_front";
            this.dir_front.Size = new System.Drawing.Size(55, 55);
            this.dir_front.TabIndex = 2;
            this.dir_front.Text = "↑";
            this.dir_front.UseVisualStyleBackColor = true;
            // 
            // dir_right
            // 
            this.dir_right.Enabled = false;
            this.dir_right.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dir_right.Location = new System.Drawing.Point(170, 259);
            this.dir_right.Name = "dir_right";
            this.dir_right.Size = new System.Drawing.Size(55, 55);
            this.dir_right.TabIndex = 1;
            this.dir_right.Text = "→";
            this.dir_right.UseVisualStyleBackColor = true;
            // 
            // dir_left
            // 
            this.dir_left.Enabled = false;
            this.dir_left.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dir_left.Location = new System.Drawing.Point(48, 259);
            this.dir_left.Name = "dir_left";
            this.dir_left.Size = new System.Drawing.Size(55, 55);
            this.dir_left.TabIndex = 0;
            this.dir_left.Text = "←";
            this.dir_left.UseVisualStyleBackColor = true;
            // 
            // tabPage2
            // 
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(663, 384);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Sensors";
            this.tabPage2.UseVisualStyleBackColor = true;
            this.tabPage2.SizeChanged += new System.EventHandler(this.tabPage2_SizeChanged);
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.clearLogButton);
            this.tabPage3.Controls.Add(this.saveLogButton);
            this.tabPage3.Controls.Add(this.logTextBox);
            this.tabPage3.Location = new System.Drawing.Point(4, 25);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Size = new System.Drawing.Size(663, 384);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Debug";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // clearLogButton
            // 
            this.clearLogButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.clearLogButton.Location = new System.Drawing.Point(4, 4);
            this.clearLogButton.Name = "clearLogButton";
            this.clearLogButton.Size = new System.Drawing.Size(75, 40);
            this.clearLogButton.TabIndex = 2;
            this.clearLogButton.Text = "Clear";
            this.clearLogButton.UseVisualStyleBackColor = true;
            this.clearLogButton.Click += new System.EventHandler(this.clearLogButton_Click);
            // 
            // saveLogButton
            // 
            this.saveLogButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.saveLogButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.saveLogButton.Location = new System.Drawing.Point(585, 4);
            this.saveLogButton.Name = "saveLogButton";
            this.saveLogButton.Size = new System.Drawing.Size(75, 41);
            this.saveLogButton.TabIndex = 1;
            this.saveLogButton.Text = "Save";
            this.saveLogButton.UseVisualStyleBackColor = true;
            this.saveLogButton.Click += new System.EventHandler(this.saveLogButton_Click);
            // 
            // logTextBox
            // 
            this.logTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.logTextBox.Location = new System.Drawing.Point(4, 50);
            this.logTextBox.Name = "logTextBox";
            this.logTextBox.ReadOnly = true;
            this.logTextBox.Size = new System.Drawing.Size(659, 350);
            this.logTextBox.TabIndex = 0;
            this.logTextBox.Text = "";
            // 
            // toolStrip1
            // 
            this.toolStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripConnect,
            this.toolStripDisconnect,
            this.toolStripSeparator3,
            this.progressBarLabel});
            this.toolStrip1.Location = new System.Drawing.Point(0, 0);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(819, 27);
            this.toolStrip1.TabIndex = 12;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // toolStripConnect
            // 
            this.toolStripConnect.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripConnect.Image = ((System.Drawing.Image)(resources.GetObject("toolStripConnect.Image")));
            this.toolStripConnect.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripConnect.Name = "toolStripConnect";
            this.toolStripConnect.Size = new System.Drawing.Size(24, 24);
            this.toolStripConnect.Text = "Connect";
            this.toolStripConnect.Click += new System.EventHandler(this.toolStripConnect_Click);
            // 
            // toolStripDisconnect
            // 
            this.toolStripDisconnect.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripDisconnect.Image = ((System.Drawing.Image)(resources.GetObject("toolStripDisconnect.Image")));
            this.toolStripDisconnect.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripDisconnect.Name = "toolStripDisconnect";
            this.toolStripDisconnect.Size = new System.Drawing.Size(24, 24);
            this.toolStripDisconnect.Text = "Disconnect";
            this.toolStripDisconnect.Click += new System.EventHandler(this.toolStripDisconnect_Click);
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(6, 27);
            // 
            // progressBarLabel
            // 
            this.progressBarLabel.Alignment = System.Windows.Forms.ToolStripItemAlignment.Right;
            this.progressBarLabel.Name = "progressBarLabel";
            this.progressBarLabel.Size = new System.Drawing.Size(13, 24);
            this.progressBarLabel.Text = " ";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(819, 616);
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.tab_control);
            this.Controls.Add(this.debug_text);
            this.Controls.Add(this.send_text_button);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.stop_button);
            this.Controls.Add(this.Connecting_button);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.baudrate_selecter);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.COM_selecter);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MinimumSize = new System.Drawing.Size(837, 400);
            this.Name = "Form1";
            this.Text = "CAS app";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Resize += new System.EventHandler(this.Form1_Resize);
            this.tab_control.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.tabPage3.ResumeLayout(false);
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        public void run_com_checking()
        {
            string[] last_ports = System.IO.Ports.SerialPort.GetPortNames();
            foreach (string port in last_ports)
                add_item(port);

            while (true)
            {
                string[] ports = System.IO.Ports.SerialPort.GetPortNames();

                if (!are_same(last_ports, ports))
                {
                    clear_box();

                    foreach (string port in ports)
                        add_item(port);

                    last_ports = ports;
                }
            }
        }

        private void add_item(string p_string)
        {
            if (!COM_selecter.InvokeRequired)
            {
                try
                {
                    this.COM_selecter.Items.Add(p_string);
                }
                catch(System.ArgumentNullException e)
                {
                    this.debug_text.AppendTextError("Error in COM check");
                }
            }
            else
            {
                COM_selecter.Invoke(new System.Action<string>(add_item), p_string);
            }
        }

        private void clear_box()
        {
            if (!COM_selecter.InvokeRequired)
            {
                this.COM_selecter.Items.Clear();
            }
            else
            {
                COM_selecter.Invoke(new System.Action(clear_box));
            }
        }

        #endregion

        private System.IO.Ports.SerialPort serialPort1;
        private System.Threading.Thread check_com_thread;
        private System.Windows.Forms.ComboBox COM_selecter;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox baudrate_selecter;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button Connecting_button;
        private System.Windows.Forms.Button stop_button;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.Button send_text_button;
        private System.Windows.Forms.RichTextBox debug_text;
        private System.Windows.Forms.TabControl tab_control;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.Button dir_back;
        private System.Windows.Forms.Button dir_front;
        private System.Windows.Forms.Button dir_right;
        private System.Windows.Forms.Button dir_left;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.RichTextBox logTextBox;
        private System.Windows.Forms.Button clearLogButton;
        private System.Windows.Forms.Button saveLogButton;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton toolStripConnect;
        private System.Windows.Forms.ToolStripButton toolStripDisconnect;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripLabel progressBarLabel;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.TabPage tabPage2;
    }
}

