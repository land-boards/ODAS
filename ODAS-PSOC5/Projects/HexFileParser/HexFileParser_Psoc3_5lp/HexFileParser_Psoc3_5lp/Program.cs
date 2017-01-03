using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace HexFileParser_Psoc3_5lp
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new FormHexFileParser_Psoc3_5lp());
        }
    }
}
