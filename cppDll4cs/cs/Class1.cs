using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace cs
{
    public static class c
    {
        //[DllImport(@"D:\git\cpp\cppDll4cs\Release\cpp.dll", EntryPoint = "add", CallingConvention = CallingConvention.Cdecl)]
        //[DllImport(@"D:\git\cpp\cppDll4cs\x64\Release\cpp.dll", EntryPoint = "add", CallingConvention = CallingConvention.Cdecl)]
        [DllImport("cpp.dll")]
        public static extern int add(int x, int y);
    }
}
