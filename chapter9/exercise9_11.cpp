#include <vector>
#include <list>
#include <string>
#include <iostream>
using namespace std;

void print(const vector<int> &iv)
{
	cout << "size:" << iv.size() << endl;
	for(const auto &i : iv)
		cout << i << ' ';
	cout << endl;
}

int main()
{
	vector<int> ivec1;
	vector<int> ivec2(10);
	vector<int> ivec3(10, 100);
	vector<int> ivec4 = {1,2,3,4};
	vector<int> ivec5 = ivec3;
	vector<int> ivec6{1,2,3,4,5,6};
	
	for(auto vec : {ivec1, ivec2, ivec3, ivec4, ivec5, ivec6})
		print(vec);
	
	//exercise 9.13
	cout << "\nexercise 9.13" << endl;
	list<int> ilist = {1,3,5,7,9};
	vector<double> dvec = {ilist.cbegin(), ilist.cend()};
	cout << dvec.size() << endl;
	for(const auto &x : dvec)
		cout << x << ' ';
	cout << endl;
	
	dvec = {ivec5.cbegin(), ivec5.cend()};
	cout << dvec.size() << endl;
	for(const auto &x : dvec)
		cout << x << ' ';
	cout << endl;
	
	dvec.assign(ivec6.cbegin(), ivec6.cend()); //assign can handle difference data type!!!
	cout << dvec.size() << endl;
	for(const auto &x : dvec)
		cout << x << ' ';
	cout << endl;
	
	ilist.assign(8, 8);
	cout << ilist.size() << endl;
	for(const auto &x : ilist)
		cout << x << ' ';
	cout << endl;
	
	list<int> ilist2(6);
	swap(ilist, ilist2); //swap same data type, even length difference!
	cout << ilist.size() << endl;
	for(const auto &x : ilist)
		cout << x << ' ';
	cout << endl;
	
	cout << ilist2.size() << endl;
	for(const auto &x : ilist2)
		cout << x << ' ';
	cout << endl;
	
	
	
	list<string> names{""};
	for(const auto &s : names)
		cout << s << endl;
	vector<const char*> oldstyle = {"Hi", "Jason"};
	//names = oldstyle; //error
	names.assign(oldstyle.cbegin(), oldstyle.cend()); //ok
	cout << names.size() << endl;
	for(const auto &s : names)
		std::cout << s << endl;
	
	names.clear();
	names.insert(names.cbegin(), 10, "Hiya!");
	for(const auto &s : names)
		std::cout << s << endl;
	
	names.assign(8, "Hi, Jason!");
	for(const auto &s : names)
		std::cout << s << endl;
	
	return 0;
}