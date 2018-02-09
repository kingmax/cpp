#include <iostream>
using namespace std;

int main()
{
	int ia[3][4] = {
		{12, 11, 10, 9},
		{8,   7,  6, 5},
		{4,   3,  2, 1}
	};
	
	//output
	//range for version:
	for(int (&row)[4] : ia)
	{
		for(int col : row)
			cout << col << ' ';
		cout << endl;
	}
	cout << endl;
	
	//for version:
	for(size_t row = 0; row < 3; ++row)
	{
		for(size_t col = 0; col < 4; ++col)
			cout << ia[row][col] << ' ';
		cout << endl;
	}
	cout << endl;
	
	//for version2:
	for(int (*p)[4] = ia; p != ia + 3; ++p)
	{
		for(int *q = *p; q != *p + 4; ++q)
			cout << *q << ' ';
		cout << endl;
	}
	cout << endl;
	
	//3.44
	//type alias
	using int4_arr = int[4];
	for(int4_arr *row = ia; row != ia + 3; ++row)
	{
		for(int col : *row)
			cout << col << ' ';
		cout << endl;
	}
	cout << endl;	

	typedef int int4_Arr[4];
	for(int4_Arr *p = ia; p != end(ia); ++p)
	{
		//for(int *q = begin(*p); q != end(*p); ++q)
		for(int *q = *p; q != end(*p); ++q)
			cout << *q << ' ';
		cout << endl;
	}
	cout << endl;
	
	//3.45
	//reference
	for(const auto &row : ia)
	{
		for(const auto col : row)
			cout << col << ' ';
		cout << endl;
	}
	cout << endl;
	
	//ptr
	for(auto p = ia; p != end(ia); ++p)
	{
		for(auto q = *p; q != end(*p); ++q)
			cout << *q << ' ';
		cout << endl;
	}
	cout << endl;
	
	//ptr
	for(auto p = begin(ia); p != end(ia); ++p)
	{
		for(auto q = begin(*p); q != end(*p); ++q)
			cout << *q << ' ';
		cout << endl;
	}
	cout << endl;
	
	//ptr
	for(auto p = ia; p != ia + 3; ++p)
	{
		for(auto q = *p; q != *p + 4; ++q)
			cout << *q << ' ';
		cout << endl;
	}
	
	return 0;
}