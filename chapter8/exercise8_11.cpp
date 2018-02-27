#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct PersonInfo
{
	string name;
	vector<string> phones;
};

bool valid(const string &s)
{
	for(const auto &c : s)
		if(!isdigit(c))
			return false;
	return true;
}

int main()
{
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	while(getline(cin, line))
	{
		/* record.str(line);
		cout << record.str() << endl; */
		
		record = istringstream(line);
		if(record)
		{
			PersonInfo info;
			record >> info.name;
			while(record >> word)
				info.phones.push_back(word);
			people.push_back(info);
		}
	}
	
	cout << "\nready\n" << endl;
	cout << people.size() << endl;
	for(auto p : people)
	{
		cout << p.name << ' ';
		for(auto x : p.phones)
			cout << x << ' ';
		cout << endl;
	}
	
	//8.3.2 ostringstream
	cout << "\n8.3.2 ostringstream" << endl;
	for(const auto &entry : people)
	{
		ostringstream formatted, badNums;
		for(const auto &nums : entry.phones)
		{
			if(!valid(nums))
				badNums << ' ' << nums;
			else
				formatted << ' ' << nums;
		}
		
		if(badNums.str().empty())
			cout << entry.name << ' ' << formatted.str() << endl;
		else
			cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << endl;
	}
	
	
	return 0;
}