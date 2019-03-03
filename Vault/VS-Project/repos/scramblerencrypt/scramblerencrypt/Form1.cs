using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace scramblerencrypt
{
    public partial class mainForm : Form
    {
        string[] lines;
        int key;

        public mainForm()
        {
            InitializeComponent();
            Random rnd = new Random();
            keyBox.Text = rnd.Next(0, 10000).ToString();
        }

        private void openButton_Click(object sender, EventArgs e)
        {
            if (!int.TryParse(keyBox.Text, out key))
            {
                sysAnnounce.Text = "Invalid key format!"; return;
            }
            else if (int.Parse(keyBox.Text) < 0 || int.Parse(keyBox.Text) > 9999)
            {
                sysAnnounce.Text = "Key must be between 0 and 9999!"; return;
            }
            else key = int.Parse(keyBox.Text);
            openDialog.ShowDialog();
        }

        private void encryptButton_Click(object sender, EventArgs e)
        {
            saveDialog.ShowDialog();
        }

        private void openDialog_FileOk(object sender, CancelEventArgs e)
        {
            fnBox.Text = openDialog.FileName;
            using (System.IO.StreamWriter sw = System.IO.File.AppendText(openDialog.FileName))
            {
                sw.WriteLine("Written for Mai with all heart. Key = {0}", key);
                sw.Dispose(); sw.Close();
            }
            lines = System.IO.File.ReadAllLines(fnBox.Text);
        }

        private void saveDialog_FileOk(object sender, CancelEventArgs e)
        {
            System.IO.StreamWriter swriter = new System.IO.StreamWriter(saveDialog.FileName);
            char[] chr = new char[63]; chr[62] = ' ';
            for (int i = 0; i < 10; i++) chr[i] = (char)(48 + i);
            for (int i = 10; i < 36; i++) chr[i] = (char)(65 + i - 10);
            for (int i = 36; i < 62; i++) chr[i] = (char)(97 + i - 36);
            int[] sd = new int[63]; for (int i = 0; i < 63; i++) sd[i] = i;
            sd = ShuffleArray(sd);
            foreach (string line in lines)
            {
                Console.WriteLine(line);
                char[] lc = line.ToCharArray();
                foreach (char c in lc)
                {
                    int z = 0;
                    Console.Write("{0}", z);
                    if (c == ' ') z = 62;
                    else if (c <= '9') z = (int)(c) - 48;
                    else if (c <= 'Z') z = (int)(c) - 65 + 10;
                    else z = (int)(c) - 97 + 36;
                    Console.Write("{0}", z);
                    if (sd[z] < 10) swriter.Write("{0}", (char)(48 + sd[z]));
                    else if (sd[z] < 36) swriter.Write("{0}", (char)(65 + sd[z] - 10));
                    else if (sd[z] < 62) swriter.Write("{0}", (char)(97 + sd[z] - 36));
                    else swriter.Write(" ");
                }
                swriter.WriteLine("");
                Console.WriteLine("");
            }
            swriter.Dispose(); swriter.Close();
        }

        int[] ShuffleArray(int[] array)
        {
            Random r = new Random(key);
            for (int i = array.Length; i > 0; i--)
            {
                int j = r.Next(i);
                int k = array[j];
                array[j] = array[i - 1];
                array[i - 1] = k;
            }
            return array;
        }
    }
}
