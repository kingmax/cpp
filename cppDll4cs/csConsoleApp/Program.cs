using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Runtime.InteropServices;

namespace csConsoleApp
{
    class Program
    {
        [DllImport(@"d:\git\cpp\cppDll4cs\Release\cppDll4cs.dll")]
        //[DllImport(@"d:\git\cpp\cppDll4cs\x64\Release\cppDll4cs.dll")]
        public static extern int add(int a, int b);

        [DllImport(@"D:\git\cpp\cppDll4cs\Release\cppDll4cs.dll", EntryPoint ="test")]
        //[DllImport(@"D:\git\cpp\cppDll4cs\x64\Release\cppDll4cs.dll", EntryPoint ="test")]
        public static extern int Test(string s);
        //public static extern int test([MarshalAs(UnmanagedType.LPStr)] string s);

        [DllImport("cppDll4cs.dll", EntryPoint = "encrypt")]
        public static extern void Encrypt(string mse1, string mse2);

        static void Main(string[] args)
        {
            Console.WriteLine("cs app using cpp dll function");

            int x = add(100, 200);
            Console.WriteLine(x);

            string s = "hi";
            int z = Test(s);
            //Console.WriteLine(z);

            string temp = Path.GetTempFileName();
            Console.WriteLine(temp);
            string mse = @"D:\git\cpp\msTesting\src_encrypt.mse";
            Encrypt(mse, temp+".mse");

            Test("Done, 我是中文呢");

            Console.ReadKey();
        }
    }
}
