#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		cerr << "usage: exercise8_10.exe in_file" << endl;
		return -1;
	}
	
	vector<string> lines;
	ifstream input(argv[1]);
	if(input)
	{
		while(!input.eof())
		{
			string line;
			getline(input, line);
			if(!line.empty())
				lines.push_back(line);
		}
		input.close();
	}
	else
	{
		cerr << "Cloudn't open file: " << argv[1] << endl;
		return -2;
	}
	
	for(auto line : lines)
	{
		istringstream iss(line);
		string word;
		while(!iss.eof())
		{
			iss >> word;
			cout << word << "\t";
		}
		cout << endl;
	}
	
	return 0;
}