using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WF4Max
{
    public partial class MyWindow : Form
    {
        public MyWindow()
        {
            InitializeComponent();
        }

        void setStatus(object sender)
        {
            this.lblStatus.Text = (sender as Button).Text;
        }

        private void btnBox_Click(object sender, EventArgs e)
        {
            setStatus(sender);
        }

        private void btnSphere_Click(object sender, EventArgs e)
        {
            setStatus(sender);
        }

        private void btnCylinder_Click(object sender, EventArgs e)
        {
            setStatus(sender);
        }

        private void btnTeapot_Click(object sender, EventArgs e)
        {
            setStatus(sender);
        }

        private void btnPoint_Click(object sender, EventArgs e)
        {
            setStatus(sender);
        }

        private void btnDummy_Click(object sender, EventArgs e)
        {
            setStatus(sender);
        }
    }
}
