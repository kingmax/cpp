#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

class TextQuery
{
public:
	TextQuery(ifstream &inFile);

	void query(const string &s) const;

private:
	vector<string> lines;
	map<string, set<int>> word_lineNumber;
};

TextQuery::TextQuery(ifstream & inFile)
{
	string line;
	int line_number(0);
	while (!inFile.eof())
	{
		line_number++;
		//string line;
		//inFile >> line;
		getline(inFile, line);
		if (!line.empty())
		{
			this->lines.push_back(line);
			stringstream ss(line);
			string word;
			while (ss >> word)
			{
				if (word_lineNumber[word].empty())
				{
					word_lineNumber[word] = set<int>({ line_number });
				}
				else
				{
					word_lineNumber[word].insert(line_number);
				}
			}
		}
	}
}

void TextQuery::query(const string &word) const
{
	
}



void runQueries(ifstream &inFile)
{
	TextQuery tq(inFile);
	while (true)
	{
		cout << "enter word to look for, or q to quite: ";
		string s;
		if (!(cin >> s) || s == "q")
		{
			break;
		}
		print(cout, tq.query(s)) << endl;
	}
}



int main()
{


	return 0;
}


