using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Dashboard
{
    internal class MainPanel : Panel
    {
        internal SelectedTab tab = SelectedTab.Projects;
        private void ColorCheck()
        {
            projects.BackColor = tab == SelectedTab.Projects ? MColor.foreground : MColor.background;
            settings.BackColor = tab == SelectedTab.Settings ? MColor.foreground : MColor.background;
        }
        internal MainPanel()
        {
            BackColor = MColor.background;
            Size = new Size(100, 500);

            Controls.Add(title);
            Controls.Add(projects);
            Controls.Add(settings);

            title.ForeColor = Color.White;
            title.Text = "Zuba";
            title.TextAlign = ContentAlignment.MiddleCenter;
            title.Font = MFont.MainHeader;
            title.Size = new Size(100, 50);

            projects.ForeColor = Color.White;
            projects.BackColor = MColor.foreground;
            projects.Text = "Projects";
            projects.Location = new Point(0, 100);
            projects.Size = new Size(100, 50);
            projects.FlatStyle = FlatStyle.Flat;
            projects.FlatAppearance.BorderSize = 0;
            projects.Font = MFont.MainHeader;
            projects.MouseClick += (sender, e) =>
            {
                tab = SelectedTab.Projects;
                ColorCheck();
            };

            settings.ForeColor = Color.White;
            settings.BackColor = MColor.foreground;
            settings.Text = "Settings";
            settings.Location = new Point(0, 150);
            settings.Size = new Size(100, 50);
            settings.FlatStyle = FlatStyle.Flat;
            settings.FlatAppearance.BorderSize = 0;
            settings.Font = MFont.MainHeader;
            settings.MouseClick += (sender, e) =>
            {
                tab = SelectedTab.Settings;
                ColorCheck();
            };
            ColorCheck();
        }
        Label title = new Label();
        Button projects = new Button();
        Button settings = new Button();
    }
    internal enum SelectedTab : byte
    {
        Projects,
        Settings,
    }
}
