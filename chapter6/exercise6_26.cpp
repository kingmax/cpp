#include <iostream>
#include <string>
#include <vector>
using namespace std;

void usage()
{
	cout << string(30, '-') << endl;
	cout << "xxx.exe -d -o ofile data0" << endl;
	cout << string(30, '-') << endl;
}

void _print(vector<string> vs)
{
	for(string s : vs)
		cout << s << ' ';
	cout << endl;
}

//int main(int argc, char *argv[])
int main(int argc, char **argv)
{
	cout << "arguments: " << endl;
	/* int arr[] = {1,2,3};
	for(auto i : arr)
		cout << i << endl;
	cout << endl; */
	
	/* cout << **argv << endl;
	cout << *argv << endl; */
	
	cout << "\n1------------------" << endl;
	for(int i = 0; i != argc; ++i)
	{
		cout << argv[i] << endl;
	}
	
	cout << "\n2------------------" << endl;
	for(int i = 0; i != argc; ++i)
	{
		cout << *argv++ << endl;
	}
	cout << endl;
	
	char c = 'A';
	char *p = &c;
	char **pc = &p;
	cout << "&c:" << &c << endl
		 << "ptr:" << p << ", val:" << *p << endl
		 << "**pc:"<< pc << ", val:"<< **pc << endl;
		 
	cout << "\n6.26:" << endl;
	//xxx.exe -d -o ofile data0
	if(argc < 5)
	{
		usage();
		cout << "argc < 5" << endl;
		return -1;
	}
	cout << "argc >= 5" << endl;
	
	vector<string> vs;
	int n = 0;
	argv -= 5; //reset ptr (line 41 move to end)
	//cout << *argv;
	while(n < 5)
	{
		vs.push_back(*argv++);
		++n;
		/* vs.push_back(argv[n]);
		++n; */
	}
	_print(vs);
	
	//if(argv[1] != "-d" || argv[2] != "-o") //error, c-style char[] NOT string
	if(vs[1] != "-d" || vs[2] != "-o")
	{
		usage();
		cout << "argv[1] != -d || argv[2] != -o" << endl;
		return -1;
	}
	
	cout << "program starting..." << endl;
	
	return 0;
}