using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Text;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dashboard
{
    internal static class MFont
    {
        private static PrivateFontCollection pfc = new PrivateFontCollection();

        public static Font MainHeader { get => mainHeader; }
        private static Font mainHeader;
        static MFont()
        {
            pfc.AddFontFile("CalSans-SemiBold.ttf");
            mainHeader = new Font(pfc.Families[0], 15);
        }
    }
}
