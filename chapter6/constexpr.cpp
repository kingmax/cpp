#include <iostream>
using namespace std;

constexpr int new_sz()
{
	return 42;
}

constexpr size_t scale(size_t cnt)
{
	return new_sz() * cnt;
}

int main()
{
	constexpr int foo = new_sz();
	cout << foo << endl;
	
	const size_t sc = scale(10);
	cout << sc << endl;
	
	int arr[scale(2)]; //ok
	cout << arr << endl;
	
	int x = 2;
	//int arr2[x]; //error
	//int arr3[scale(x)]; //error
	
	return 0;
}