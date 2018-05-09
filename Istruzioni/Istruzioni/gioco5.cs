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
    public partial class gioco5 : Form
    {
        public gioco5()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            gioco6 g6 = new gioco6();
            g6.Show();
            this.Hide();
        }
    }
}
