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

	void query(string &s);

private:
	vector<string> lines;
	map<string, set<int>> word_lineNumber;
};


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