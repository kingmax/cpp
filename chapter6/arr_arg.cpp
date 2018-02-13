#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(const char *p)
{
	if(p)
		while(*p)
			cout << *p++;
}

void print(const int *begin, const int *end)
{
	while(begin != end)
		cout << *begin++ << endl;
}

void print(const int ia[], size_t size)
{
	for(size_t i=0; i != size; ++i)
		cout << ia[i] << endl;
}

void print(int (&arr)[10])
{
	for(auto elem : arr)
		cout << elem << endl;
}

int main()
{
	char cs[] = "hi, jason!";
	print(cs);
	cout << endl;
	
	int arr[] = {1,2,3,4,5,6,7,8};
	print(arr, end(arr));
	
	cout << endl;
	print(arr, sizeof(arr)/sizeof(int));
	print(arr, end(arr)-begin(arr));
	
	cout << endl;
	int arr2[] = {10,9,8,7,6,5,4,3,2,1};
	print(arr2);
	
	return 0;
}