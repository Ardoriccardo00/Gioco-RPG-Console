using System;
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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {
            Informazioni i = new Informazioni();
            i.Show();
           
        }

        private void label3_Click(object sender, EventArgs e)
        {
            Istruzioni ii = new Istruzioni();
            ii.Show();
        }

        private void label4_Click(object sender, EventArgs e)
        {
            no n = new no();
            n.Show();
        }
    }
}
