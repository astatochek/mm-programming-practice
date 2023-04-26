using System.Windows.Forms;

namespace WindowsFormsCalculator
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }

            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.num0 = new System.Windows.Forms.Button();
            this.num1 = new System.Windows.Forms.Button();
            this.num2 = new System.Windows.Forms.Button();
            this.num3 = new System.Windows.Forms.Button();
            this.num4 = new System.Windows.Forms.Button();
            this.num6 = new System.Windows.Forms.Button();
            this.num5 = new System.Windows.Forms.Button();
            this.inputAll = new System.Windows.Forms.TextBox();
            this.input = new System.Windows.Forms.TextBox();
            this.commandDot = new System.Windows.Forms.Button();
            this.commandEqual = new System.Windows.Forms.Button();
            this.commandClear = new System.Windows.Forms.Button();
            this.commandPlus = new System.Windows.Forms.Button();
            this.commandMinus = new System.Windows.Forms.Button();
            this.commandMultiply = new System.Windows.Forms.Button();
            this.commandDivide = new System.Windows.Forms.Button();
            this.commandLeft = new System.Windows.Forms.Button();
            this.commandRight = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // num0
            // 
            this.num0.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.num0.Cursor = System.Windows.Forms.Cursors.Default;
            this.num0.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.num0.FlatAppearance.BorderSize = 0;
            this.num0.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.num0.Font = new System.Drawing.Font("JetBrains Mono", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.num0.ForeColor = System.Drawing.Color.Honeydew;
            this.num0.Location = new System.Drawing.Point(13, 389);
            this.num0.Margin = new System.Windows.Forms.Padding(4);
            this.num0.Name = "num0";
            this.num0.Size = new System.Drawing.Size(60, 128);
            this.num0.TabIndex = 0;
            this.num0.Text = "0";
            this.num0.UseVisualStyleBackColor = false;
            this.num0.Click += new System.EventHandler(this.num0_Click);
            // 
            // num1
            // 
            this.num1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.num1.Cursor = System.Windows.Forms.Cursors.Default;
            this.num1.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.num1.FlatAppearance.BorderSize = 0;
            this.num1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.num1.Font = new System.Drawing.Font("JetBrains Mono", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.num1.ForeColor = System.Drawing.Color.Honeydew;
            this.num1.Location = new System.Drawing.Point(81, 389);
            this.num1.Margin = new System.Windows.Forms.Padding(4);
            this.num1.Name = "num1";
            this.num1.Size = new System.Drawing.Size(60, 60);
            this.num1.TabIndex = 1;
            this.num1.Text = "1";
            this.num1.UseVisualStyleBackColor = false;
            this.num1.Click += new System.EventHandler(this.num1_Click);
            // 
            // num2
            // 
            this.num2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.num2.Cursor = System.Windows.Forms.Cursors.Default;
            this.num2.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.num2.FlatAppearance.BorderSize = 0;
            this.num2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.num2.Font = new System.Drawing.Font("JetBrains Mono", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.num2.ForeColor = System.Drawing.Color.Honeydew;
            this.num2.Location = new System.Drawing.Point(149, 389);
            this.num2.Margin = new System.Windows.Forms.Padding(4);
            this.num2.Name = "num2";
            this.num2.Size = new System.Drawing.Size(60, 60);
            this.num2.TabIndex = 2;
            this.num2.Text = "2";
            this.num2.UseVisualStyleBackColor = false;
            this.num2.Click += new System.EventHandler(this.num2_Click);
            // 
            // num3
            // 
            this.num3.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.num3.Cursor = System.Windows.Forms.Cursors.Default;
            this.num3.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.num3.FlatAppearance.BorderSize = 0;
            this.num3.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.num3.Font = new System.Drawing.Font("JetBrains Mono", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.num3.ForeColor = System.Drawing.Color.Honeydew;
            this.num3.Location = new System.Drawing.Point(217, 389);
            this.num3.Margin = new System.Windows.Forms.Padding(4);
            this.num3.Name = "num3";
            this.num3.Size = new System.Drawing.Size(60, 60);
            this.num3.TabIndex = 3;
            this.num3.Text = "3";
            this.num3.UseVisualStyleBackColor = false;
            this.num3.Click += new System.EventHandler(this.num3_Click);
            // 
            // num4
            // 
            this.num4.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.num4.Cursor = System.Windows.Forms.Cursors.Default;
            this.num4.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.num4.FlatAppearance.BorderSize = 0;
            this.num4.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.num4.Font = new System.Drawing.Font("JetBrains Mono", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.num4.ForeColor = System.Drawing.Color.Honeydew;
            this.num4.Location = new System.Drawing.Point(81, 457);
            this.num4.Margin = new System.Windows.Forms.Padding(4);
            this.num4.Name = "num4";
            this.num4.Size = new System.Drawing.Size(60, 60);
            this.num4.TabIndex = 4;
            this.num4.Text = "4";
            this.num4.UseVisualStyleBackColor = false;
            this.num4.Click += new System.EventHandler(this.num4_Click);
            // 
            // num6
            // 
            this.num6.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.num6.Cursor = System.Windows.Forms.Cursors.Default;
            this.num6.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.num6.FlatAppearance.BorderSize = 0;
            this.num6.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.num6.Font = new System.Drawing.Font("JetBrains Mono", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.num6.ForeColor = System.Drawing.Color.Honeydew;
            this.num6.Location = new System.Drawing.Point(217, 457);
            this.num6.Margin = new System.Windows.Forms.Padding(4);
            this.num6.Name = "num6";
            this.num6.Size = new System.Drawing.Size(60, 60);
            this.num6.TabIndex = 6;
            this.num6.Text = "6";
            this.num6.UseVisualStyleBackColor = false;
            this.num6.Click += new System.EventHandler(this.num6_Click);
            // 
            // num5
            // 
            this.num5.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.num5.Cursor = System.Windows.Forms.Cursors.Default;
            this.num5.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.num5.FlatAppearance.BorderSize = 0;
            this.num5.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.num5.Font = new System.Drawing.Font("JetBrains Mono", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.num5.ForeColor = System.Drawing.Color.Honeydew;
            this.num5.Location = new System.Drawing.Point(149, 457);
            this.num5.Margin = new System.Windows.Forms.Padding(4);
            this.num5.Name = "num5";
            this.num5.Size = new System.Drawing.Size(60, 60);
            this.num5.TabIndex = 5;
            this.num5.Text = "5";
            this.num5.UseVisualStyleBackColor = false;
            this.num5.Click += new System.EventHandler(this.num5_Click);
            // 
            // inputAll
            // 
            this.inputAll.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(50)))), ((int)(((byte)(50)))));
            this.inputAll.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.inputAll.CausesValidation = false;
            this.inputAll.Font = new System.Drawing.Font("JetBrains Mono SemiBold", 12F, System.Drawing.FontStyle.Bold);
            this.inputAll.ForeColor = System.Drawing.Color.Honeydew;
            this.inputAll.Location = new System.Drawing.Point(12, 72);
            this.inputAll.Name = "inputAll";
            this.inputAll.ReadOnly = true;
            this.inputAll.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.inputAll.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
            this.inputAll.Size = new System.Drawing.Size(401, 32);
            this.inputAll.TabIndex = 14;
            // 
            // input
            // 
            this.input.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(50)))), ((int)(((byte)(50)))));
            this.input.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.input.CausesValidation = false;
            this.input.Font = new System.Drawing.Font("JetBrains Mono SemiBold", 26F, System.Drawing.FontStyle.Bold);
            this.input.ForeColor = System.Drawing.Color.MintCream;
            this.input.Location = new System.Drawing.Point(13, 110);
            this.input.Name = "input";
            this.input.ReadOnly = true;
            this.input.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.input.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
            this.input.Size = new System.Drawing.Size(400, 69);
            this.input.TabIndex = 15;
            this.input.Text = "0";
            // 
            // commandDot
            // 
            this.commandDot.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(80)))), ((int)(((byte)(80)))), ((int)(((byte)(80)))));
            this.commandDot.Cursor = System.Windows.Forms.Cursors.Default;
            this.commandDot.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.commandDot.FlatAppearance.BorderSize = 0;
            this.commandDot.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.commandDot.Font = new System.Drawing.Font("JetBrains Mono", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.commandDot.ForeColor = System.Drawing.Color.Honeydew;
            this.commandDot.Location = new System.Drawing.Point(285, 457);
            this.commandDot.Margin = new System.Windows.Forms.Padding(4);
            this.commandDot.Name = "commandDot";
            this.commandDot.Size = new System.Drawing.Size(60, 60);
            this.commandDot.TabIndex = 16;
            this.commandDot.Text = ".";
            this.commandDot.UseVisualStyleBackColor = false;
            this.commandDot.Click += new System.EventHandler(this.commandDot_Click);
            // 
            // commandEqual
            // 
            this.commandEqual.BackColor = System.Drawing.Color.Honeydew;
            this.commandEqual.Cursor = System.Windows.Forms.Cursors.Default;
            this.commandEqual.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.commandEqual.FlatAppearance.BorderSize = 0;
            this.commandEqual.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.commandEqual.Font = new System.Drawing.Font("JetBrains Mono", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.commandEqual.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.commandEqual.Location = new System.Drawing.Point(353, 389);
            this.commandEqual.Margin = new System.Windows.Forms.Padding(4);
            this.commandEqual.Name = "commandEqual";
            this.commandEqual.Size = new System.Drawing.Size(60, 128);
            this.commandEqual.TabIndex = 17;
            this.commandEqual.Text = "=";
            this.commandEqual.UseVisualStyleBackColor = false;
            this.commandEqual.Click += new System.EventHandler(this.commandEqual_Click);
            // 
            // commandClear
            // 
            this.commandClear.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(80)))), ((int)(((byte)(80)))), ((int)(((byte)(80)))));
            this.commandClear.Cursor = System.Windows.Forms.Cursors.Default;
            this.commandClear.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.commandClear.FlatAppearance.BorderSize = 0;
            this.commandClear.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.commandClear.Font = new System.Drawing.Font("JetBrains Mono", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.commandClear.ForeColor = System.Drawing.Color.Honeydew;
            this.commandClear.Location = new System.Drawing.Point(285, 389);
            this.commandClear.Margin = new System.Windows.Forms.Padding(4);
            this.commandClear.Name = "commandClear";
            this.commandClear.Size = new System.Drawing.Size(60, 60);
            this.commandClear.TabIndex = 18;
            this.commandClear.Text = "c";
            this.commandClear.UseVisualStyleBackColor = false;
            this.commandClear.Click += new System.EventHandler(this.commandClear_Click);
            // 
            // commandPlus
            // 
            this.commandPlus.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(80)))), ((int)(((byte)(80)))), ((int)(((byte)(80)))));
            this.commandPlus.Cursor = System.Windows.Forms.Cursors.Default;
            this.commandPlus.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.commandPlus.FlatAppearance.BorderSize = 0;
            this.commandPlus.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.commandPlus.Font = new System.Drawing.Font("JetBrains Mono", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.commandPlus.ForeColor = System.Drawing.Color.Honeydew;
            this.commandPlus.Location = new System.Drawing.Point(12, 321);
            this.commandPlus.Margin = new System.Windows.Forms.Padding(4);
            this.commandPlus.Name = "commandPlus";
            this.commandPlus.Size = new System.Drawing.Size(61, 60);
            this.commandPlus.TabIndex = 19;
            this.commandPlus.Text = "+";
            this.commandPlus.UseVisualStyleBackColor = false;
            this.commandPlus.Click += new System.EventHandler(this.commandPlus_Click);
            // 
            // commandMinus
            // 
            this.commandMinus.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(80)))), ((int)(((byte)(80)))), ((int)(((byte)(80)))));
            this.commandMinus.Cursor = System.Windows.Forms.Cursors.Default;
            this.commandMinus.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.commandMinus.FlatAppearance.BorderSize = 0;
            this.commandMinus.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.commandMinus.Font = new System.Drawing.Font("JetBrains Mono", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.commandMinus.ForeColor = System.Drawing.Color.Honeydew;
            this.commandMinus.Location = new System.Drawing.Point(81, 321);
            this.commandMinus.Margin = new System.Windows.Forms.Padding(4);
            this.commandMinus.Name = "commandMinus";
            this.commandMinus.Size = new System.Drawing.Size(60, 60);
            this.commandMinus.TabIndex = 20;
            this.commandMinus.Text = "-";
            this.commandMinus.UseVisualStyleBackColor = false;
            this.commandMinus.Click += new System.EventHandler(this.commandMinus_Click);
            // 
            // commandMultiply
            // 
            this.commandMultiply.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(80)))), ((int)(((byte)(80)))), ((int)(((byte)(80)))));
            this.commandMultiply.Cursor = System.Windows.Forms.Cursors.Default;
            this.commandMultiply.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.commandMultiply.FlatAppearance.BorderSize = 0;
            this.commandMultiply.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.commandMultiply.Font = new System.Drawing.Font("JetBrains Mono", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.commandMultiply.ForeColor = System.Drawing.Color.Honeydew;
            this.commandMultiply.Location = new System.Drawing.Point(149, 321);
            this.commandMultiply.Margin = new System.Windows.Forms.Padding(4);
            this.commandMultiply.Name = "commandMultiply";
            this.commandMultiply.Size = new System.Drawing.Size(60, 60);
            this.commandMultiply.TabIndex = 21;
            this.commandMultiply.Text = "×";
            this.commandMultiply.UseVisualStyleBackColor = false;
            this.commandMultiply.Click += new System.EventHandler(this.commandMultiply_Click);
            // 
            // commandDivide
            // 
            this.commandDivide.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(80)))), ((int)(((byte)(80)))), ((int)(((byte)(80)))));
            this.commandDivide.Cursor = System.Windows.Forms.Cursors.Default;
            this.commandDivide.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.commandDivide.FlatAppearance.BorderSize = 0;
            this.commandDivide.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.commandDivide.Font = new System.Drawing.Font("JetBrains Mono", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.commandDivide.ForeColor = System.Drawing.Color.Honeydew;
            this.commandDivide.Location = new System.Drawing.Point(217, 321);
            this.commandDivide.Margin = new System.Windows.Forms.Padding(4);
            this.commandDivide.Name = "commandDivide";
            this.commandDivide.Size = new System.Drawing.Size(60, 60);
            this.commandDivide.TabIndex = 22;
            this.commandDivide.Text = "÷";
            this.commandDivide.UseVisualStyleBackColor = false;
            this.commandDivide.Click += new System.EventHandler(this.commandDivide_Click);
            // 
            // commandLeft
            // 
            this.commandLeft.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(80)))), ((int)(((byte)(80)))), ((int)(((byte)(80)))));
            this.commandLeft.Cursor = System.Windows.Forms.Cursors.Default;
            this.commandLeft.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.commandLeft.FlatAppearance.BorderSize = 0;
            this.commandLeft.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.commandLeft.Font = new System.Drawing.Font("JetBrains Mono", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.commandLeft.ForeColor = System.Drawing.Color.Honeydew;
            this.commandLeft.Location = new System.Drawing.Point(285, 321);
            this.commandLeft.Margin = new System.Windows.Forms.Padding(4);
            this.commandLeft.Name = "commandLeft";
            this.commandLeft.Size = new System.Drawing.Size(60, 60);
            this.commandLeft.TabIndex = 23;
            this.commandLeft.Text = "(";
            this.commandLeft.UseVisualStyleBackColor = false;
            this.commandLeft.Click += new System.EventHandler(this.commadLeft_Click);
            // 
            // commandRight
            // 
            this.commandRight.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(80)))), ((int)(((byte)(80)))), ((int)(((byte)(80)))));
            this.commandRight.Cursor = System.Windows.Forms.Cursors.Default;
            this.commandRight.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.commandRight.FlatAppearance.BorderSize = 0;
            this.commandRight.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.commandRight.Font = new System.Drawing.Font("JetBrains Mono", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.commandRight.ForeColor = System.Drawing.Color.Honeydew;
            this.commandRight.Location = new System.Drawing.Point(353, 321);
            this.commandRight.Margin = new System.Windows.Forms.Padding(4);
            this.commandRight.Name = "commandRight";
            this.commandRight.Size = new System.Drawing.Size(60, 60);
            this.commandRight.TabIndex = 24;
            this.commandRight.Text = ")";
            this.commandRight.UseVisualStyleBackColor = false;
            this.commandRight.Click += new System.EventHandler(this.commandRight_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoScroll = true;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(50)))), ((int)(((byte)(50)))));
            this.ClientSize = new System.Drawing.Size(426, 530);
            this.Controls.Add(this.commandRight);
            this.Controls.Add(this.commandLeft);
            this.Controls.Add(this.commandDivide);
            this.Controls.Add(this.commandMultiply);
            this.Controls.Add(this.commandMinus);
            this.Controls.Add(this.commandPlus);
            this.Controls.Add(this.commandClear);
            this.Controls.Add(this.commandEqual);
            this.Controls.Add(this.commandDot);
            this.Controls.Add(this.input);
            this.Controls.Add(this.inputAll);
            this.Controls.Add(this.num6);
            this.Controls.Add(this.num5);
            this.Controls.Add(this.num4);
            this.Controls.Add(this.num3);
            this.Controls.Add(this.num2);
            this.Controls.Add(this.num1);
            this.Controls.Add(this.num0);
            this.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Name = "Form1";
            this.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Septenary Calculator";
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.ResumeLayout(false);
            this.PerformLayout();
        }

        private System.Windows.Forms.Button commandDot;
        private System.Windows.Forms.Button commandEqual;
        private System.Windows.Forms.Button commandClear;
        private System.Windows.Forms.Button commandPlus;
        private System.Windows.Forms.Button commandMinus;
        private System.Windows.Forms.Button commandMultiply;
        private System.Windows.Forms.Button commandDivide;
        private System.Windows.Forms.Button commandLeft;
        private System.Windows.Forms.Button commandRight;

        private System.Windows.Forms.TextBox inputAll;
        private System.Windows.Forms.TextBox input;

        private System.Windows.Forms.Button num0;
        private System.Windows.Forms.Button num1;
        private System.Windows.Forms.Button num2;
        private System.Windows.Forms.Button num3;
        private System.Windows.Forms.Button num4;
        private System.Windows.Forms.Button num6;
        private System.Windows.Forms.Button num5;

        #endregion
    }
}