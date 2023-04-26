using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsCalculator
{
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();
            KeyPreview = true; // For KeyDown to work (for some reason)
            Controller = new Controller(input, inputAll);
        }
        
        private Controller Controller { get; }
        
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.D0:
                    Controller.Process(ModifierKeys == Keys.Shift ? @")" : @"0");
                    break;
                case Keys.D1:
                    Controller.Process(@"1");
                    break;
                case Keys.D2:
                    Controller.Process(@"2");
                    break;
                case Keys.D3:
                    Controller.Process(@"3");
                    break;
                case Keys.D4:
                    Controller.Process(@"4");
                    break;
                case Keys.D5:
                    Controller.Process(@"5");
                    break;
                case Keys.D6:
                    Controller.Process(@"6");
                    break;
                case Keys.D8:
                    if (ModifierKeys == Keys.Shift)
                    {
                        Controller.Process(@"*");
                    }
                    break;
                case Keys.D9:
                    if (ModifierKeys == Keys.Shift)
                    {
                        Controller.Process(@"(");
                    }
                    break;
                case Keys.Escape:
                    Dispose(true);
                    break;
                case Keys.Delete:
                    Controller.Process(@"Delete");
                    break;
                case Keys.Back:
                    Controller.Process(@"Backspace");
                    break;
                case Keys.Oemplus:
                    Controller.Process(ModifierKeys == Keys.Shift ? @"+" : @"=");
                    break;
                case Keys.OemQuestion:
                    Controller.Process(@"/");
                    break;
                case Keys.OemMinus:
                    Controller.Process(@"-");
                    break;
                case Keys.OemPeriod:
                    Controller.Process(@".");
                    break;
            }
        }
        

        private void num0_Click(object sender, EventArgs e)
        {
            Controller.Process(@"0");
        }

        private void num1_Click(object sender, EventArgs e)
        {
            Controller.Process(@"1");
        }

        private void num2_Click(object sender, EventArgs e)
        {
            Controller.Process(@"2");
        }

        private void num3_Click(object sender, EventArgs e)
        {
            Controller.Process(@"3");
        }

        private void num4_Click(object sender, EventArgs e)
        {
            Controller.Process(@"4");
        }

        private void num5_Click(object sender, EventArgs e)
        {
            Controller.Process(@"5");
        }

        private void num6_Click(object sender, EventArgs e)
        {
            Controller.Process(@"6");
        }

        // private void num7_Click(object sender, EventArgs e)
        // {
        //     Controller.Process(@"7");
        // }
        //
        // private void num8_Click(object sender, EventArgs e)
        // {
        //     Controller.Process(@"8");
        // }
        //
        // private void num9_Click(object sender, EventArgs e)
        // {
        //     Controller.Process(@"9");
        // }
        //
        // private void numA_Click(object sender, EventArgs e)
        // {
        //     Controller.Process(@"A");
        // }
        //
        // private void numB_Click(object sender, EventArgs e)
        // {
        //     Controller.Process(@"B");
        // }
        //
        // private void numC_Click(object sender, EventArgs e)
        // {
        //     Controller.Process(@"C");
        // }
        //
        // private void numD_Click(object sender, EventArgs e)
        // {
        //     Controller.Process(@"D");
        // }

        private void commandDot_Click(object sender, EventArgs e)
        {
            Controller.Process(@".");
        }

        private void commandEqual_Click(object sender, EventArgs e)
        {
            Controller.Process(@"=");
        }

        private void commandClear_Click(object sender, EventArgs e)
        {
            Controller.Process(@"Clear");
        }

        private void commandPlus_Click(object sender, EventArgs e)
        {
            Controller.Process(@"+");
        }

        private void commandMinus_Click(object sender, EventArgs e)
        {
            Controller.Process(@"-");
        }

        private void commandMultiply_Click(object sender, EventArgs e)
        {
            Controller.Process(@"*");
        }

        private void commandDivide_Click(object sender, EventArgs e)
        {
            Controller.Process(@"/");
        }

        private void commadLeft_Click(object sender, EventArgs e)
        {
            Controller.Process(@"(");
        }

        private void commandRight_Click(object sender, EventArgs e)
        {
            Controller.Process(@")");
        }
        
    }
}