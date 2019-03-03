using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Security.Cryptography;
using System.Windows.Forms;

namespace logintest
{
    public partial class mainForm : Form
    {
        Dictionary<String, String> UPMap = new Dictionary<string, string>();
        SHA256 personalSHA256 = SHA256Managed.Create();

        public mainForm()
        {
            InitializeComponent();
            this.KeyPreview = true;
            this.KeyDown += new KeyEventHandler(mainForm_KeyDown);
            this.MaximizeBox = false;
        }

        private void mainForm_KeyDown(object sender, System.Windows.Forms.KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Return) loginButton.PerformClick();
        }

        private string getHash(string s)
        {
            var crypt = new System.Security.Cryptography.SHA256Managed();
            var hash = new System.Text.StringBuilder();
            byte[] crypto = crypt.ComputeHash(Encoding.UTF8.GetBytes(s));
            foreach (byte theByte in crypto)
            {
                hash.Append(theByte.ToString("x2"));
            }
            return hash.ToString();
        }

        private void mainForm_Load(object sender, EventArgs e)
        {
            string[] lines = System.IO.File.ReadAllLines("data.txt");
            for (int i=0; i<lines.Length; i++)
            {
                string[] token = lines[i].Split();
                UPMap[token[0]] = token[1];
            }
        }

        private void loginButton_Click(object sender, EventArgs e)
        {
            string user = getHash(userBox.Text);
            string pass = getHash(passBox.Text);
            if (UPMap[user] == pass) MessageBox.Show("Login successful!");
            else MessageBox.Show("Login details mismatch!");
        }
    }
}
