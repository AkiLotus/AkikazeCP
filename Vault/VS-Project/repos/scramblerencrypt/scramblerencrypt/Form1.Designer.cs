namespace scramblerencrypt
{
    partial class mainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.introLabel = new System.Windows.Forms.Label();
            this.openDialog = new System.Windows.Forms.OpenFileDialog();
            this.saveDialog = new System.Windows.Forms.SaveFileDialog();
            this.openButton = new System.Windows.Forms.Button();
            this.encryptButton = new System.Windows.Forms.Button();
            this.fnLabel = new System.Windows.Forms.Label();
            this.fnBox = new System.Windows.Forms.TextBox();
            this.keyLabel = new System.Windows.Forms.Label();
            this.keyBox = new System.Windows.Forms.TextBox();
            this.sysLabel = new System.Windows.Forms.Label();
            this.sysAnnounce = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // introLabel
            // 
            this.introLabel.AutoSize = true;
            this.introLabel.Location = new System.Drawing.Point(41, 21);
            this.introLabel.Name = "introLabel";
            this.introLabel.Size = new System.Drawing.Size(355, 13);
            this.introLabel.TabIndex = 0;
            this.introLabel.Text = "Works with Latin letters and spaces only. Other characters will be ignored.";
            // 
            // openDialog
            // 
            this.openDialog.DefaultExt = "txt";
            this.openDialog.Filter = "Text files|*.txt";
            this.openDialog.Title = "Open file....";
            this.openDialog.FileOk += new System.ComponentModel.CancelEventHandler(this.openDialog_FileOk);
            // 
            // saveDialog
            // 
            this.saveDialog.DefaultExt = "txt";
            this.saveDialog.Filter = "\"Text files|*.txt\"";
            this.saveDialog.Title = "Save file as....";
            this.saveDialog.FileOk += new System.ComponentModel.CancelEventHandler(this.saveDialog_FileOk);
            // 
            // openButton
            // 
            this.openButton.Location = new System.Drawing.Point(95, 53);
            this.openButton.Name = "openButton";
            this.openButton.Size = new System.Drawing.Size(75, 23);
            this.openButton.TabIndex = 1;
            this.openButton.Text = "OPEN";
            this.openButton.UseVisualStyleBackColor = true;
            this.openButton.Click += new System.EventHandler(this.openButton_Click);
            // 
            // encryptButton
            // 
            this.encryptButton.Location = new System.Drawing.Point(251, 53);
            this.encryptButton.Name = "encryptButton";
            this.encryptButton.Size = new System.Drawing.Size(75, 23);
            this.encryptButton.TabIndex = 2;
            this.encryptButton.Text = "ENCRYPT!";
            this.encryptButton.UseVisualStyleBackColor = true;
            this.encryptButton.Click += new System.EventHandler(this.encryptButton_Click);
            // 
            // fnLabel
            // 
            this.fnLabel.AutoSize = true;
            this.fnLabel.Location = new System.Drawing.Point(12, 130);
            this.fnLabel.Name = "fnLabel";
            this.fnLabel.Size = new System.Drawing.Size(55, 13);
            this.fnLabel.TabIndex = 3;
            this.fnLabel.Text = "File name:";
            // 
            // fnBox
            // 
            this.fnBox.Location = new System.Drawing.Point(73, 127);
            this.fnBox.Name = "fnBox";
            this.fnBox.ReadOnly = true;
            this.fnBox.Size = new System.Drawing.Size(338, 20);
            this.fnBox.TabIndex = 4;
            // 
            // keyLabel
            // 
            this.keyLabel.AutoSize = true;
            this.keyLabel.Location = new System.Drawing.Point(12, 99);
            this.keyLabel.Name = "keyLabel";
            this.keyLabel.Size = new System.Drawing.Size(28, 13);
            this.keyLabel.TabIndex = 5;
            this.keyLabel.Text = "Key:";
            // 
            // keyBox
            // 
            this.keyBox.Location = new System.Drawing.Point(73, 96);
            this.keyBox.Name = "keyBox";
            this.keyBox.Size = new System.Drawing.Size(100, 20);
            this.keyBox.TabIndex = 6;
            // 
            // sysLabel
            // 
            this.sysLabel.AutoSize = true;
            this.sysLabel.Location = new System.Drawing.Point(188, 99);
            this.sysLabel.Name = "sysLabel";
            this.sysLabel.Size = new System.Drawing.Size(44, 13);
            this.sysLabel.TabIndex = 7;
            this.sysLabel.Text = "System:";
            // 
            // sysAnnounce
            // 
            this.sysAnnounce.Location = new System.Drawing.Point(238, 96);
            this.sysAnnounce.Name = "sysAnnounce";
            this.sysAnnounce.ReadOnly = true;
            this.sysAnnounce.Size = new System.Drawing.Size(173, 20);
            this.sysAnnounce.TabIndex = 8;
            // 
            // mainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(423, 161);
            this.Controls.Add(this.sysAnnounce);
            this.Controls.Add(this.sysLabel);
            this.Controls.Add(this.keyBox);
            this.Controls.Add(this.keyLabel);
            this.Controls.Add(this.fnBox);
            this.Controls.Add(this.fnLabel);
            this.Controls.Add(this.encryptButton);
            this.Controls.Add(this.openButton);
            this.Controls.Add(this.introLabel);
            this.MaximizeBox = false;
            this.Name = "mainForm";
            this.Text = "Scrambler Encryptor - Powered by #Team4T";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label introLabel;
        private System.Windows.Forms.OpenFileDialog openDialog;
        private System.Windows.Forms.SaveFileDialog saveDialog;
        private System.Windows.Forms.Button openButton;
        private System.Windows.Forms.Button encryptButton;
        private System.Windows.Forms.Label fnLabel;
        private System.Windows.Forms.TextBox fnBox;
        private System.Windows.Forms.Label keyLabel;
        private System.Windows.Forms.TextBox keyBox;
        private System.Windows.Forms.Label sysLabel;
        private System.Windows.Forms.TextBox sysAnnounce;
    }
}

