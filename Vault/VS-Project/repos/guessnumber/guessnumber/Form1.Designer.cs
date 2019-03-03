namespace guessnumber
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(mainForm));
            this.introButton = new System.Windows.Forms.Button();
            this.scoreLabel = new System.Windows.Forms.Label();
            this.scoreBox = new System.Windows.Forms.TextBox();
            this.ansPrompt = new System.Windows.Forms.Label();
            this.ansBox = new System.Windows.Forms.TextBox();
            this.verdictLabel = new System.Windows.Forms.Label();
            this.verdictBox = new System.Windows.Forms.TextBox();
            this.timeLabel = new System.Windows.Forms.Label();
            this.gameTimer = new System.Windows.Forms.Timer(this.components);
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.startButton = new System.Windows.Forms.Button();
            this.minLabel = new System.Windows.Forms.Label();
            this.maxLabel = new System.Windows.Forms.Label();
            this.minBox = new System.Windows.Forms.TextBox();
            this.maxBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // introButton
            // 
            this.introButton.ForeColor = System.Drawing.SystemColors.ControlText;
            this.introButton.Location = new System.Drawing.Point(12, 119);
            this.introButton.Name = "introButton";
            this.introButton.Size = new System.Drawing.Size(560, 44);
            this.introButton.TabIndex = 0;
            this.introButton.Text = resources.GetString("introButton.Text");
            this.introButton.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.introButton.UseVisualStyleBackColor = true;
            this.introButton.Click += new System.EventHandler(this.introButton_Click);
            // 
            // scoreLabel
            // 
            this.scoreLabel.AutoSize = true;
            this.scoreLabel.Location = new System.Drawing.Point(12, 9);
            this.scoreLabel.Name = "scoreLabel";
            this.scoreLabel.Size = new System.Drawing.Size(38, 13);
            this.scoreLabel.TabIndex = 1;
            this.scoreLabel.Text = "Score:";
            // 
            // scoreBox
            // 
            this.scoreBox.Location = new System.Drawing.Point(56, 6);
            this.scoreBox.Name = "scoreBox";
            this.scoreBox.ReadOnly = true;
            this.scoreBox.Size = new System.Drawing.Size(100, 20);
            this.scoreBox.TabIndex = 2;
            this.scoreBox.Text = "0";
            this.scoreBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // ansPrompt
            // 
            this.ansPrompt.AutoSize = true;
            this.ansPrompt.Location = new System.Drawing.Point(9, 56);
            this.ansPrompt.Name = "ansPrompt";
            this.ansPrompt.Size = new System.Drawing.Size(95, 13);
            this.ansPrompt.TabIndex = 3;
            this.ansPrompt.Text = "Type your number:";
            // 
            // ansBox
            // 
            this.ansBox.Enabled = false;
            this.ansBox.Location = new System.Drawing.Point(110, 53);
            this.ansBox.Name = "ansBox";
            this.ansBox.Size = new System.Drawing.Size(100, 20);
            this.ansBox.TabIndex = 4;
            this.ansBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.ansBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.ansBox_KeyDown);
            // 
            // verdictLabel
            // 
            this.verdictLabel.AutoSize = true;
            this.verdictLabel.Location = new System.Drawing.Point(9, 89);
            this.verdictLabel.Name = "verdictLabel";
            this.verdictLabel.Size = new System.Drawing.Size(43, 13);
            this.verdictLabel.TabIndex = 5;
            this.verdictLabel.Text = "Verdict:";
            // 
            // verdictBox
            // 
            this.verdictBox.Location = new System.Drawing.Point(56, 86);
            this.verdictBox.Name = "verdictBox";
            this.verdictBox.ReadOnly = true;
            this.verdictBox.Size = new System.Drawing.Size(154, 20);
            this.verdictBox.TabIndex = 6;
            this.verdictBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // timeLabel
            // 
            this.timeLabel.AutoSize = true;
            this.timeLabel.Location = new System.Drawing.Point(162, 9);
            this.timeLabel.Name = "timeLabel";
            this.timeLabel.Size = new System.Drawing.Size(50, 13);
            this.timeLabel.TabIndex = 7;
            this.timeLabel.Text = "Time left:";
            // 
            // gameTimer
            // 
            this.gameTimer.Interval = 125;
            this.gameTimer.Tick += new System.EventHandler(this.gameTimer_Tick);
            // 
            // progressBar1
            // 
            this.progressBar1.Location = new System.Drawing.Point(209, 3);
            this.progressBar1.Maximum = 480;
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(363, 23);
            this.progressBar1.TabIndex = 8;
            this.progressBar1.Value = 480;
            // 
            // startButton
            // 
            this.startButton.Location = new System.Drawing.Point(467, 68);
            this.startButton.Name = "startButton";
            this.startButton.Size = new System.Drawing.Size(90, 23);
            this.startButton.TabIndex = 9;
            this.startButton.Text = "START";
            this.startButton.UseVisualStyleBackColor = true;
            this.startButton.Click += new System.EventHandler(this.startButton_Click);
            // 
            // minLabel
            // 
            this.minLabel.AutoSize = true;
            this.minLabel.Location = new System.Drawing.Point(245, 56);
            this.minLabel.Name = "minLabel";
            this.minLabel.Size = new System.Drawing.Size(48, 13);
            this.minLabel.TabIndex = 10;
            this.minLabel.Text = "Minimum";
            // 
            // maxLabel
            // 
            this.maxLabel.AutoSize = true;
            this.maxLabel.Location = new System.Drawing.Point(245, 89);
            this.maxLabel.Name = "maxLabel";
            this.maxLabel.Size = new System.Drawing.Size(51, 13);
            this.maxLabel.TabIndex = 11;
            this.maxLabel.Text = "Maximum";
            // 
            // minBox
            // 
            this.minBox.Location = new System.Drawing.Point(299, 53);
            this.minBox.Name = "minBox";
            this.minBox.ReadOnly = true;
            this.minBox.Size = new System.Drawing.Size(100, 20);
            this.minBox.TabIndex = 12;
            this.minBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // maxBox
            // 
            this.maxBox.Location = new System.Drawing.Point(299, 86);
            this.maxBox.Name = "maxBox";
            this.maxBox.ReadOnly = true;
            this.maxBox.Size = new System.Drawing.Size(100, 20);
            this.maxBox.TabIndex = 13;
            this.maxBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // mainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(584, 173);
            this.Controls.Add(this.maxBox);
            this.Controls.Add(this.minBox);
            this.Controls.Add(this.maxLabel);
            this.Controls.Add(this.minLabel);
            this.Controls.Add(this.startButton);
            this.Controls.Add(this.progressBar1);
            this.Controls.Add(this.timeLabel);
            this.Controls.Add(this.verdictBox);
            this.Controls.Add(this.verdictLabel);
            this.Controls.Add(this.ansBox);
            this.Controls.Add(this.ansPrompt);
            this.Controls.Add(this.scoreBox);
            this.Controls.Add(this.scoreLabel);
            this.Controls.Add(this.introButton);
            this.Name = "mainForm";
            this.Text = "Number Guess - Powered by #Team4T";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button introButton;
        private System.Windows.Forms.Label scoreLabel;
        private System.Windows.Forms.TextBox scoreBox;
        private System.Windows.Forms.Label ansPrompt;
        private System.Windows.Forms.TextBox ansBox;
        private System.Windows.Forms.Label verdictLabel;
        private System.Windows.Forms.TextBox verdictBox;
        private System.Windows.Forms.Label timeLabel;
        private System.Windows.Forms.Timer gameTimer;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.Button startButton;
        private System.Windows.Forms.Label minLabel;
        private System.Windows.Forms.Label maxLabel;
        private System.Windows.Forms.TextBox minBox;
        private System.Windows.Forms.TextBox maxBox;
    }
}

