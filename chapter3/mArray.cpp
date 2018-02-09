#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int ia[3][4];
	int arr[10][20][30];
	int matrix[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,0,1},
	};
	int matrix2[3][4] = 
	{0,1,2,3, 4,5,6,7, 8,9,0,1};
	int matrix3[3][4] = {{0},{4},{8}}; //{{0,0,0,0}, {4,0,0,0}, {8,0,0,0}}
	int matrix4[3][4] = {0,3,6,9}; //{0,3,6,9, 0,0,0,0, 0,0,0,0}
	
	ia[2][3] = arr[9][19][29];
	ia[0][0] = arr[0][0][0];
	int (&row)[4] = matrix[2]; //reference to matrix last row {8,9,0,1}
	for(int i : row)
		cout << i << ' ';
	cout << endl << endl;
	
	//for init Multi-Array
	for(size_t i=0; i!=3; ++i)
		for(size_t j=0; j!=4; ++j)
			ia[i][j] = i * 4 + j;
	//range for init Multi-Array:
	for(auto &row : ia)
		for(auto &col : row)
			col *= col;
	//range for output Multi-Array	
	for(const auto &row : ia) //Note: using reference else compile to ptr point to array!!!
	{
		for(const auto col : row)
			cout << col << ", ";
		cout << endl;
	}
	
	//Multi-Array and ptr
	int ma2[3][4]={}, (*p)[4] = ma2; //ptr point to int[][4]
	p = &ma2[2]; //now point to last row of ma2
	int *p2[4]; //4 ptr array, every ptr point to int!
	
	//ptr by using auto
	for(auto p = ma2; p != ma2 + 3; ++p)
	{
		for(auto q = *p; q != *p + 4; ++q)
			cout << *q << ' ';
		cout << endl;
	}
	
	//ptr by using begin, end function
	for(auto p = begin(matrix); p != end(matrix); ++p)
	{
		for(auto q = begin(*p); q != end(*p); ++q)
		{
			(*q)++;
			cout << *q << ' ';
		}
		cout << endl;
	}
	
	//using alias
	using int_array = int[4];
	typedef int int_array2[4]; //same as int_array
	for(int_array *p = matrix; p != matrix + 3; ++p)
	{
		for(int *q = *p; q != *p + 4; ++q)
			cout << *q << ' ';
		cout << endl;
	}
	cout << endl;
	for(int_array2 *p = matrix; p != matrix + 3; ++p)
	{
		for(int *q = *p; q != *p + 4; ++q)
			cout << *q << ' ';
		cout << endl;
	}
	
	return 0;
}