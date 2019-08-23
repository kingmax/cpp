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
	ͨ��extern "C"ʹ��(������������C++�������������ظı䣬ͬʱ��C���Է�ʽд,�粻ʹ��string����ʹ��char*)
	ʹ��x86(32λ����DLL)
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
	__declspec(dllexport) int t(const char *s) // ok
	//__declspec(dllexport) int test(const string s) // error in c#, ����˺����������룡
	{
		cout << "dll function test(const string) in cpp:\n\t";
		cout << s << endl;
		return 100;
	}

	__declspec(dllexport) int a(int a, int b) { return a + b; }	// ok

	__declspec(dllexport) void b(const char *s) { cout << s; }
	__declspec(dllexport) int c(const char *s) { cout << s; return 0; }
	__declspec(dllexport) int o(const char *s) { cout << s; return 0; }
	__declspec(dllexport) void p(const char *s) { cout << s; }
	__declspec(dllexport) int q(const char *s) { cout << s; return 0; }
	__declspec(dllexport) void r(const char *s) { cout << s; }
	__declspec(dllexport) int u(const char *s) { cout << s; return 0; }
	__declspec(dllexport) int v(const char *s) { cout << s; return 0; }
	__declspec(dllexport) float w(const char *s) { cout << s; return 0.1f; }
	__declspec(dllexport) int x(const char *s) { cout << s; return 0; }
	__declspec(dllexport) double y() { return 10000; }
	__declspec(dllexport) double z(const char *s) { cout << s; return 184327932; }
	


	//__declspec(dllexport) void dencrypt_my_mse(const char *my_mse, const char *out_mse)
	//����ȡ�෴����ĺ�����, ʵ����;��������ԭ�����ܵ��ļ�
	__declspec(dllexport) int e(const char *my_mse, const char *out_mse)
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

		// ���������mse��ֱ�Ӹ��Ƶ������ʱĿǰ(by c#)
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

	//һЩû�õĺ��������������������������
	__declspec(dllexport) int f(const char *s) { return -1; }
	__declspec(dllexport) int g(const char *s) { return -1; }
	__declspec(dllexport) int h(const char *s) { return -1; }
	__declspec(dllexport) int i(const char *s) { return -1; }
	__declspec(dllexport) int j(const char *s) { return -1; }
	__declspec(dllexport) int k(const char *s) { return -1; }
	__declspec(dllexport) int l(const char *s) { return -1; }
	__declspec(dllexport) int n(const char *s) { return -1; }

	__declspec(dllexport) int s(int a, int b) { return a - b; }	// ok
	__declspec(dllexport) int m(int a, int b) { return a * b; }	// ok
	__declspec(dllexport) int d(int a, int b) { return ((b == 0) ? 0 : a / b); }	// ok
}

// dll �в����õ�main
int main()
{
	encrypt_mse(R"(D:\git\cpp\msTesting\src.mse)", R"(D:\git\cpp\msTesting\src_copy.mse)");
	cout << "encrypt done" << endl;

	e(R"(D:\git\cpp\msTesting\src_copy.mse)", R"(D:\git\cpp\msTesting\src_dencrypt.mse)");
	cout << "dencrypt done." << endl;

	cout << a(100, 100) << endl;
	t("���");
	system("pause");
	return 0;
}