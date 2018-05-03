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
    public partial class gioco1 : Form
    {
        public gioco1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            gioco2 g2 = new gioco2();
            g2.Show();
        }
    }
}
