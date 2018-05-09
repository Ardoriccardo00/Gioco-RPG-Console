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
    public partial class gioco2 : Form
    {
        public gioco2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            gioco3 g3 = new gioco3();
            g3.Show();
            this.Hide();
        }
    }
}
