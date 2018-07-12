#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

void usage()
{
	cout << "usage: ex12.17.exe in_file query_keyword" << endl;
}

int main(int argc, char** argv)
{
	usage();
	if(argc < 2)
		return -1;
	
	ifstream input(argv[1]);
	if(!input)
	{
		cerr << "Couldn't open the file" << endl;
		return -1;
	}
	
	vector<string> contents;
	while(!input.eof())
	{
		string line;
		getline(input, line);
		//if(!line.empty())
			contents.push_back(line);
	}
	input.close();
	
	cout << "\nread file finished, lines count: " << contents.size() << endl;
	for(const string& s : contents)
		cout << s << endl;
	cout << endl;
	
	
	string keyword;
	
	do
	{
		cout << "\n\ninput query keyword:" << endl;
		cin >> keyword;
		/* if(keyword.empty())
			return -1; */
		
		unsigned cnt(0);
		set<unsigned> lineNums;
		map<string, set<unsigned>> queryResult;
		/* struct _result
		{
			map<string, set<unsigned>> a;
			unsigned n;
		} result; */
		
		for(unsigned i=0; i<contents.size(); ++i)
		{
			//cout << contents[i] << endl;
			istringstream iss(contents[i]);
			while(!iss.eof())
			{
				string word;
				iss >> word;
				if(word == keyword)
				{
					++cnt;
					lineNums.insert(i);
					//cout << cnt << ' ' << word << endl;
				}
			}
		}
		queryResult[keyword] = lineNums;
		
		cout << "keyword: " << keyword << " occurs: " << cnt << " times!" << endl;
		for(auto i : lineNums)
			cout << i+1 << "\t" << contents[i] << endl;
		// #include #include #include
	}
	while(!keyword.empty() && keyword != "q");
	
	return 0;
}

