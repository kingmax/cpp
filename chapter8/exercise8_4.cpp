#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		cerr << "usage:exercise8_4.exe in_file" << endl;
		return -1;
	}
	
	vector<string> lines;
	//ifstream input(argv[1]);
	ifstream input;
	input.open(argv[1]);
	if(input)
	{
		string line;
		while(!input.eof() && getline(input, line))
		{
			//getline(input, line);
			if(!line.empty())
				lines.push_back(line);
		}
	}
	input.close();
	cout << "read file finished." << endl;
	
	cout << "line count: " << lines.size() << endl;
	for(auto x : lines)
		cout << x << endl;
	cout << endl;
	
	return 0;
}