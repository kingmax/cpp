#include <fstream>
#include <iostream>
#include <string>

// https://blog.csdn.net/calmreason/article/details/7935258
#include <locale>
#include <Windows.h>

using namespace std;

void write_read()
{
	locale ch("chs");
	wcin.imbue(ch);
	wcout.imbue(ch);
	wstring s;
	wchar_t wc = L'。';

	wofstream out;
	out.imbue(ch);
	out.open("out_ch.txt", ios::out);
	out.seekp(0, out.beg);
	if (!out)
	{
		cerr << "out_ch.txt create failed!" << endl;
		return;
	}

	wcout << L"请输入中文字内容，以便写入文件,以句号结束输入！" << endl;

	while (getline(wcin, s, wc))
	{
		wcout << s << endl;
		out << s << endl;
		break;
	}

	out.close();
	out.clear();

	cout << "\nread out_ch.txt\n" << endl;
	wifstream in("out_ch.txt");
	in.imbue(ch);
	if (!in)
	{
		cerr << "open out_ch.txt failed!" << endl;
		return;
	}

	WCHAR line[80];
	//while (!in.eof() && in >> line)
	while (in.getline(line, 80))
	{
		wcout << line << endl;
	}
	in.close();
}

// https://blog.csdn.net/ZhanCF/article/details/49930969
string utf8togb(const char* str)
{
	string ret;
	WCHAR *strSrc;
	LPSTR szRes;

	//获得临时变量的大小
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//获得临时变量的大小
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	ret = szRes;
	delete[] strSrc;
	delete[] szRes;

	return ret;
}


int main()
{
	string txt_ch = u8"这是EssentialC++中文版第39页";

	ofstream outfile("seq_data.txt", ios_base::app);
	if (!outfile)
	{
		cerr << "Oops! Unable to save session data!\n";
	}
	else
	{
		outfile << "usr_name:" << ' '
			<< "num_tries:" << ' '
			<< "num_right:" << endl;

		outfile << txt_ch << endl;

		cout << "写文件结束" << endl;
	}
	outfile.close();

	cout << "\nread from file\n";
	ifstream infile("seq_data.txt");
	if (!infile)
	{
		cerr << "Can not open seq_data.txt" << endl;
	}
	else
	{
		string name;
		//wchar_t name;
		int nt;
		int nc;

		while (infile >> name)
		{
			if (name == "usr_name:")
			{
				cout << "Welcome back, " << name << endl;
				
				infile >> nt >> nc;
				cout << "Your current score is " << nc
					<< " out of " << nt
					<< "\nGood Luck!\n";
			}
			else
			{
				cout << endl << name << endl;
			}
		}

		cout << endl;
		cout << "try read 2:\n";
		cout << infile.tellg() << endl;
		infile.clear();
		infile.seekg(infile.beg);
		char *line = new char[80];
		while (infile.getline(line, 80))
		{
			cout << line << endl;
		}
		delete[] line;
	}

	cout << "\n using utf8togb:\n";
	infile.clear();
	infile.seekg(infile.beg);
	char txt[80];
	string sTxt;
	while (!infile.eof())
	{
		infile.getline(txt, 80);
		sTxt = utf8togb(txt);
		cout << sTxt << endl;
	}

	cout << "\n write_read(ch) testing started.\n";
	write_read();

	system("pause");
	return 0;
}