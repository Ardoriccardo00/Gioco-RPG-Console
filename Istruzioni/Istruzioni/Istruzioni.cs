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
    public partial class Istruzioni : Form
    {
        public Istruzioni()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {
            gioco1 g1 = new gioco1();
            g1.Show();
        }
    }
}
