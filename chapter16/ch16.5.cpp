#include <iostream>
#include <string>
using namespace std;

template <typename Array> void print(const Array &arr)
{
	for(const auto &item : arr)
		cout << item << endl;
}

int main()
{
	int numbers[] = {1,3,5,7,9};
	char chars[]{'A', 'B'};
	string words[]{"a", "b", "cc"};
	
	print(numbers);
	cout << endl;
	print(chars);
	cout << endl;
	print(words);
	
	return 0;
}