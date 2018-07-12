#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <iostream>
#include <sstream>
#include <set>
#include <map>

using namespace std;

class QueryResult;

using line_no = vector<string>::size_type;

class TextQuery
{
public:
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
	
private:
	shared_ptr<vector<string>> file;
	map<string,shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
	string text;
	while(getline(is, text))
	{
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while(line >> word)
		{
			auto &lines = wm[word]; //shared_ptr<set<line_no>>
			if(!lines)				//first meet, lines is null ptr
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

class QueryResult
{
	friend ostream& print(ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) :
	sought(s), lines(p), file(f)
	{
		
	}
	
private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
};

QueryResult TextQuery::query(const string &sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

ostream& print(ostream& os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " time(s)" << endl;
	for(auto n : *qr.lines)
		os << "\t(line " << n + 1 << ") "
		   << *(qr.file->begin() + n) << endl;
	return os;
}

int main(int argc, char** argv)
{
	if(argc < 2)
		return -1;
	
	ifstream input(argv[1]);
	if(!input)
		return -1;
	
	TextQuery tq(input);
	input.close();
	
	while(1)
	{
		cout << "enter word to look for, or q to quit: " << endl;
		string s;
		if(!(cin >> s) || s == "q")
			break;
		
		print(cout, tq.query(s)) << endl;
	}
	
	return 0;
	//#include #include
}