using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace plg
{
    public static class c
    {
        [DllImport("plg.dll", EntryPoint ="e")]
        public static /*unsafe*/ extern void e();

        public static string hi()
        {
            return "hi";
        }
    }
}
