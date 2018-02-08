#include <iostream>
#include <vector>
using namespace std;

int main()
{
	const int cnt = 10;
	int arr[cnt];
	cout << "un-init array" << endl;
	for(int i : arr)
		cout << i << ' ';
	cout << endl;
	
	int *p = arr, index=0;
	while(index != cnt)
	{
		*(p++) = 0;
		++index;
	}
	for(int i : arr)
		cout << i << ' ';
	cout << endl;
	
	int *b = arr, *e = end(arr);
	while(b < e)
		*(b++) = 100;
	for(int i : arr)
		cout << i << ' ';
	cout << endl;
	
	//compare 2 array
	int arr_a[3] = {1,2,3};
	int arr_b[5] = {1,2,3,4,5};
	int arr_c[5] = {1,2,4,4,5}; //{1,2,3,4,6};
	int *a_begin = begin(arr_a), *a_end = end(arr_a);
	int *b_begin = begin(arr_b), *b_end = end(arr_b);
	int *c_begin = begin(arr_c), *c_end = end(arr_c);
	int len_a = a_end - a_begin;
	int len_b = b_end - b_begin;
	int len_c = c_end - c_begin;
	if(len_a != len_b)
		cout << "arr_a != arr_b, len(arr_a)=" << len_a << ", len(arr_b)="
			 << len_b << endl;
			 
	bool found = false;
	if(len_b != len_c)
	{
		cout << "arr_b != arr_c" << endl;
		found = true;
	}
	else
	{
		while(b_begin < b_end)
		{
			if(*b_begin != *c_begin)
			{
				cout << "arr_b != arr_c, diff:" << *b_begin << " <> " << *c_begin << endl;
				found = true;
				break;
			}
			++b_begin;
			++c_begin;
		}
	}
	if(!found)
		cout << "arr_b == arr_c" << endl;
	
	//compare 2 vector
	bool diff = false;
	vector<int> va = {1,2,3,4,5};
	vector<int> vb = {1,2,3,4,5,}; //{1,2,3,5,4};
	if(va.size() != vb.size())
	{
		cout << "va != vb, size difference!" << endl;
		diff = true;
	}
	else
	{
		for(auto va_b = va.cbegin(), va_e = va.cend(), vb_b = vb.cbegin();
			va_b != va_e; ++va_b, ++vb_b)
		{
			if(*va_b != *vb_b)
			{
				cout << "va != vb, diff: " << *va_b << "<>" << *vb_b << endl;
				diff = true;
				break;
			}
		}
	}
	if(!diff)
		cout << "va == vb" << endl;
	
	return 0;
}