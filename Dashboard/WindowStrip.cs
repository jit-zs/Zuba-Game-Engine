using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Dashboard
{
    internal class WindowStrip : Panel
    {
        protected override void WndProc(ref Message m)
        {
            const int WM_NCHITTEST = 0x84;
            const int HTTRANPARENT = (-1);
            quit.Location = new Point(this.Width - quit.Width, 0);
            switch (m.Msg)
            {
                case WM_NCHITTEST:
                    m.Result = (IntPtr)HTTRANPARENT;
                    break;
                default:
                    base.WndProc(ref m);
                    break;
            }
        }
        internal WindowStrip()
        {
            BackColor = Color.Maroon;


            quit = new Button();
            quit.Size = new Size(24, 24);
            quit.Text = "X";
            quit.Font = new Font(MFont.MainHeader.FontFamily, 10);
            quit.FlatStyle = FlatStyle.Flat;
            quit.FlatAppearance.BorderSize = 0;
            quit.Margin = new Padding(0);
            quit.TextImageRelation = TextImageRelation.Overlay;
            quit.ForeColor = Color.White;
            quit.BackColor = Color.DarkRed;
            quit.MouseClick += (sender, e) =>
            {
                Application.Exit();
            };

            Controls.Add(quit);
        }
        private Button quit;
    }
}
