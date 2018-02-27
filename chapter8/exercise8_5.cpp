#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		cerr << "usage:exercise8_5.exe in_file" << endl;
		return -1;
	}
	
	ifstream input(argv[1]);
	vector<string> words;
	unsigned cnt=0;
	if(input)
	{
		string word;
		while(!input.eof() && input >> word)
		{
			//input >> word;
			if(!word.empty())
			{
				words.push_back(word);
				++cnt;
			}
		}
	}
	else
	{
		cout << "read file error" << endl;
		return -2;
	}
	
	cout << "read file finished." << endl;
	cout << "word count:" << cnt << endl;
	cout << "words.size=" << words.size() << endl;
	for(auto w : words)
		cout << w << endl;
	cout << endl;
	
	return 0;
}