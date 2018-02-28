#include <iostream>
#include <array>
using namespace std;

int main()
{
	array<int, 18> a1;
	array<string, 10> a2;
	
	array<int, 18>::size_type sz;
	
	array<int, 10> a3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	array<int, 10> a4 = {100}; //first element is 100, others are 0;
	
	array<int, 10> copy = a3;
	cout << copy.size() << endl;
	for(const auto &x : copy)
		cout << x << ' ';
	cout << endl;
	
	int digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	//int cp[10] = digits; //error!!
	
	return 0;
}