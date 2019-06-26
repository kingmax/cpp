#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

template<typename T>
void display(const string &msg, const vector<T> &vec, ostream &os = cout)
{
	os << msg << endl;
	for(const auto &x : vec)
		cout << x << ' ';
	os << endl;
}

template<typename T>
void display(const string &msg, const list<T> &list, ostream &os = cout)
{
	os << msg << endl;
	for(auto &x : list)
		cout << x << ' ';
	os << endl;
}

int main()
{
	vector<int> vi = {1, 2, 3, 4, 5};
	display<int>("vector<int>", vi);
	
	list<double> list = {6.0, 7.0, 8.0, 9.0};
	display<double>("list<double>", list);
	
	return 0;
}