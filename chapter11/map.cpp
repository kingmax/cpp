#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		cerr << "usage:: map.exe infile" << endl;
		return -1;
	}
	
	ifstream fp(argv[1]);
	if(!fp)
	{
		cerr << "cann't open the file: " << argv[1] << endl;
		return -2;
	}
	
	string word;
	map<string, size_t> word_count;
	while(!fp.eof())
	{
		fp >> word;
		if(!word.empty())
			++word_count[word];
	}
	cout << "read file finished." << endl;
	
	for(const auto &wc : word_count)
		cout << wc.first << " -> " << wc.second << (wc.second > 1 ? " times" : " time") << endl;
	
	return 0;
}