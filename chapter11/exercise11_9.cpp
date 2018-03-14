#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		//cl /EHsc /Fe:word_line.exe exercise11_9.cpp
		cerr << "usage:: word_line.exe infile" << endl;
		return -1;
	}
	
	ifstream fp(argv[1]);
	if(!fp)
		return -2;
	
	unsigned line_number = 0;
	map<string, list<unsigned>> word_line;
	string line, word;
	while(!fp.eof())
	{
		getline(fp, line);
		++line_number;
		stringstream ss(line);
		while(ss >> word)
			if(word_line[word].empty())
				word_line[word] = {line_number};
			else
				word_line[word].push_back(line_number);
	}
	
	for(const auto &m : word_line)
	{
		cout << m.first << ' ';
		for(const auto &n : m.second)
			cout << n << ' ';
		cout << endl;
	}
	cout << endl;
	
	//exercise11.10
	map<vector<int>::iterator, int> mi;
	map<list<int>::iterator, int> mi2;
	
	cout << string(80, '$') << endl;
	map<string, list<unsigned>>::const_iterator map_it = word_line.cbegin();
	while(map_it != word_line.cend())
	{
		cout << map_it->first << " occurs " << map_it->second.size() << " times" << endl;
		++map_it;
	}
	
	return 0;
}