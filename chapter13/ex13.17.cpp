#include <iostream>
using namespace std;

static int n;

class Numbered
{	
public:
	int mysn;
	
	Numbered()
	{
		++n;
		mysn = n;
	}
	
	Numbered(const Numbered &orig) : mysn(++n)
	{}
};

void f(Numbered s)
{
	cout << s.mysn << endl;
}

void f2(const Numbered& s)
{
	cout << s.mysn << endl;
}

int main()
{
	
	Numbered a, b=a, c=b;
	f(a);
	f(b);
	f(c);
	
	cout << endl;
	f2(a);
	f2(b);
	f2(c);
	
	return 0;
}