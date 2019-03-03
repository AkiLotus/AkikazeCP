using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace calculator
{
    public partial class Calculator : Form
    {
        String p1 = "";
        String p2 = "";
        String ans = "";
        String memory = "0";
        String err = "No errors.";

        int position = 1;

        char operation = '?';

        public Calculator()
        {
            InitializeComponent();
            p1TextBox.ReadOnly = true;
            p2TextBox.ReadOnly = true;
            ansTextBox.ReadOnly = true;
            memTextBox.ReadOnly = true;
            errorBox.ReadOnly = true;
            this.KeyPreview = true;
            this.KeyDown += new KeyEventHandler(Calculator_KeyDown);
        }

        private String strAdd(String a1, String a2)
        {
            int len = a1.Length; if (a2.Length > len) len = a2.Length; len++;
            String tmp = ""; for (int i = 0; i < len - a1.Length; i++) tmp = tmp.Insert(0, "0");
            a1 = a1.Insert(0, tmp);
            tmp = ""; for (int i = 0; i < len - a2.Length; i++) tmp = tmp.Insert(0, "0");
            a2 = a2.Insert(0, tmp);
            char[] ca1 = a1.ToCharArray();
            char[] ca2 = a2.ToCharArray();
            char[] cares = new char[len];
            int carry = 0;
            for (int i=len-1; i>=0; i--)
            {
                int p1 = (int)ca1[i] - 48;
                int p2 = (int)ca2[i] - 48;
                int val = p1 + p2 + carry;
                cares[i] = (char)(48 + val % 10);
                carry = val / 10;
            }
            String res = new string(cares);
            while (res.IndexOf('0') == 0) res = res.Remove(0, 1);
            return res;
        }

        private void resetCommence()
        {
            if (ans != "" && position == 1)
            {
                p1 = ""; p2 = "";
                ans = ""; err = "No errors.";
            }
        }

        private void updateTextBox()
        {
            p1TextBox.Text = p1;
            p2TextBox.Text = p2;
            ansTextBox.Text = ans;
            memTextBox.Text = memory;
            errorBox.Text = err;
        }

        private void Calculator_Load(object sender, EventArgs e)
        {

        }

        private void digit_0_Click(object sender, EventArgs e)
        {
            resetCommence();
            if (position == 1) { p1 += "0"; }
            else { p2 += "0"; }
            updateTextBox();
        }

        private void digit_1_Click(object sender, EventArgs e)
        {
            resetCommence();
            if (position == 1) { p1 += "1"; }
            else { p2 += "1"; }
            updateTextBox();
        }

        private void digit_2_Click(object sender, EventArgs e)
        {
            resetCommence();
            if (position == 1) { p1 += "2"; }
            else { p2 += "2"; }
            updateTextBox();
        }

        private void digit_3_Click(object sender, EventArgs e)
        {
            resetCommence();
            if (position == 1) { p1 += "3"; }
            else { p2 += "3"; }
            updateTextBox();
        }

        private void digit_4_Click(object sender, EventArgs e)
        {
            resetCommence();
            if (position == 1) { p1 += "4"; }
            else { p2 += "4"; }
            updateTextBox();
        }

        private void digit_5_Click(object sender, EventArgs e)
        {
            resetCommence();
            if (position == 1) { p1 += "5"; }
            else { p2 += "5"; }
            updateTextBox();
        }

        private void digit_6_Click(object sender, EventArgs e)
        {
            resetCommence();
            if (position == 1) { p1 += "6"; }
            else { p2 += "6"; }
            updateTextBox();
        }

        private void digit_7_Click(object sender, EventArgs e)
        {
            resetCommence();
            if (position == 1) { p1 += "7"; }
            else { p2 += "7"; }
            updateTextBox();
        }

        private void digit_8_Click(object sender, EventArgs e)
        {
            resetCommence();
            if (position == 1) { p1 += "8"; }
            else { p2 += "8"; }
            updateTextBox();
        }

        private void digit_9_Click(object sender, EventArgs e)
        {
            resetCommence();
            if (position == 1) { p1 += "9"; }
            else { p2 += "9"; }
            updateTextBox();
        }

        private void Calculator_KeyDown(object sender, System.Windows.Forms.KeyEventArgs e)
        {
            if (e.KeyCode == Keys.D0) { digit_0_Click(sender, e); }
            if (e.KeyCode == Keys.D1) { digit_1_Click(sender, e); }
            if (e.KeyCode == Keys.D2) { digit_2_Click(sender, e); }
            if (e.KeyCode == Keys.D3) { digit_3_Click(sender, e); }
            if (e.KeyCode == Keys.D4) { digit_4_Click(sender, e); }
            if (e.KeyCode == Keys.D5) { digit_5_Click(sender, e); }
            if (e.KeyCode == Keys.D6) { digit_6_Click(sender, e); }
            if (e.KeyCode == Keys.D7) { digit_7_Click(sender, e); }
            if (e.KeyCode == Keys.D8) { digit_8_Click(sender, e); }
            if (e.KeyCode == Keys.D9) { digit_9_Click(sender, e); }
            if (e.KeyCode == Keys.Return) { calcButton_Click(sender, e); }
            if (e.KeyCode == Keys.Back) { delButton_Click(sender, e); }
            if (e.KeyCode == Keys.Escape) { aclearButton_Click(sender, e); }
            if (e.KeyCode == Keys.Oemplus) { addButton_Click(sender, e); }
        }

        private void calcButton_Click(object sender, EventArgs e)
        {
            resetCommence();
            if (operation == '+')
            {
                ans = strAdd(p1, p2);
                updateTextBox(); operation = '?';
                addButton.BackColor = default(Color);
                position = 1; return;
            }
        }

        private void addButton_Click(object sender, EventArgs e)
        {
            resetCommence();
            if (position == 2)
            {
                err = "Error - 2nd parameter reached!";
                updateTextBox(); return;
            }
            position = 2; operation = '+';
            if (p1 == "") p1 = "0";
            addButton.BackColor = Color.BlueViolet; updateTextBox();
        }

        private void subButton_Click(object sender, EventArgs e)
        {
            resetCommence();
            if (position == 2)
            {
                err = "Error - 2nd parameter reached!";
                updateTextBox(); return;
            }
            position = 2; operation = '-';
            if (p1 == "") p1 = "0";
            subButton.BackColor = Color.BlueViolet; updateTextBox();
        }

        private void mulButton_Click(object sender, EventArgs e)
        {
            resetCommence();
            if (position == 2)
            {
                err = "Error - 2nd parameter reached!";
                updateTextBox(); return;
            }
            position = 2; operation = '*';
            if (p1 == "") p1 = "0";
            mulButton.BackColor = Color.BlueViolet; updateTextBox();
        }

        private void divButton_Click(object sender, EventArgs e)
        {
            resetCommence();
            if (position == 2)
            {
                err = "Error - 2nd parameter reached!";
                updateTextBox(); return;
            }
            position = 2; operation = '/';
            if (p1 == "") p1 = "0";
            divButton.BackColor = Color.BlueViolet; updateTextBox();
        }

        private void divtruncButton_Click(object sender, EventArgs e)
        {
            resetCommence();
            if (position == 2)
            {
                err = "Error - 2nd parameter reached!";
                updateTextBox(); return;
            }
            position = 2; operation = '\\';
            if (p1 == "") p1 = "0";
            divtruncButton.BackColor = Color.BlueViolet; updateTextBox();
        }

        private void modButton_Click(object sender, EventArgs e)
        {
            resetCommence();
            if (position == 2)
            {
                err = "Error - 2nd parameter reached!";
                updateTextBox(); return;
            }
            position = 2; operation = '%';
            if (p1 == "") p1 = "0";
            modButton.BackColor = Color.BlueViolet; updateTextBox();
        }

        private void aclearButton_Click(object sender, EventArgs e)
        {
            position = 1; ans = "1";
            resetCommence(); ans = "";
            updateTextBox();
            addButton.BackColor = default(Color);
            subButton.BackColor = default(Color);
            mulButton.BackColor = default(Color);
            divButton.BackColor = default(Color);
            divtruncButton.BackColor = default(Color);
            modButton.BackColor = default(Color);
        }

        private void delButton_Click(object sender, EventArgs e)
        {
            resetCommence();
            if (position == 1)
            {
                if (p1 == "") err = "Error - empty parameter.";
                else p1 = p1.Remove(p1.Length - 1);
            }
            else
            {
                if (p2 == "") err = "Error - empty parameter.";
                else p2 = p2.Remove(p2.Length - 1);
            }
            updateTextBox();
        }
    }
}
