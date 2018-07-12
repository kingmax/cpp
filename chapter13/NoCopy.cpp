#include <iostream>
using namespace std;

class NoCopy
{
public:
	NoCopy() = default;
	NoCopy(const NoCopy&) = delete;
	NoCopy& operator = (const NoCopy&) = delete;
	~NoCopy() = default;
};

int main()
{
	NoCopy n;
	NoCopy n2(n); //error
	NoCopy n3 = n; //error
	
	return 0;
}