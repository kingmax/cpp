#include <iostream>
#include <cstdlib>
using namespace std;

int fibonacci_element(unsigned n)
{
	if(n <= 0)
		exit(-1);	// or throw new Exception
	
	int result = 1;
	//n == 1 or 2
	if(n < 3)
		return result;
	
	int n1 = 1, n2 = 1;
	for(int i = 3; i <= n; ++i)
	{
		result = n1 + n2;
		n1 = n2;
		n2 = result;
	}
	
	return result;
}

bool fibonacci_element(int pos, int &result)
{
	if( pos <= 0 || pos > 1024)
	{
		result = 0;
		return false;
	}
	
	result = 1;
	int n2 = 1, n1 = 1;
	for(int ix = 3; ix <= pos; ++ix)
	{
		result = n2 + n1;
		n2 = n1;
		n1 = result;
	}
	
	return true;
}

int main()
{
	int pos;
	cout << "Please enter a position: ";
	cin >> pos;
	
	cout << fibonacci_element(pos) << endl;
	
	int elem;
	if(fibonacci_element(pos, elem))
		cout << "element #" << pos
			<< " is " << elem << endl;
	else
		cout << "Sorry, Could not calculate element #"
			<< pos << endl;
	
	return 0;
}