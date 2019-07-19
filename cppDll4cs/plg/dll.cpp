#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

/*
	cpp dll for c# call:
	1. extern "C" (if for another cpp call, even using extern "C" when dllimport)
	2. x86 -> 32bit (x64 error!)
	通过extern "C"使用(函数名不会像C++那样被可能重载改变，同时按C语言方式写,如不使用string而是使用char*)
	使用x86(32位编译DLL)
*/



//base64 encode("kingmax_res@163.com") + "CETXNUL"
const string header = "a2luZ21heF9yZXNAMTYzLmNvbQCETXNUL";
// Last line
const string last_line = "kingmax_res@163.com|";

// read from mse as binary, encrypt it then write out as binary, ext is .mse
void encrypt_mse(const char *in_mse, const char *out_mse)
{
	ifstream input(string(in_mse), ios::binary | ios::in);
	ofstream output(string(out_mse), ios::binary | ios::out);
	if (input && output)
	{
		output << header;

		string line;
		while (!input.eof())
		{
			getline(input, line);
			output << line << endl;
		}

		for (auto &c : last_line)
		{
			int i = (int)c;
			output << i << c;
		}
		output << last_line;
	}
}


extern "C"
{
	__declspec(dllexport) int test(const char *s) // ok
	//__declspec(dllexport) int test(const string s) // error in c#, 输出了后面多余的乱码！
	{
		cout << "dll function test(const string) in cpp:\n\t";
		cout << s << endl;
		return 100;
	}

	__declspec(dllexport) int add(int a, int b) { return a + b; }	// ok


	//__declspec(dllexport) void dencrypt_my_mse(const char *my_mse, const char *out_mse)
	//故意取相反意义的函数名, 实际用途是用来还原被加密的文件
	__declspec(dllexport) int encrypt(const char *my_mse, const char *out_mse)
	{
		ifstream input(string(my_mse), ios::binary | ios::in);
		ofstream output(string(out_mse), ios::binary | ios::out);
		vector<string> contents;

		if (input)
		{
			string line;
			while (!input.eof())
			{
				getline(input, line);
				contents.push_back(line);
			}
		}
		else
		{
			return -1;
		}

		// 如果是正常mse则直接复制到随机临时目前(by c#)
		if (contents[0].find(header) == string::npos)
		{
			fs::copy_file(fs::path(my_mse), fs::path(out_mse), fs::copy_options::overwrite_existing);
			return 0;
		}

		string first_line = contents[0].substr(header.length());
		//cout << contents[0] << endl << first_line;
		contents[0] = first_line;
		contents.pop_back();
		if (output)
		{
			for (auto &line : contents)
			{
				output << line << endl;
			}
			return 0;
		}

		return -1;
	}

	//一些没用的函数，导出，是用来故意充数的
	__declspec(dllexport) int sub(int a, int b) { return a - b; }	// ok
	__declspec(dllexport) int mul(int a, int b) { return a * b; }	// ok
	__declspec(dllexport) int _div(int a, int b) { return ((b == 0) ? 0 : a / b); }	// ok
}

// dll 中不会用到main
int main()
{
	encrypt_mse(R"(D:\git\cpp\msTesting\src.mse)", R"(D:\git\cpp\msTesting\src_copy.mse)");
	cout << "encrypt done" << endl;

	//dencrypt_my_mse(R"(D:\git\cpp\msTesting\src_copy.mse)", R"(D:\git\cpp\msTesting\src_dencrypt.mse)");
	//cout << "dencrypt done." << endl;

	/*cout << add(100, 100) << endl;
	test("你好");*/
	system("pause");
	return 0;
}