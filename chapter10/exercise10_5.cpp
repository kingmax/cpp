#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	//equal
	vector<string> roster1 = {"jason", "lee"};
	vector<string> roster2 = {"jason", "lee"};
	
	cout << equal(roster1.cbegin(), roster1.cend(), roster2.cbegin()) << endl; //1, equals
	
	vector<char *> v1 = {"jason", "lee"};
	vector<char *> v2 = {"jason", "lee"};
	cout << equal(v1.cbegin(), v1.cend(), v2.cbegin()) << endl; //0, not equals, because pointer is address!!!
	
	return 0;
}