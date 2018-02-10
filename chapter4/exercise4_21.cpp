#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int> vi = {1,2,3,4,5,6,7,8};
	for(auto i : vi)
		cout << i << ' ';
	cout << endl;
	
	for(int &i : vi)
	{
		(i % 2 != 0) ? (i *=2) : i;
	}
	for(auto i : vi)
		cout << i << ' ';
	cout << endl;
	
	
	int scores[10] = {50, 66, 89, 72, 38, 99, 100, 100, 98, 89};
	string grade="";
	for(int i : scores)
	{
		grade = (i > 90) ? "high pass" : ( i > 75 && i <= 90 ? "pass" : ( i > 60 && i <= 75 ? "low pass" : "fail"));
		cout << i << ":\t" << grade << endl;
	}
	cout << endl;
	
	return 0;
}