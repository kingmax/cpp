#include <iostream>
#include <string>
using namespace std;

int main()
{
	unsigned cnt = 42;
	constexpr unsigned sz = 42;
	int arr[10];
	int *ptr[sz];
	//string bad[cnt]; //error, must be const
	//string strs[get_size()]; //ok if get_size is constexpr else error
	
	const unsigned size=3;
	int a1[size] = {0, 1, 2};
	int a2[] = {0, 1, 2};
	int a3[5] = {0, 1, 2}; //other 2 element init to 0
	string a4[3] = {"hi", "bye"}; //{"hi", "bye", ""}
	//int a5[2] = {1,2,3}; //error, values too much
	
	char s1[] = {'C', '+', '+'}; //len = 3
	char s2[] = {'C', '+', '+', '\0'}; //end null char
	char s3[] = "C++"; //same as s2, len=4, contains '\0'!
	//const char s4[6] = "Daniel"; //error, no '\0' position, s4[7] ok
	
	int *ptrs[10]; //10 ptr point to int
	//int &ptrs[10] = arr; //error
	int (*ptrArray)[3] = &a1; //ptr point to array contains 3 int
	int (&refArray)[3] = a1; //reference to array contains 3 int
	for(int i=0; i<3; ++i)
		refArray[i] *= 2;
	for(auto i : a1)
		cout << i << ' ';
	cout << endl;
	int i = 0;
	while(i < 3)
	{
		cout << (*ptrArray)[i++] << endl;
		//++i;
	}
	
	int (*ptr2)[10] = nullptr; //a ptr point to an array (int array[10])
	
	unsigned scores[11] = {}; //init every element to 0;
	unsigned grade;
	while(cin >> grade)
		if(grade <= 100)
			++scores[grade/10];
	for(auto s : scores)
		cout << s << ' ';
	cout << endl;
	
	return 0;
}