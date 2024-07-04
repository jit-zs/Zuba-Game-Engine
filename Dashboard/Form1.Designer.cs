using System;
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;

namespace Dashboard
{
    [DesignerCategory("")]
    partial class Form1
    {
        private const int WM_NCHITTEST = 0x84;
        private const int WM_LBUTTONUP = 0x0202;
        private const int HT_CLIENT = 0x1;
        private const int HT_CAPTION = 2;


        private System.ComponentModel.IContainer components = null;
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }
        protected override void WndProc(ref Message m)
        {
            const int cGrip = 24;

            strip.Size = new Size(Width, cGrip);
            strip.Location = new Point(0, 0);
            panel.Location = new Point(0, cGrip);
            switch (m.Msg)
            {
                case WM_NCHITTEST:
                    Point pos = new Point(m.LParam.ToInt32());
                    pos = PointToClient(pos);
                    if (pos.Y < cGrip/*strip.Height*/)
                    {
                        m.Result = (IntPtr)HT_CAPTION;
                        return;
                    }
                    if (pos.X >= this.ClientSize.Width - cGrip && pos.Y >= this.ClientSize.Height - cGrip)
                    {
                        m.Result = (IntPtr)17;
                        return;
                    }
                    break;
                default:
                    base.WndProc(ref m);
                    break;
            }
        }
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(600, 400);
            this.MaximumSize = new Size(600, 400);
            this.MinimumSize = new Size(600, 400);
            this.Text = "Form1";
            this.FormBorderStyle = FormBorderStyle.None;
            this.MaximizeBox = false;
            this.MinimizeBox = false;

            strip = new WindowStrip();
            panel = new MainPanel();

            strip.Location = Point.Empty;
            strip.Dock = DockStyle.Top;
            strip.Anchor = AnchorStyles.Top;

            panel.Location = Point.Empty;
            Controls.Add(strip);
            Controls.Add(panel);
           
            
        }
        WindowStrip strip;
        MainPanel panel;
    }
}

