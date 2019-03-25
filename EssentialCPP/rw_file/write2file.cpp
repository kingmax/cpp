#include <fstream>
#include <iostream>
#include <string>

#include <locale>

using namespace std;

//ostream	&read_txt_ch(ostream &os, const string &file_name)
//{
//	locale ch("chs");
//	os.imbue(ch);
//	while (getline()
//	{
//
//	}
//}

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
		infile.seekg(0);
		char *line = new char[80];
		while (infile.getline(line, 80))
		{
			cout << line << endl;
		}
	}

	system("pause");
	return 0;
}