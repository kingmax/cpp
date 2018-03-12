#include <stack>
#include <iostream>
using namespace std;

int main()
{
	stack<int> intStack;
	for(size_t ix = 0; ix != 10; ++ix)
	{
		intStack.push(ix);
	}
	
	cout << intStack.size() << endl;
	while(!intStack.empty())
	{
		int value = intStack.top();
		cout << value << ' ';
		intStack.pop();
	}
	cout << endl << intStack.size() << endl;
	
	return 0;
}