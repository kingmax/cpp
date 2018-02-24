#include <iostream>
#include <string>
using namespace std;

struct Sales_data
{
	string bookNo;
	unsigned sold;
	double revenue;
};

class Debug
{
	public:
		constexpr Debug(bool b=true) : hw(b), io(b), other(b){}
		constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o){}
		constexpr bool any(){return hw || io || other;}
		
		void set_io(bool b){ io = b; }
		void set_hw(bool b){ hw = b; }
		void set_other(bool b){ other = b;}
		
	private:
		bool hw;
		bool io;
		bool other;
};

int main()
{
	//aggregate class:
	//1. all public
	//2. no constructor function defined
	//3. no member init value
	//4. no virtual, base-class
	Sales_data item = {"987-0590353403", 25, 15.99};
	
	/*
		d:\git\cpp\chapter7>cl /EHsc exercise7_52.cpp
		用于 x64 的 Microsoft (R) C/C++ 优化编译器 19.12.25835 版
		版权所有(C) Microsoft Corporation。保留所有权利。

		exercise7_52.cpp
		exercise7_52.cpp(40): error C2662: “bool Debug::any(void)”: 不能将“this”指针从“const Debug”转换为“Debug &”
		exercise7_52.cpp(40): note: 转换丢失限定符
		exercise7_52.cpp(44): error C2662: “bool Debug::any(void)”: 不能将“this”指针从“const Debug”转换为“Debug &”
		exercise7_52.cpp(44): note: 转换丢失限定符
	*/
	cout << "constexpr constructor" << endl;
	constexpr Debug io_sub(false, true, false); //Debug IO
	if(io_sub.any()) //compile error
		cerr << "print appropriate error message" << endl;
	
	constexpr Debug prod(false); //No debug
	if(prod.any())   //compile error
		cerr << "print an error message" << endl;
	
	return 0;
}