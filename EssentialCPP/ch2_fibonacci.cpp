#include <iostream>
#include <cstdlib>
#include <string>
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

bool print_sequence(int pos)
{
	if(pos <= 0 || pos > 1024)
	{
		cerr << "invalid position: " << pos
			 << " -- cannot handle request!\n";
		return false;
	}
	
	cout << "The Fibonacci Sequence for " << pos
		 << " positions: \n\t";
	
	// 无论pos是多少都会输出1 1, 除了pos==1
	// 因为有default, 且没有被break!
	switch(pos)
	{
		default:
		case 2:
			cout << "1 ";
			// No break here, so go down..
		case 1:
			cout << "1 ";
			break;
	}
	
	int elem;
	int n2 = 1, n1 = 1;
	for(int i = 3; i <= pos; ++i)
	{
		elem = n2 + n1;
		n2 = n1;
		n1 = elem;
		cout << elem << (!(i % 10) ? "\n\t" : " ");
	}
	cout << endl;
	
	return true;
}

void print_msg(ostream &os, const string &msg)
{
	if(msg.empty())
		return;
	
	os << msg;
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
			
	cout << endl;
	print_sequence(pos);
	
	print_msg(cout, "hello, function");
	
	return 0;
}