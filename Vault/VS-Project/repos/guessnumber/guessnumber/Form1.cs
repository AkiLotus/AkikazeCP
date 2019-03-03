using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace guessnumber
{
    public partial class mainForm : Form
    {
        string submittedAnswer = "";
        int desiredNumber = 0, score = 0;
        int minimum = 0, maximum = 0;
        Random rnd = new Random();

        public mainForm()
        {
            InitializeComponent();
            this.KeyPreview = true;
            this.KeyDown += new KeyEventHandler(mainForm_KeyDown);
            this.MaximizeBox = false;
        }

        private void ansBox_KeyDown(object sender, System.Windows.Forms.KeyEventArgs e)
        {
        }

        private void verdict()
        {
            int ans;
            if (!Int32.TryParse(submittedAnswer, out ans))
            {
                if (submittedAnswer == "JadeMasochist") verdictBox.Text = "Hey, stop teasing me!";
                else if (submittedAnswer == "thuytrangxinhdep") verdictBox.Text = "Team4T\'s T has arrived!";
                else if (submittedAnswer == "Akikaze") verdictBox.Text = "Addressed the wind?";
                else verdictBox.Text = "INCORRECT FORMAT"; return;
            }
            ans = Int32.Parse(submittedAnswer);
            if (ans == desiredNumber)
            {
                if (!gameTimer.Enabled)
                {
                    verdictBox.Text = "CORRECT, BUT TIMEOUT";
                    return;
                }
                verdictBox.Text = "CORRECT"; score++;
                if (progressBar1.Value + progressBar1.Maximum / 6 <= progressBar1.Maximum)
                {
                    progressBar1.Value += progressBar1.Maximum / 6;
                }
                else progressBar1.Value = progressBar1.Maximum;
                scoreBox.Text = score.ToString();
                generateNumber();
            }
            else if (ans < desiredNumber) verdictBox.Text = "TOO LOW";
            else verdictBox.Text = "TOO HIGH";
        }
        
        private void mainForm_KeyDown(object sender, System.Windows.Forms.KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Return)
            {
                submittedAnswer = ansBox.Text;
                ansBox.Text = ""; verdict();
            }
        }

        private void generateNumber()
        {
            minimum = rnd.Next(0, 10000);
            maximum = rnd.Next(minimum, 10001);
            desiredNumber = rnd.Next(minimum, maximum + 1);
            minBox.Text = minimum.ToString();
            maxBox.Text = maximum.ToString();
        }

        private void gameTimer_Tick(object sender, EventArgs e)
        {
            if (progressBar1.Value - 1 >= progressBar1.Minimum)
            {
                progressBar1.Value--;
                if (progressBar1.Value == 1) startButton.Text = (progressBar1.Value.ToString()).Insert(progressBar1.Value.ToString().Length, " tick left");
                else startButton.Text = (progressBar1.Value.ToString()).Insert(progressBar1.Value.ToString().Length, " ticks left");
            }
            else
            {
                gameTimer.Stop();
                gameTimer.Enabled = false;
                ansBox.Enabled = false;
                startButton.Text = "START";
            }
        }

        private void startButton_Click(object sender, EventArgs e)
        {
            if (gameTimer.Enabled) return;
            ansBox.Enabled = true;
            gameTimer.Enabled = true;
            gameTimer.Start();
            progressBar1.Value = progressBar1.Maximum;
            scoreBox.Text = "0"; score = 0;
            generateNumber();
        }

        private void introButton_Click(object sender, EventArgs e)
        {
            // Really?
        }
    }
}
