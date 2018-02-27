#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//std::istream &process(istream &is)
void process(istream &is)
{
	string line;
	while(!is.eof())
	{
		getline(is, line);
		if(!line.empty())
			cout << line << endl;
	}
	//return is;
}

int main(int argc, char **argv)
{
	cout << "usage: auto_fs.exe in_file1 in_file2 ..." << endl;
	
	for(auto p = argv + 1; p != argv + argc; ++p)
	{
		cout << "read:\t" << *p << endl;
		
		//ifstream input(*p);
		ifstream input;
		input.open(*p);
		
		if(input)
		{
			process(input);
			cout << endl;
		}
		else
			cerr << "couldn't open file" << endl;
		
		//input.close(); //since input is local in for scope, so if leave for scope, input will close automaticlly!
	}
	
	return 0;
}
