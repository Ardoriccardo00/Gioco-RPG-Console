﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Istruzioni
{
    public partial class gioco3 : Form
    {
        public gioco3()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            gioco4 g4 = new gioco4();
            g4.Show();
            this.Hide();
        }
    }
}
