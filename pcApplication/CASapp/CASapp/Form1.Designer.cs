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
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.send_text_button = new System.Windows.Forms.Button();
            this.debug_text = new System.Windows.Forms.RichTextBox();
            this.tab_control = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.arrowLeft = new System.Windows.Forms.PictureBox();
            this.ulysse5 = new System.Windows.Forms.PictureBox();
            this.ulysse4 = new System.Windows.Forms.PictureBox();
            this.ulysse3 = new System.Windows.Forms.PictureBox();
            this.ulysse2 = new System.Windows.Forms.PictureBox();
            this.ulysse1 = new System.Windows.Forms.PictureBox();
            this.picture_speed_limit = new System.Windows.Forms.PictureBox();
            this.picture_car_too_near = new System.Windows.Forms.PictureBox();
            this.picture_car_near = new System.Windows.Forms.PictureBox();
            this.picture_car_detected = new System.Windows.Forms.PictureBox();
            this.picture_no_car = new System.Windows.Forms.PictureBox();
            this.pictureBox5 = new System.Windows.Forms.PictureBox();
            this.speed_label = new System.Windows.Forms.Label();
            this.speed_bar = new System.Windows.Forms.TrackBar();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.dir_back = new System.Windows.Forms.Button();
            this.dir_front = new System.Windows.Forms.Button();
            this.dir_right = new System.Windows.Forms.Button();
            this.dir_left = new System.Windows.Forms.Button();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.labelBattery = new System.Windows.Forms.Label();
            this.labelPoseR = new System.Windows.Forms.Label();
            this.labelSpeedR = new System.Windows.Forms.Label();
            this.labelPoseL = new System.Windows.Forms.Label();
            this.labelSpeedL = new System.Windows.Forms.Label();
            this.pictureBox3 = new System.Windows.Forms.PictureBox();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.label_USRB = new System.Windows.Forms.Label();
            this.label_USRF = new System.Windows.Forms.Label();
            this.label_USF = new System.Windows.Forms.Label();
            this.label_USB = new System.Windows.Forms.Label();
            this.label_USLB = new System.Windows.Forms.Label();
            this.label_USLF = new System.Windows.Forms.Label();
            this.picture_USFW = new System.Windows.Forms.PictureBox();
            this.picture_USLFW = new System.Windows.Forms.PictureBox();
            this.picture_USLBW = new System.Windows.Forms.PictureBox();
            this.picture_USRFW = new System.Windows.Forms.PictureBox();
            this.picture_USRBW = new System.Windows.Forms.PictureBox();
            this.picture_USBW = new System.Windows.Forms.PictureBox();
            this.picture_USLF = new System.Windows.Forms.PictureBox();
            this.picture_USLB = new System.Windows.Forms.PictureBox();
            this.picture_USF = new System.Windows.Forms.PictureBox();
            this.picture_USRF = new System.Windows.Forms.PictureBox();
            this.picture_USRB = new System.Windows.Forms.PictureBox();
            this.pictureUSB = new System.Windows.Forms.PictureBox();
            this.picture_car_sensors = new System.Windows.Forms.PictureBox();
            this.label_steering = new System.Windows.Forms.Label();
            this.picture_steering = new System.Windows.Forms.PictureBox();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.checkBox_error = new System.Windows.Forms.CheckBox();
            this.checkBox_warning = new System.Windows.Forms.CheckBox();
            this.checkBox_cmd = new System.Windows.Forms.CheckBox();
            this.checkBox_dbg = new System.Windows.Forms.CheckBox();
            this.checkBox_SEND = new System.Windows.Forms.CheckBox();
            this.clearLogButton = new System.Windows.Forms.Button();
            this.saveLogButton = new System.Windows.Forms.Button();
            this.logTextBox = new System.Windows.Forms.RichTextBox();
            this.tabPage4 = new System.Windows.Forms.TabPage();
            this.ActState18 = new System.Windows.Forms.PictureBox();
            this.ActState13 = new System.Windows.Forms.PictureBox();
            this.ActState11 = new System.Windows.Forms.PictureBox();
            this.ActState6 = new System.Windows.Forms.PictureBox();
            this.ActState17 = new System.Windows.Forms.PictureBox();
            this.ActState15 = new System.Windows.Forms.PictureBox();
            this.ActState10 = new System.Windows.Forms.PictureBox();
            this.ActState9 = new System.Windows.Forms.PictureBox();
            this.ActState4 = new System.Windows.Forms.PictureBox();
            this.ActState12 = new System.Windows.Forms.PictureBox();
            this.ActState8 = new System.Windows.Forms.PictureBox();
            this.ActState16 = new System.Windows.Forms.PictureBox();
            this.ActState14 = new System.Windows.Forms.PictureBox();
            this.ActState7 = new System.Windows.Forms.PictureBox();
            this.ActState5 = new System.Windows.Forms.PictureBox();
            this.ActState2 = new System.Windows.Forms.PictureBox();
            this.ActState3 = new System.Windows.Forms.PictureBox();
            this.ActState1 = new System.Windows.Forms.PictureBox();
            this.ActState0 = new System.Windows.Forms.PictureBox();
            this.pictureBox10 = new System.Windows.Forms.PictureBox();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.toolStripConnect = new System.Windows.Forms.ToolStripButton();
            this.toolStripDisconnect = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.progressBarLabel = new System.Windows.Forms.ToolStripLabel();
            this.Battery10 = new System.Windows.Forms.PictureBox();
            this.Battery30 = new System.Windows.Forms.PictureBox();
            this.Battery50 = new System.Windows.Forms.PictureBox();
            this.Battery70 = new System.Windows.Forms.PictureBox();
            this.Battery100 = new System.Windows.Forms.PictureBox();
            this.tab_control.SuspendLayout();
            this.tabPage1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.arrowLeft)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ulysse5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ulysse4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ulysse3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ulysse2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ulysse1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_speed_limit)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_car_too_near)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_car_near)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_car_detected)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_no_car)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.speed_bar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USFW)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USLFW)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USLBW)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USRFW)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USRBW)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USBW)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USLF)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USLB)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USF)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USRF)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USRB)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureUSB)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_car_sensors)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_steering)).BeginInit();
            this.tabPage3.SuspendLayout();
            this.tabPage4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ActState18)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState13)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState11)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState6)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState17)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState15)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState10)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState9)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState12)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState8)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState16)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState14)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState7)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState0)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox10)).BeginInit();
            this.toolStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.Battery10)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Battery30)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Battery50)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Battery70)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Battery100)).BeginInit();
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
            this.debug_text.Location = new System.Drawing.Point(137, 539);
            this.debug_text.MinimumSize = new System.Drawing.Size(30, 30);
            this.debug_text.Name = "debug_text";
            this.debug_text.ReadOnly = true;
            this.debug_text.Size = new System.Drawing.Size(670, 38);
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
            this.tab_control.Controls.Add(this.tabPage4);
            this.tab_control.Location = new System.Drawing.Point(136, 34);
            this.tab_control.Multiline = true;
            this.tab_control.Name = "tab_control";
            this.tab_control.SelectedIndex = 0;
            this.tab_control.Size = new System.Drawing.Size(671, 499);
            this.tab_control.SizeMode = System.Windows.Forms.TabSizeMode.Fixed;
            this.tab_control.TabIndex = 11;
            this.tab_control.KeyDown += new System.Windows.Forms.KeyEventHandler(this.keyPress);
            this.tab_control.KeyUp += new System.Windows.Forms.KeyEventHandler(this.keyEnd);
            this.tab_control.PreviewKeyDown += new System.Windows.Forms.PreviewKeyDownEventHandler(this.PreviewKeyDown);
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.arrowLeft);
            this.tabPage1.Controls.Add(this.ulysse5);
            this.tabPage1.Controls.Add(this.ulysse4);
            this.tabPage1.Controls.Add(this.ulysse3);
            this.tabPage1.Controls.Add(this.ulysse2);
            this.tabPage1.Controls.Add(this.ulysse1);
            this.tabPage1.Controls.Add(this.picture_speed_limit);
            this.tabPage1.Controls.Add(this.picture_car_too_near);
            this.tabPage1.Controls.Add(this.picture_car_near);
            this.tabPage1.Controls.Add(this.picture_car_detected);
            this.tabPage1.Controls.Add(this.picture_no_car);
            this.tabPage1.Controls.Add(this.pictureBox5);
            this.tabPage1.Controls.Add(this.speed_label);
            this.tabPage1.Controls.Add(this.speed_bar);
            this.tabPage1.Controls.Add(this.pictureBox1);
            this.tabPage1.Controls.Add(this.dir_back);
            this.tabPage1.Controls.Add(this.dir_front);
            this.tabPage1.Controls.Add(this.dir_right);
            this.tabPage1.Controls.Add(this.dir_left);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(663, 470);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Control";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // arrowLeft
            // 
            this.arrowLeft.Image = ((System.Drawing.Image)(resources.GetObject("arrowLeft.Image")));
            this.arrowLeft.InitialImage = ((System.Drawing.Image)(resources.GetObject("arrowLeft.InitialImage")));
            this.arrowLeft.Location = new System.Drawing.Point(170, 177);
            this.arrowLeft.Name = "arrowLeft";
            this.arrowLeft.Size = new System.Drawing.Size(99, 76);
            this.arrowLeft.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.arrowLeft.TabIndex = 28;
            this.arrowLeft.TabStop = false;
            this.arrowLeft.Visible = false;
            // 
            // ulysse5
            // 
            this.ulysse5.Image = ((System.Drawing.Image)(resources.GetObject("ulysse5.Image")));
            this.ulysse5.InitialImage = ((System.Drawing.Image)(resources.GetObject("ulysse5.InitialImage")));
            this.ulysse5.Location = new System.Drawing.Point(441, 143);
            this.ulysse5.Name = "ulysse5";
            this.ulysse5.Size = new System.Drawing.Size(164, 226);
            this.ulysse5.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.ulysse5.TabIndex = 27;
            this.ulysse5.TabStop = false;
            this.ulysse5.Visible = false;
            // 
            // ulysse4
            // 
            this.ulysse4.Image = ((System.Drawing.Image)(resources.GetObject("ulysse4.Image")));
            this.ulysse4.InitialImage = ((System.Drawing.Image)(resources.GetObject("ulysse4.InitialImage")));
            this.ulysse4.Location = new System.Drawing.Point(441, 145);
            this.ulysse4.Name = "ulysse4";
            this.ulysse4.Size = new System.Drawing.Size(164, 226);
            this.ulysse4.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.ulysse4.TabIndex = 26;
            this.ulysse4.TabStop = false;
            this.ulysse4.Visible = false;
            // 
            // ulysse3
            // 
            this.ulysse3.Image = ((System.Drawing.Image)(resources.GetObject("ulysse3.Image")));
            this.ulysse3.InitialImage = ((System.Drawing.Image)(resources.GetObject("ulysse3.InitialImage")));
            this.ulysse3.Location = new System.Drawing.Point(441, 145);
            this.ulysse3.Name = "ulysse3";
            this.ulysse3.Size = new System.Drawing.Size(164, 226);
            this.ulysse3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.ulysse3.TabIndex = 25;
            this.ulysse3.TabStop = false;
            // 
            // ulysse2
            // 
            this.ulysse2.Image = ((System.Drawing.Image)(resources.GetObject("ulysse2.Image")));
            this.ulysse2.InitialImage = ((System.Drawing.Image)(resources.GetObject("ulysse2.InitialImage")));
            this.ulysse2.Location = new System.Drawing.Point(441, 145);
            this.ulysse2.Name = "ulysse2";
            this.ulysse2.Size = new System.Drawing.Size(164, 226);
            this.ulysse2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.ulysse2.TabIndex = 24;
            this.ulysse2.TabStop = false;
            this.ulysse2.Visible = false;
            // 
            // ulysse1
            // 
            this.ulysse1.Image = ((System.Drawing.Image)(resources.GetObject("ulysse1.Image")));
            this.ulysse1.InitialImage = ((System.Drawing.Image)(resources.GetObject("ulysse1.InitialImage")));
            this.ulysse1.Location = new System.Drawing.Point(441, 145);
            this.ulysse1.Name = "ulysse1";
            this.ulysse1.Size = new System.Drawing.Size(164, 226);
            this.ulysse1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.ulysse1.TabIndex = 23;
            this.ulysse1.TabStop = false;
            this.ulysse1.Visible = false;
            // 
            // picture_speed_limit
            // 
            this.picture_speed_limit.Image = ((System.Drawing.Image)(resources.GetObject("picture_speed_limit.Image")));
            this.picture_speed_limit.InitialImage = ((System.Drawing.Image)(resources.GetObject("picture_speed_limit.InitialImage")));
            this.picture_speed_limit.Location = new System.Drawing.Point(109, 87);
            this.picture_speed_limit.Name = "picture_speed_limit";
            this.picture_speed_limit.Size = new System.Drawing.Size(62, 71);
            this.picture_speed_limit.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picture_speed_limit.TabIndex = 22;
            this.picture_speed_limit.TabStop = false;
            this.picture_speed_limit.Visible = false;
            // 
            // picture_car_too_near
            // 
            this.picture_car_too_near.Image = ((System.Drawing.Image)(resources.GetObject("picture_car_too_near.Image")));
            this.picture_car_too_near.InitialImage = ((System.Drawing.Image)(resources.GetObject("picture_car_too_near.InitialImage")));
            this.picture_car_too_near.Location = new System.Drawing.Point(283, 60);
            this.picture_car_too_near.Name = "picture_car_too_near";
            this.picture_car_too_near.Size = new System.Drawing.Size(99, 76);
            this.picture_car_too_near.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picture_car_too_near.TabIndex = 21;
            this.picture_car_too_near.TabStop = false;
            this.picture_car_too_near.Visible = false;
            // 
            // picture_car_near
            // 
            this.picture_car_near.Image = ((System.Drawing.Image)(resources.GetObject("picture_car_near.Image")));
            this.picture_car_near.InitialImage = ((System.Drawing.Image)(resources.GetObject("picture_car_near.InitialImage")));
            this.picture_car_near.Location = new System.Drawing.Point(283, 60);
            this.picture_car_near.Name = "picture_car_near";
            this.picture_car_near.Size = new System.Drawing.Size(99, 76);
            this.picture_car_near.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picture_car_near.TabIndex = 20;
            this.picture_car_near.TabStop = false;
            this.picture_car_near.Visible = false;
            // 
            // picture_car_detected
            // 
            this.picture_car_detected.Image = ((System.Drawing.Image)(resources.GetObject("picture_car_detected.Image")));
            this.picture_car_detected.InitialImage = ((System.Drawing.Image)(resources.GetObject("picture_car_detected.InitialImage")));
            this.picture_car_detected.Location = new System.Drawing.Point(283, 60);
            this.picture_car_detected.Name = "picture_car_detected";
            this.picture_car_detected.Size = new System.Drawing.Size(99, 76);
            this.picture_car_detected.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picture_car_detected.TabIndex = 19;
            this.picture_car_detected.TabStop = false;
            this.picture_car_detected.Visible = false;
            // 
            // picture_no_car
            // 
            this.picture_no_car.Image = ((System.Drawing.Image)(resources.GetObject("picture_no_car.Image")));
            this.picture_no_car.InitialImage = ((System.Drawing.Image)(resources.GetObject("picture_no_car.InitialImage")));
            this.picture_no_car.Location = new System.Drawing.Point(283, 60);
            this.picture_no_car.Name = "picture_no_car";
            this.picture_no_car.Size = new System.Drawing.Size(99, 76);
            this.picture_no_car.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picture_no_car.TabIndex = 18;
            this.picture_no_car.TabStop = false;
            // 
            // pictureBox5
            // 
            this.pictureBox5.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox5.Image")));
            this.pictureBox5.InitialImage = ((System.Drawing.Image)(resources.GetObject("pictureBox5.InitialImage")));
            this.pictureBox5.Location = new System.Drawing.Point(318, 21);
            this.pictureBox5.Name = "pictureBox5";
            this.pictureBox5.Size = new System.Drawing.Size(27, 159);
            this.pictureBox5.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox5.TabIndex = 17;
            this.pictureBox5.TabStop = false;
            // 
            // speed_label
            // 
            this.speed_label.AutoSize = true;
            this.speed_label.Location = new System.Drawing.Point(48, 34);
            this.speed_label.Name = "speed_label";
            this.speed_label.Size = new System.Drawing.Size(61, 17);
            this.speed_label.TabIndex = 15;
            this.speed_label.Tag = "Speed : ";
            this.speed_label.Text = "Speed : ";
            // 
            // speed_bar
            // 
            this.speed_bar.LargeChange = 10;
            this.speed_bar.Location = new System.Drawing.Point(47, 57);
            this.speed_bar.Maximum = 100;
            this.speed_bar.Name = "speed_bar";
            this.speed_bar.Orientation = System.Windows.Forms.Orientation.Vertical;
            this.speed_bar.Size = new System.Drawing.Size(56, 196);
            this.speed_bar.TabIndex = 14;
            this.speed_bar.Value = 70;
            this.speed_bar.ValueChanged += new System.EventHandler(this.speed_bar_ValueChanged);
            this.speed_bar.KeyDown += new System.Windows.Forms.KeyEventHandler(this.speed_bar_keyPress);
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
            this.dir_back.BackColor = System.Drawing.Color.LightGray;
            this.dir_back.Enabled = false;
            this.dir_back.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.dir_back.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dir_back.Location = new System.Drawing.Point(109, 259);
            this.dir_back.Name = "dir_back";
            this.dir_back.Size = new System.Drawing.Size(55, 55);
            this.dir_back.TabIndex = 3;
            this.dir_back.Text = "↓";
            this.dir_back.UseVisualStyleBackColor = false;
            // 
            // dir_front
            // 
            this.dir_front.BackColor = System.Drawing.Color.LightGray;
            this.dir_front.Enabled = false;
            this.dir_front.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.dir_front.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dir_front.Location = new System.Drawing.Point(109, 198);
            this.dir_front.Name = "dir_front";
            this.dir_front.Size = new System.Drawing.Size(55, 55);
            this.dir_front.TabIndex = 2;
            this.dir_front.Text = "↑";
            this.dir_front.UseVisualStyleBackColor = false;
            // 
            // dir_right
            // 
            this.dir_right.BackColor = System.Drawing.Color.LightGray;
            this.dir_right.Enabled = false;
            this.dir_right.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.dir_right.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dir_right.Location = new System.Drawing.Point(170, 259);
            this.dir_right.Name = "dir_right";
            this.dir_right.Size = new System.Drawing.Size(55, 55);
            this.dir_right.TabIndex = 1;
            this.dir_right.Text = "→";
            this.dir_right.UseVisualStyleBackColor = false;
            // 
            // dir_left
            // 
            this.dir_left.BackColor = System.Drawing.Color.LightGray;
            this.dir_left.Enabled = false;
            this.dir_left.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.dir_left.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dir_left.Location = new System.Drawing.Point(48, 259);
            this.dir_left.Name = "dir_left";
            this.dir_left.Size = new System.Drawing.Size(55, 55);
            this.dir_left.TabIndex = 0;
            this.dir_left.Text = "←";
            this.dir_left.UseVisualStyleBackColor = false;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.labelBattery);
            this.tabPage2.Controls.Add(this.labelPoseR);
            this.tabPage2.Controls.Add(this.labelSpeedR);
            this.tabPage2.Controls.Add(this.labelPoseL);
            this.tabPage2.Controls.Add(this.labelSpeedL);
            this.tabPage2.Controls.Add(this.pictureBox3);
            this.tabPage2.Controls.Add(this.pictureBox2);
            this.tabPage2.Controls.Add(this.label_USRB);
            this.tabPage2.Controls.Add(this.label_USRF);
            this.tabPage2.Controls.Add(this.label_USF);
            this.tabPage2.Controls.Add(this.label_USB);
            this.tabPage2.Controls.Add(this.label_USLB);
            this.tabPage2.Controls.Add(this.label_USLF);
            this.tabPage2.Controls.Add(this.picture_USFW);
            this.tabPage2.Controls.Add(this.picture_USLFW);
            this.tabPage2.Controls.Add(this.picture_USLBW);
            this.tabPage2.Controls.Add(this.picture_USRFW);
            this.tabPage2.Controls.Add(this.picture_USRBW);
            this.tabPage2.Controls.Add(this.picture_USBW);
            this.tabPage2.Controls.Add(this.picture_USLF);
            this.tabPage2.Controls.Add(this.picture_USLB);
            this.tabPage2.Controls.Add(this.picture_USF);
            this.tabPage2.Controls.Add(this.picture_USRF);
            this.tabPage2.Controls.Add(this.picture_USRB);
            this.tabPage2.Controls.Add(this.pictureUSB);
            this.tabPage2.Controls.Add(this.picture_car_sensors);
            this.tabPage2.Controls.Add(this.label_steering);
            this.tabPage2.Controls.Add(this.picture_steering);
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(663, 470);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Sensors";
            this.tabPage2.UseVisualStyleBackColor = true;
            this.tabPage2.SizeChanged += new System.EventHandler(this.tabPage2_SizeChanged);
            // 
            // labelBattery
            // 
            this.labelBattery.AutoSize = true;
            this.labelBattery.Location = new System.Drawing.Point(15, 21);
            this.labelBattery.Name = "labelBattery";
            this.labelBattery.Size = new System.Drawing.Size(32, 17);
            this.labelBattery.TabIndex = 27;
            this.labelBattery.Tag = " %";
            this.labelBattery.Text = "0 %";
            // 
            // labelPoseR
            // 
            this.labelPoseR.AutoSize = true;
            this.labelPoseR.Location = new System.Drawing.Point(503, 339);
            this.labelPoseR.Name = "labelPoseR";
            this.labelPoseR.Size = new System.Drawing.Size(38, 17);
            this.labelPoseR.TabIndex = 26;
            this.labelPoseR.Tag = " cm";
            this.labelPoseR.Text = "0 cm";
            // 
            // labelSpeedR
            // 
            this.labelSpeedR.AutoSize = true;
            this.labelSpeedR.Location = new System.Drawing.Point(503, 306);
            this.labelSpeedR.Name = "labelSpeedR";
            this.labelSpeedR.Size = new System.Drawing.Size(49, 17);
            this.labelSpeedR.TabIndex = 25;
            this.labelSpeedR.Tag = " cm/s";
            this.labelSpeedR.Text = "0 cm/s";
            // 
            // labelPoseL
            // 
            this.labelPoseL.AutoSize = true;
            this.labelPoseL.Location = new System.Drawing.Point(82, 339);
            this.labelPoseL.Name = "labelPoseL";
            this.labelPoseL.Size = new System.Drawing.Size(38, 17);
            this.labelPoseL.TabIndex = 24;
            this.labelPoseL.Tag = " cm";
            this.labelPoseL.Text = "0 cm";
            // 
            // labelSpeedL
            // 
            this.labelSpeedL.AutoSize = true;
            this.labelSpeedL.Location = new System.Drawing.Point(82, 306);
            this.labelSpeedL.Name = "labelSpeedL";
            this.labelSpeedL.Size = new System.Drawing.Size(49, 17);
            this.labelSpeedL.TabIndex = 23;
            this.labelSpeedL.Tag = " cm/s";
            this.labelSpeedL.Text = "0 cm/s";
            // 
            // pictureBox3
            // 
            this.pictureBox3.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox3.Image")));
            this.pictureBox3.Location = new System.Drawing.Point(506, 235);
            this.pictureBox3.Name = "pictureBox3";
            this.pictureBox3.Size = new System.Drawing.Size(65, 65);
            this.pictureBox3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox3.TabIndex = 22;
            this.pictureBox3.TabStop = false;
            // 
            // pictureBox2
            // 
            this.pictureBox2.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox2.Image")));
            this.pictureBox2.Location = new System.Drawing.Point(85, 235);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(65, 65);
            this.pictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox2.TabIndex = 21;
            this.pictureBox2.TabStop = false;
            // 
            // label_USRB
            // 
            this.label_USRB.AutoSize = true;
            this.label_USRB.Location = new System.Drawing.Point(390, 259);
            this.label_USRB.Name = "label_USRB";
            this.label_USRB.Size = new System.Drawing.Size(23, 17);
            this.label_USRB.TabIndex = 20;
            this.label_USRB.Text = "inf";
            // 
            // label_USRF
            // 
            this.label_USRF.AutoSize = true;
            this.label_USRF.Location = new System.Drawing.Point(390, 119);
            this.label_USRF.Name = "label_USRF";
            this.label_USRF.Size = new System.Drawing.Size(23, 17);
            this.label_USRF.TabIndex = 19;
            this.label_USRF.Text = "inf";
            // 
            // label_USF
            // 
            this.label_USF.AutoSize = true;
            this.label_USF.Location = new System.Drawing.Point(267, 99);
            this.label_USF.Name = "label_USF";
            this.label_USF.Size = new System.Drawing.Size(23, 17);
            this.label_USF.TabIndex = 18;
            this.label_USF.Text = "inf";
            // 
            // label_USB
            // 
            this.label_USB.AutoSize = true;
            this.label_USB.Location = new System.Drawing.Point(336, 99);
            this.label_USB.Name = "label_USB";
            this.label_USB.Size = new System.Drawing.Size(23, 17);
            this.label_USB.TabIndex = 17;
            this.label_USB.Text = "inf";
            // 
            // label_USLB
            // 
            this.label_USLB.AutoSize = true;
            this.label_USLB.Location = new System.Drawing.Point(219, 259);
            this.label_USLB.Name = "label_USLB";
            this.label_USLB.Size = new System.Drawing.Size(23, 17);
            this.label_USLB.TabIndex = 16;
            this.label_USLB.Text = "inf";
            // 
            // label_USLF
            // 
            this.label_USLF.AutoSize = true;
            this.label_USLF.Location = new System.Drawing.Point(209, 123);
            this.label_USLF.Name = "label_USLF";
            this.label_USLF.Size = new System.Drawing.Size(23, 17);
            this.label_USLF.TabIndex = 15;
            this.label_USLF.Text = "inf";
            // 
            // picture_USFW
            // 
            this.picture_USFW.Image = ((System.Drawing.Image)(resources.GetObject("picture_USFW.Image")));
            this.picture_USFW.Location = new System.Drawing.Point(272, 119);
            this.picture_USFW.Name = "picture_USFW";
            this.picture_USFW.Size = new System.Drawing.Size(54, 50);
            this.picture_USFW.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picture_USFW.TabIndex = 14;
            this.picture_USFW.TabStop = false;
            this.picture_USFW.Visible = false;
            // 
            // picture_USLFW
            // 
            this.picture_USLFW.Image = ((System.Drawing.Image)(resources.GetObject("picture_USLFW.Image")));
            this.picture_USLFW.Location = new System.Drawing.Point(222, 143);
            this.picture_USLFW.Name = "picture_USLFW";
            this.picture_USLFW.Size = new System.Drawing.Size(54, 50);
            this.picture_USLFW.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picture_USLFW.TabIndex = 13;
            this.picture_USLFW.TabStop = false;
            this.picture_USLFW.Visible = false;
            // 
            // picture_USLBW
            // 
            this.picture_USLBW.Image = ((System.Drawing.Image)(resources.GetObject("picture_USLBW.Image")));
            this.picture_USLBW.Location = new System.Drawing.Point(222, 206);
            this.picture_USLBW.Name = "picture_USLBW";
            this.picture_USLBW.Size = new System.Drawing.Size(54, 50);
            this.picture_USLBW.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picture_USLBW.TabIndex = 12;
            this.picture_USLBW.TabStop = false;
            this.picture_USLBW.Visible = false;
            // 
            // picture_USRFW
            // 
            this.picture_USRFW.Image = ((System.Drawing.Image)(resources.GetObject("picture_USRFW.Image")));
            this.picture_USRFW.Location = new System.Drawing.Point(377, 139);
            this.picture_USRFW.Name = "picture_USRFW";
            this.picture_USRFW.Size = new System.Drawing.Size(54, 50);
            this.picture_USRFW.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picture_USRFW.TabIndex = 11;
            this.picture_USRFW.TabStop = false;
            this.picture_USRFW.Visible = false;
            // 
            // picture_USRBW
            // 
            this.picture_USRBW.Image = ((System.Drawing.Image)(resources.GetObject("picture_USRBW.Image")));
            this.picture_USRBW.Location = new System.Drawing.Point(377, 206);
            this.picture_USRBW.Name = "picture_USRBW";
            this.picture_USRBW.Size = new System.Drawing.Size(54, 50);
            this.picture_USRBW.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picture_USRBW.TabIndex = 10;
            this.picture_USRBW.TabStop = false;
            this.picture_USRBW.Visible = false;
            // 
            // picture_USBW
            // 
            this.picture_USBW.Image = ((System.Drawing.Image)(resources.GetObject("picture_USBW.Image")));
            this.picture_USBW.Location = new System.Drawing.Point(330, 119);
            this.picture_USBW.Name = "picture_USBW";
            this.picture_USBW.Size = new System.Drawing.Size(54, 50);
            this.picture_USBW.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picture_USBW.TabIndex = 9;
            this.picture_USBW.TabStop = false;
            this.picture_USBW.Visible = false;
            // 
            // picture_USLF
            // 
            this.picture_USLF.Image = ((System.Drawing.Image)(resources.GetObject("picture_USLF.Image")));
            this.picture_USLF.Location = new System.Drawing.Point(222, 143);
            this.picture_USLF.Name = "picture_USLF";
            this.picture_USLF.Size = new System.Drawing.Size(54, 50);
            this.picture_USLF.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picture_USLF.TabIndex = 8;
            this.picture_USLF.TabStop = false;
            // 
            // picture_USLB
            // 
            this.picture_USLB.Image = ((System.Drawing.Image)(resources.GetObject("picture_USLB.Image")));
            this.picture_USLB.Location = new System.Drawing.Point(222, 206);
            this.picture_USLB.Name = "picture_USLB";
            this.picture_USLB.Size = new System.Drawing.Size(54, 50);
            this.picture_USLB.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picture_USLB.TabIndex = 7;
            this.picture_USLB.TabStop = false;
            // 
            // picture_USF
            // 
            this.picture_USF.Image = ((System.Drawing.Image)(resources.GetObject("picture_USF.Image")));
            this.picture_USF.Location = new System.Drawing.Point(272, 119);
            this.picture_USF.Name = "picture_USF";
            this.picture_USF.Size = new System.Drawing.Size(54, 50);
            this.picture_USF.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picture_USF.TabIndex = 6;
            this.picture_USF.TabStop = false;
            // 
            // picture_USRF
            // 
            this.picture_USRF.Image = ((System.Drawing.Image)(resources.GetObject("picture_USRF.Image")));
            this.picture_USRF.Location = new System.Drawing.Point(377, 139);
            this.picture_USRF.Name = "picture_USRF";
            this.picture_USRF.Size = new System.Drawing.Size(54, 50);
            this.picture_USRF.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picture_USRF.TabIndex = 5;
            this.picture_USRF.TabStop = false;
            // 
            // picture_USRB
            // 
            this.picture_USRB.Image = ((System.Drawing.Image)(resources.GetObject("picture_USRB.Image")));
            this.picture_USRB.Location = new System.Drawing.Point(377, 206);
            this.picture_USRB.Name = "picture_USRB";
            this.picture_USRB.Size = new System.Drawing.Size(54, 50);
            this.picture_USRB.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picture_USRB.TabIndex = 4;
            this.picture_USRB.TabStop = false;
            // 
            // pictureUSB
            // 
            this.pictureUSB.Image = ((System.Drawing.Image)(resources.GetObject("pictureUSB.Image")));
            this.pictureUSB.Location = new System.Drawing.Point(330, 119);
            this.pictureUSB.Name = "pictureUSB";
            this.pictureUSB.Size = new System.Drawing.Size(54, 50);
            this.pictureUSB.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureUSB.TabIndex = 3;
            this.pictureUSB.TabStop = false;
            // 
            // picture_car_sensors
            // 
            this.picture_car_sensors.Image = ((System.Drawing.Image)(resources.GetObject("picture_car_sensors.Image")));
            this.picture_car_sensors.Location = new System.Drawing.Point(263, 166);
            this.picture_car_sensors.Name = "picture_car_sensors";
            this.picture_car_sensors.Size = new System.Drawing.Size(130, 203);
            this.picture_car_sensors.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picture_car_sensors.TabIndex = 2;
            this.picture_car_sensors.TabStop = false;
            // 
            // label_steering
            // 
            this.label_steering.AutoSize = true;
            this.label_steering.Location = new System.Drawing.Point(471, 114);
            this.label_steering.Name = "label_steering";
            this.label_steering.Size = new System.Drawing.Size(16, 17);
            this.label_steering.TabIndex = 1;
            this.label_steering.Text = "0";
            // 
            // picture_steering
            // 
            this.picture_steering.Image = ((System.Drawing.Image)(resources.GetObject("picture_steering.Image")));
            this.picture_steering.Location = new System.Drawing.Point(474, 14);
            this.picture_steering.Name = "picture_steering";
            this.picture_steering.Size = new System.Drawing.Size(119, 97);
            this.picture_steering.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picture_steering.TabIndex = 0;
            this.picture_steering.TabStop = false;
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.checkBox_error);
            this.tabPage3.Controls.Add(this.checkBox_warning);
            this.tabPage3.Controls.Add(this.checkBox_cmd);
            this.tabPage3.Controls.Add(this.checkBox_dbg);
            this.tabPage3.Controls.Add(this.checkBox_SEND);
            this.tabPage3.Controls.Add(this.clearLogButton);
            this.tabPage3.Controls.Add(this.saveLogButton);
            this.tabPage3.Controls.Add(this.logTextBox);
            this.tabPage3.Location = new System.Drawing.Point(4, 25);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Size = new System.Drawing.Size(663, 470);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Debug";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // checkBox_error
            // 
            this.checkBox_error.AutoSize = true;
            this.checkBox_error.Checked = true;
            this.checkBox_error.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox_error.ForeColor = System.Drawing.Color.Red;
            this.checkBox_error.Location = new System.Drawing.Point(412, 4);
            this.checkBox_error.Name = "checkBox_error";
            this.checkBox_error.Size = new System.Drawing.Size(80, 21);
            this.checkBox_error.TabIndex = 7;
            this.checkBox_error.Text = "ERROR";
            this.checkBox_error.UseVisualStyleBackColor = true;
            // 
            // checkBox_warning
            // 
            this.checkBox_warning.AutoSize = true;
            this.checkBox_warning.Checked = true;
            this.checkBox_warning.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox_warning.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
            this.checkBox_warning.Location = new System.Drawing.Point(310, 4);
            this.checkBox_warning.Name = "checkBox_warning";
            this.checkBox_warning.Size = new System.Drawing.Size(96, 21);
            this.checkBox_warning.TabIndex = 6;
            this.checkBox_warning.Text = "WARNING";
            this.checkBox_warning.UseVisualStyleBackColor = true;
            // 
            // checkBox_cmd
            // 
            this.checkBox_cmd.AutoSize = true;
            this.checkBox_cmd.Checked = true;
            this.checkBox_cmd.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox_cmd.ForeColor = System.Drawing.Color.Lime;
            this.checkBox_cmd.Location = new System.Drawing.Point(244, 4);
            this.checkBox_cmd.Name = "checkBox_cmd";
            this.checkBox_cmd.Size = new System.Drawing.Size(60, 21);
            this.checkBox_cmd.TabIndex = 5;
            this.checkBox_cmd.Text = "CMD";
            this.checkBox_cmd.UseVisualStyleBackColor = true;
            // 
            // checkBox_dbg
            // 
            this.checkBox_dbg.AutoSize = true;
            this.checkBox_dbg.Checked = true;
            this.checkBox_dbg.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox_dbg.ForeColor = System.Drawing.Color.Blue;
            this.checkBox_dbg.Location = new System.Drawing.Point(159, 4);
            this.checkBox_dbg.Name = "checkBox_dbg";
            this.checkBox_dbg.Size = new System.Drawing.Size(79, 21);
            this.checkBox_dbg.TabIndex = 4;
            this.checkBox_dbg.Text = "DEBUG";
            this.checkBox_dbg.UseVisualStyleBackColor = true;
            // 
            // checkBox_SEND
            // 
            this.checkBox_SEND.AutoSize = true;
            this.checkBox_SEND.Checked = true;
            this.checkBox_SEND.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox_SEND.ForeColor = System.Drawing.Color.Blue;
            this.checkBox_SEND.Location = new System.Drawing.Point(85, 4);
            this.checkBox_SEND.Name = "checkBox_SEND";
            this.checkBox_SEND.Size = new System.Drawing.Size(68, 21);
            this.checkBox_SEND.TabIndex = 3;
            this.checkBox_SEND.Text = "SEND";
            this.checkBox_SEND.UseVisualStyleBackColor = true;
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
            this.logTextBox.Enabled = false;
            this.logTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.logTextBox.HideSelection = false;
            this.logTextBox.Location = new System.Drawing.Point(4, 50);
            this.logTextBox.Name = "logTextBox";
            this.logTextBox.ReadOnly = true;
            this.logTextBox.ShortcutsEnabled = false;
            this.logTextBox.Size = new System.Drawing.Size(659, 350);
            this.logTextBox.TabIndex = 0;
            this.logTextBox.Text = "";
            this.logTextBox.VisibleChanged += new System.EventHandler(this.logVisibleChange);
            // 
            // tabPage4
            // 
            this.tabPage4.Controls.Add(this.ActState18);
            this.tabPage4.Controls.Add(this.ActState13);
            this.tabPage4.Controls.Add(this.ActState11);
            this.tabPage4.Controls.Add(this.ActState6);
            this.tabPage4.Controls.Add(this.ActState17);
            this.tabPage4.Controls.Add(this.ActState15);
            this.tabPage4.Controls.Add(this.ActState10);
            this.tabPage4.Controls.Add(this.ActState9);
            this.tabPage4.Controls.Add(this.ActState4);
            this.tabPage4.Controls.Add(this.ActState12);
            this.tabPage4.Controls.Add(this.ActState8);
            this.tabPage4.Controls.Add(this.ActState16);
            this.tabPage4.Controls.Add(this.ActState14);
            this.tabPage4.Controls.Add(this.ActState7);
            this.tabPage4.Controls.Add(this.ActState5);
            this.tabPage4.Controls.Add(this.ActState2);
            this.tabPage4.Controls.Add(this.ActState3);
            this.tabPage4.Controls.Add(this.ActState1);
            this.tabPage4.Controls.Add(this.ActState0);
            this.tabPage4.Controls.Add(this.pictureBox10);
            this.tabPage4.Location = new System.Drawing.Point(4, 25);
            this.tabPage4.Name = "tabPage4";
            this.tabPage4.Size = new System.Drawing.Size(663, 470);
            this.tabPage4.TabIndex = 3;
            this.tabPage4.Text = "Graph";
            this.tabPage4.UseVisualStyleBackColor = true;
            // 
            // ActState18
            // 
            this.ActState18.Image = ((System.Drawing.Image)(resources.GetObject("ActState18.Image")));
            this.ActState18.Location = new System.Drawing.Point(166, 427);
            this.ActState18.Name = "ActState18";
            this.ActState18.Size = new System.Drawing.Size(24, 23);
            this.ActState18.TabIndex = 47;
            this.ActState18.TabStop = false;
            this.ActState18.Visible = false;
            // 
            // ActState13
            // 
            this.ActState13.Image = ((System.Drawing.Image)(resources.GetObject("ActState13.Image")));
            this.ActState13.Location = new System.Drawing.Point(208, 328);
            this.ActState13.Name = "ActState13";
            this.ActState13.Size = new System.Drawing.Size(23, 23);
            this.ActState13.TabIndex = 46;
            this.ActState13.TabStop = false;
            this.ActState13.Visible = false;
            // 
            // ActState11
            // 
            this.ActState11.Image = ((System.Drawing.Image)(resources.GetObject("ActState11.Image")));
            this.ActState11.Location = new System.Drawing.Point(249, 279);
            this.ActState11.Name = "ActState11";
            this.ActState11.Size = new System.Drawing.Size(24, 23);
            this.ActState11.TabIndex = 45;
            this.ActState11.TabStop = false;
            this.ActState11.Visible = false;
            // 
            // ActState6
            // 
            this.ActState6.Image = ((System.Drawing.Image)(resources.GetObject("ActState6.Image")));
            this.ActState6.Location = new System.Drawing.Point(287, 135);
            this.ActState6.Name = "ActState6";
            this.ActState6.Size = new System.Drawing.Size(23, 23);
            this.ActState6.TabIndex = 44;
            this.ActState6.TabStop = false;
            this.ActState6.Visible = false;
            // 
            // ActState17
            // 
            this.ActState17.Image = ((System.Drawing.Image)(resources.GetObject("ActState17.Image")));
            this.ActState17.Location = new System.Drawing.Point(103, 427);
            this.ActState17.Name = "ActState17";
            this.ActState17.Size = new System.Drawing.Size(23, 23);
            this.ActState17.TabIndex = 43;
            this.ActState17.TabStop = false;
            this.ActState17.Visible = false;
            // 
            // ActState15
            // 
            this.ActState15.Image = ((System.Drawing.Image)(resources.GetObject("ActState15.Image")));
            this.ActState15.Location = new System.Drawing.Point(144, 378);
            this.ActState15.Name = "ActState15";
            this.ActState15.Size = new System.Drawing.Size(24, 23);
            this.ActState15.TabIndex = 42;
            this.ActState15.TabStop = false;
            this.ActState15.Visible = false;
            // 
            // ActState10
            // 
            this.ActState10.Image = ((System.Drawing.Image)(resources.GetObject("ActState10.Image")));
            this.ActState10.Location = new System.Drawing.Point(175, 279);
            this.ActState10.Name = "ActState10";
            this.ActState10.Size = new System.Drawing.Size(23, 23);
            this.ActState10.TabIndex = 41;
            this.ActState10.TabStop = false;
            this.ActState10.Visible = false;
            // 
            // ActState9
            // 
            this.ActState9.Image = ((System.Drawing.Image)(resources.GetObject("ActState9.Image")));
            this.ActState9.Location = new System.Drawing.Point(216, 228);
            this.ActState9.Name = "ActState9";
            this.ActState9.Size = new System.Drawing.Size(24, 23);
            this.ActState9.TabIndex = 40;
            this.ActState9.TabStop = false;
            this.ActState9.Visible = false;
            // 
            // ActState4
            // 
            this.ActState4.Image = ((System.Drawing.Image)(resources.GetObject("ActState4.Image")));
            this.ActState4.Location = new System.Drawing.Point(221, 90);
            this.ActState4.Name = "ActState4";
            this.ActState4.Size = new System.Drawing.Size(23, 23);
            this.ActState4.TabIndex = 39;
            this.ActState4.TabStop = false;
            this.ActState4.Visible = false;
            // 
            // ActState12
            // 
            this.ActState12.Image = ((System.Drawing.Image)(resources.GetObject("ActState12.Image")));
            this.ActState12.Location = new System.Drawing.Point(132, 329);
            this.ActState12.Name = "ActState12";
            this.ActState12.Size = new System.Drawing.Size(23, 23);
            this.ActState12.TabIndex = 38;
            this.ActState12.TabStop = false;
            this.ActState12.Visible = false;
            // 
            // ActState8
            // 
            this.ActState8.Image = ((System.Drawing.Image)(resources.GetObject("ActState8.Image")));
            this.ActState8.Location = new System.Drawing.Point(148, 178);
            this.ActState8.Name = "ActState8";
            this.ActState8.Size = new System.Drawing.Size(23, 23);
            this.ActState8.TabIndex = 37;
            this.ActState8.TabStop = false;
            this.ActState8.Visible = false;
            // 
            // ActState16
            // 
            this.ActState16.Image = ((System.Drawing.Image)(resources.GetObject("ActState16.Image")));
            this.ActState16.Location = new System.Drawing.Point(40, 444);
            this.ActState16.Name = "ActState16";
            this.ActState16.Size = new System.Drawing.Size(24, 23);
            this.ActState16.TabIndex = 36;
            this.ActState16.TabStop = false;
            this.ActState16.Visible = false;
            // 
            // ActState14
            // 
            this.ActState14.Image = ((System.Drawing.Image)(resources.GetObject("ActState14.Image")));
            this.ActState14.Location = new System.Drawing.Point(40, 378);
            this.ActState14.Name = "ActState14";
            this.ActState14.Size = new System.Drawing.Size(24, 23);
            this.ActState14.TabIndex = 35;
            this.ActState14.TabStop = false;
            this.ActState14.Visible = false;
            // 
            // ActState7
            // 
            this.ActState7.Image = ((System.Drawing.Image)(resources.GetObject("ActState7.Image")));
            this.ActState7.Location = new System.Drawing.Point(40, 178);
            this.ActState7.Name = "ActState7";
            this.ActState7.Size = new System.Drawing.Size(24, 23);
            this.ActState7.TabIndex = 34;
            this.ActState7.TabStop = false;
            this.ActState7.Visible = false;
            // 
            // ActState5
            // 
            this.ActState5.Image = ((System.Drawing.Image)(resources.GetObject("ActState5.Image")));
            this.ActState5.Location = new System.Drawing.Point(108, 134);
            this.ActState5.Name = "ActState5";
            this.ActState5.Size = new System.Drawing.Size(24, 23);
            this.ActState5.TabIndex = 33;
            this.ActState5.TabStop = false;
            this.ActState5.Visible = false;
            // 
            // ActState2
            // 
            this.ActState2.Image = ((System.Drawing.Image)(resources.GetObject("ActState2.Image")));
            this.ActState2.Location = new System.Drawing.Point(40, 90);
            this.ActState2.Name = "ActState2";
            this.ActState2.Size = new System.Drawing.Size(24, 23);
            this.ActState2.TabIndex = 32;
            this.ActState2.TabStop = false;
            this.ActState2.Visible = false;
            // 
            // ActState3
            // 
            this.ActState3.Image = ((System.Drawing.Image)(resources.GetObject("ActState3.Image")));
            this.ActState3.Location = new System.Drawing.Point(131, 91);
            this.ActState3.Name = "ActState3";
            this.ActState3.Size = new System.Drawing.Size(23, 23);
            this.ActState3.TabIndex = 31;
            this.ActState3.TabStop = false;
            this.ActState3.Visible = false;
            // 
            // ActState1
            // 
            this.ActState1.Image = ((System.Drawing.Image)(resources.GetObject("ActState1.Image")));
            this.ActState1.Location = new System.Drawing.Point(131, 47);
            this.ActState1.Name = "ActState1";
            this.ActState1.Size = new System.Drawing.Size(24, 23);
            this.ActState1.TabIndex = 30;
            this.ActState1.TabStop = false;
            this.ActState1.Visible = false;
            // 
            // ActState0
            // 
            this.ActState0.Image = ((System.Drawing.Image)(resources.GetObject("ActState0.Image")));
            this.ActState0.Location = new System.Drawing.Point(131, 3);
            this.ActState0.Name = "ActState0";
            this.ActState0.Size = new System.Drawing.Size(23, 23);
            this.ActState0.TabIndex = 29;
            this.ActState0.TabStop = false;
            this.ActState0.Visible = false;
            // 
            // pictureBox10
            // 
            this.pictureBox10.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox10.Image")));
            this.pictureBox10.Location = new System.Drawing.Point(12, 3);
            this.pictureBox10.Name = "pictureBox10";
            this.pictureBox10.Size = new System.Drawing.Size(328, 467);
            this.pictureBox10.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox10.TabIndex = 28;
            this.pictureBox10.TabStop = false;
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
            // Battery10
            // 
            this.Battery10.Image = ((System.Drawing.Image)(resources.GetObject("Battery10.Image")));
            this.Battery10.Location = new System.Drawing.Point(25, 59);
            this.Battery10.Name = "Battery10";
            this.Battery10.Size = new System.Drawing.Size(85, 50);
            this.Battery10.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.Battery10.TabIndex = 28;
            this.Battery10.TabStop = false;
            // 
            // Battery30
            // 
            this.Battery30.Image = ((System.Drawing.Image)(resources.GetObject("Battery30.Image")));
            this.Battery30.Location = new System.Drawing.Point(25, 59);
            this.Battery30.Name = "Battery30";
            this.Battery30.Size = new System.Drawing.Size(85, 50);
            this.Battery30.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.Battery30.TabIndex = 29;
            this.Battery30.TabStop = false;
            // 
            // Battery50
            // 
            this.Battery50.Image = ((System.Drawing.Image)(resources.GetObject("Battery50.Image")));
            this.Battery50.Location = new System.Drawing.Point(25, 59);
            this.Battery50.Name = "Battery50";
            this.Battery50.Size = new System.Drawing.Size(85, 50);
            this.Battery50.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.Battery50.TabIndex = 29;
            this.Battery50.TabStop = false;
            // 
            // Battery70
            // 
            this.Battery70.Image = ((System.Drawing.Image)(resources.GetObject("Battery70.Image")));
            this.Battery70.Location = new System.Drawing.Point(25, 59);
            this.Battery70.Name = "Battery70";
            this.Battery70.Size = new System.Drawing.Size(85, 50);
            this.Battery70.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.Battery70.TabIndex = 30;
            this.Battery70.TabStop = false;
            // 
            // Battery100
            // 
            this.Battery100.Image = ((System.Drawing.Image)(resources.GetObject("Battery100.Image")));
            this.Battery100.Location = new System.Drawing.Point(25, 59);
            this.Battery100.Name = "Battery100";
            this.Battery100.Size = new System.Drawing.Size(85, 50);
            this.Battery100.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.Battery100.TabIndex = 29;
            this.Battery100.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(819, 616);
            this.Controls.Add(this.Battery100);
            this.Controls.Add(this.Battery70);
            this.Controls.Add(this.Battery50);
            this.Controls.Add(this.Battery30);
            this.Controls.Add(this.Battery10);
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.tab_control);
            this.Controls.Add(this.debug_text);
            this.Controls.Add(this.send_text_button);
            this.Controls.Add(this.textBox2);
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
            this.tabPage1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.arrowLeft)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ulysse5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ulysse4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ulysse3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ulysse2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ulysse1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_speed_limit)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_car_too_near)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_car_near)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_car_detected)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_no_car)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.speed_bar)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USFW)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USLFW)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USLBW)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USRFW)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USRBW)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USBW)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USLF)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USLB)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USF)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USRF)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_USRB)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureUSB)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_car_sensors)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picture_steering)).EndInit();
            this.tabPage3.ResumeLayout(false);
            this.tabPage3.PerformLayout();
            this.tabPage4.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.ActState18)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState13)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState11)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState6)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState17)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState15)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState10)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState9)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState12)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState8)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState16)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState14)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState7)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ActState0)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox10)).EndInit();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.Battery10)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Battery30)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Battery50)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Battery70)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Battery100)).EndInit();
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
                try
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
                catch(Exception e)
                {

                }
                System.Threading.Thread.Sleep(500);
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
        private System.Windows.Forms.TrackBar speed_bar;
        private System.Windows.Forms.Label speed_label;
        private System.Windows.Forms.CheckBox checkBox_error;
        private System.Windows.Forms.CheckBox checkBox_warning;
        private System.Windows.Forms.CheckBox checkBox_cmd;
        private System.Windows.Forms.CheckBox checkBox_dbg;
        private System.Windows.Forms.CheckBox checkBox_SEND;
        private System.Windows.Forms.PictureBox picture_car_sensors;
        private System.Windows.Forms.Label label_steering;
        private System.Windows.Forms.PictureBox picture_steering;
        private System.Windows.Forms.PictureBox picture_USLF;
        private System.Windows.Forms.PictureBox picture_USLB;
        private System.Windows.Forms.PictureBox picture_USF;
        private System.Windows.Forms.PictureBox picture_USRF;
        private System.Windows.Forms.PictureBox picture_USRB;
        private System.Windows.Forms.PictureBox pictureUSB;
        private System.Windows.Forms.PictureBox picture_USBW;
        private System.Windows.Forms.PictureBox picture_USFW;
        private System.Windows.Forms.PictureBox picture_USLFW;
        private System.Windows.Forms.PictureBox picture_USLBW;
        private System.Windows.Forms.PictureBox picture_USRFW;
        private System.Windows.Forms.PictureBox picture_USRBW;
        private System.Windows.Forms.Label label_USRB;
        private System.Windows.Forms.Label label_USRF;
        private System.Windows.Forms.Label label_USF;
        private System.Windows.Forms.Label label_USB;
        private System.Windows.Forms.Label label_USLB;
        private System.Windows.Forms.Label label_USLF;
        private System.Windows.Forms.Label labelPoseR;
        private System.Windows.Forms.Label labelSpeedR;
        private System.Windows.Forms.Label labelPoseL;
        private System.Windows.Forms.Label labelSpeedL;
        private System.Windows.Forms.PictureBox pictureBox3;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.Label labelBattery;
        private System.Windows.Forms.PictureBox Battery10;
        private System.Windows.Forms.PictureBox Battery30;
        private System.Windows.Forms.PictureBox Battery50;
        private System.Windows.Forms.PictureBox Battery70;
        private System.Windows.Forms.PictureBox Battery100;
        private System.Windows.Forms.PictureBox picture_no_car;
        private System.Windows.Forms.PictureBox pictureBox5;
        private System.Windows.Forms.PictureBox picture_car_detected;
        private System.Windows.Forms.PictureBox picture_car_too_near;
        private System.Windows.Forms.PictureBox picture_car_near;
        private System.Windows.Forms.PictureBox picture_speed_limit;
        private System.Windows.Forms.TabPage tabPage4;
        private System.Windows.Forms.PictureBox pictureBox10;
        private System.Windows.Forms.PictureBox ActState0;
        private System.Windows.Forms.PictureBox ActState5;
        private System.Windows.Forms.PictureBox ActState2;
        private System.Windows.Forms.PictureBox ActState3;
        private System.Windows.Forms.PictureBox ActState1;
        private System.Windows.Forms.PictureBox ActState7;
        private System.Windows.Forms.PictureBox ActState16;
        private System.Windows.Forms.PictureBox ActState14;
        private System.Windows.Forms.PictureBox ActState12;
        private System.Windows.Forms.PictureBox ActState8;
        private System.Windows.Forms.PictureBox ActState17;
        private System.Windows.Forms.PictureBox ActState15;
        private System.Windows.Forms.PictureBox ActState10;
        private System.Windows.Forms.PictureBox ActState9;
        private System.Windows.Forms.PictureBox ActState4;
        private System.Windows.Forms.PictureBox ActState6;
        private System.Windows.Forms.PictureBox ActState18;
        private System.Windows.Forms.PictureBox ActState13;
        private System.Windows.Forms.PictureBox ActState11;
        private System.Windows.Forms.PictureBox ulysse5;
        private System.Windows.Forms.PictureBox ulysse4;
        private System.Windows.Forms.PictureBox ulysse3;
        private System.Windows.Forms.PictureBox ulysse2;
        private System.Windows.Forms.PictureBox ulysse1;
        private System.Windows.Forms.PictureBox arrowLeft;
    }
}

