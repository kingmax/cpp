#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> words;
	string word;
	while(cin >> word && word != "q")
		words.push_back(word);
	for(auto &w : words)
	{
		for(auto &c : w)
			c = toupper(c);
		cout << w << ' ';
	}
	cout << endl;
	
	//3.19
	vector<int> v1(10, 42);
	vector<int> v2{42,42,42,42,42,42,42,42,42,42};
	vector<int> v3 = {42,42,42,42,42,42,42,42,42,42};
	cout << v1.size() << ' ' << v2.size() << ' ' << v3.size() << endl;
	for(auto i : v1)
		cout << i << ' ';
	cout << endl;
	for(auto i : v2)
		cout << i << ' ';
	cout << endl;
	for(auto i : v3)
		cout << i << ' ';
	cout << endl;
	
	//3.20
	vector<int> ints;
	int input;
	cout << "enter some ints:" << endl;
	while(cin >> input && input != 0)
		ints.push_back(input);
	cout << "your inputs:" << endl;
	for(auto i : ints)
		cout << i << ' ';
	cout << endl;
	
	if(ints.size() < 2)
		cout << "ints.size < 2, can't add." << endl;
	else
	{
		cout << "\nneighbor sum:" << endl;
		for(decltype(ints.size()) i = 0, j = i + 1; j != ints.size(); ++i, ++j)
		{
			cout << ints[i] << " + " << ints[j] << " = " << ints[i] + ints[j] << endl;
		}
		cout << endl;
		
		cout << "brother sum:" << endl;
		/* for(decltype(ints.size()) i = 0; i*2+1 <= ints.size(); ++i)
		{
			if(i*2+1 == ints.size())
				cout << "alone:" << ints[ints.size()-1] << endl;
			else
				cout << ints[i*2] << " + " << ints[i*2+1] << " = " << ints[i*2] + ints[i*2+1] << endl;
		} */
		for(decltype(ints.size()) i = 0; i < ints.size(); i += 2)
		{
			if(i+1 == ints.size())
				cout << "last alone:" << ints[i] << endl;
			else
				cout << ints[i] << " + " << ints[i+1] << " = " << ints[i] + ints[i+1] << endl;
		}
		
		cout << "\nfirst + last:" << endl;
		for(decltype(ints.size()) i = 0, j = ints.size()-1; i <= j; ++i, --j)
		{
			if( i == j)
				cout << "middle:" << ints[i] << endl;
			else
				cout << ints[i] << " + " << ints[j] << " = " << ints[i] + ints[j] << endl;
		}
	}
	
	
	return 0;
}