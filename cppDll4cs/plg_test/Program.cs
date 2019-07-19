using System;
using System.IO;
using System.Runtime.InteropServices;

namespace plg
{
    class Program
    {
        [DllImport("cppDll4cs.dll", EntryPoint = "encrypt")]
        public static extern void Encrypt(string mse1, string mse2);

        static void Main(string[] args)
        {
            string temp = Path.GetTempFileName();
            Console.WriteLine(temp);

            string mse = @"D:\git\cpp\msTesting\src_encrypt.mse";
            Encrypt(mse, temp);

            Console.WriteLine("kingmax_res@163.com");

            Console.ReadKey();
        }
    }
}
