#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void output(const map<string, vector<string>> &family)
{
	for(const auto &m : family)
	{
		cout << "family:" << m.first << endl;
		//for_each(m.second.cbegin(), m.second.cend(), [](const string &s){cout << "\t" << s << endl;});
		for(const auto &c : m.second)
			cout << "\t" << c << endl;
		cout << endl;
	}
}

int main()
{
	map<string, vector<string>> family;
	cout << family.size() << endl;
	
	family["Li"] = {"Andy", "Wendy"};
	cout << family.size() << endl;
	output(family);	
	
	family["Huang"] = {"Renhao", "Renxin"};
	cout << family.size() << endl;
	output(family);	
	
	cout << string(80, '-') << endl;
	family["Li"].push_back("Jack");
	family["Li"].push_back("Rose");
	output(family);
	
	//exercise11.8
	cout << "enter some words testing unique vector:" << endl;
	vector<string> uniqueVec;
	string w;
	while(cin >> w && w != "q")
		if(find_if(uniqueVec.cbegin(), uniqueVec.cend(), [w](const string &s){return s == w;}) == uniqueVec.cend())
			uniqueVec.push_back(w);
	
	cout << "unique vector:" << endl;
	for(const auto &w : uniqueVec)
		cout << w << ' ';
	cout << endl;
	
	return 0;
}