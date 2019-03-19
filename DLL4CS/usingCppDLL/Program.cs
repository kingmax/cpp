using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Runtime.InteropServices;

namespace usingCppDLL
{
    class Program
    {
        [DllImport(@"D:\git\cpp\DLL4CS\x64\Release\DLL4CS.dll", CharSet=CharSet.Unicode, CallingConvention =CallingConvention.Cdecl)]
        public static extern int FunctionInDLL(String s);

        [DllImport(@"D:\git\cpp\DLL4CS\x64\Release\dll2.dll", CharSet=CharSet.Auto, SetLastError=true, CallingConvention=CallingConvention.Cdecl)]
        public static extern int fn(string s);


        static void Main(string[] args)
        {
            Console.WriteLine("Writen by C#.");

            int ret2 = fn("你好");
            Console.WriteLine("ret2 = {0}", ret2);

            int ret = FunctionInDLL("Some string from C#.");
            Console.WriteLine("C++ returned the value: " + ret);
        }
    }
}
