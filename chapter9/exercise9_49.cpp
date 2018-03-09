#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		cout << "usage: exercise9_49.exe in_word_file" << endl;
		return -1;
	}
	
	string ascender("bdfhijklt"); //("bdfhkl");
	string descender("gjpqy");
	vector<string> other_words;
	string longest_word("");
	
	ifstream fp(argv[1]);
	if(fp)
	{
		while(!fp.eof())
		{
			string line;
			getline(fp, line);
			istringstream iss(line);
			string other_word;
			while(!iss.eof())
			{
				iss >> other_word;
				if( other_word.find_first_of(ascender) == string::npos && 
					other_word.find_first_of(descender)== string::npos)
				{
					other_words.push_back(other_word);
					
					if(other_word.size() > longest_word.size())
						longest_word = other_word;
				}
			}
		}
		fp.close();
	}
	else
	{
		cerr << "Cloudn't open file " << argv[1] << endl;
		return -2;
	}
	
	cout << "found other word(s): (neither ascender nor descender)" << endl;
	for(const auto &w : other_words)
		cout << w << ' ';
	cout << endl;
	cout << "\nthe longest word is: " << longest_word << endl;
	
	
	return 0;
}
