using System;
using System.Collections.Generic;
using System.Text;

using System.Runtime.InteropServices;

namespace csConsoleApp
{
    class Program
    {
        [DllImport(@"d:\git\cpp\cppDll4cs\Release\cppDll4cs.dll")]
        public static extern int add(int a, int b);

        [DllImport(@"d:\git\cpp\cppDll4cs\Release\cppDll4cs.dll", EntryPoint ="test")]
        public static extern int test(string s);
        //public static extern int test([MarshalAs(UnmanagedType.LPStr)] string s);

        static void Main(string[] args)
        {
            Console.WriteLine("cs app using cpp dll function");

            int x = add(100, 200);
            Console.WriteLine(x);

            string s = "hi";
            int z = test(s);
            Console.WriteLine(z);

            Console.ReadKey();
        }
    }
}
