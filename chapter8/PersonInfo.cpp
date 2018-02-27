#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct PersonInfo
{
	string name;
	vector<string> phones;
};

int main(int argc, char **argv)
{
	string line, word;
	vector<PersonInfo> people;
	
	while(getline(cin, line))
	{
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		while(record >> word)
		{
			info.phones.push_back(word);
		}
		people.push_back(info);
	}
	
	cout << "\ninput finished" << endl;
	for(auto p : people)
	{
		cout << p.name << ' ';
		for(auto n : p.phones)
			cout << n << ' ';
		cout << endl;
	}
	
	return 0;
}