#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		cerr << "usage:: map_set.exe infile" << endl;
		return -1;
	}
	
	ifstream fp(argv[1]);
	if(!fp)
	{
		cerr << "cannot open the file" << endl;
		return -2;
	}
	
	string w;
	set<string> exclude = {"The", "But", "And", "Or", "An", "A", 
						   "the", "but", "and", "or", "an", "a"};
	map<string, size_t> word_count;
	
	while(fp >> w)
	{
		if(!w.empty() && exclude.find(w) == exclude.end())
			++word_count[w];
	}
	
	fp.close();
	cout << "read file finished. " << argv[1] << endl;
	for(const auto &m : word_count)
		cout << m.first << " -> " << m.second << endl;
	
	return 0;
}