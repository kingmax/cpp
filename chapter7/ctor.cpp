#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ConstRef
{
	public:
		ConstRef(int ii);
		ostream& print(ostream&) const;
		
	private:
		int i;
		const int ci;
		int &ri; //reference to i
};

ConstRef::ConstRef(int ii) : i(ii), ci(ii*2), ri(i){}
ostream &ConstRef::print(ostream &os) const
{
	os << "i = " << i << " ci=" << ci << " ri = " << ri
		<< "\n" << &i  << "\t" << &ci << "\t" << &ri;
	return os;
}

int main()
{
	ConstRef cr(100);
	
	cr.print(cout) << endl;
	
	return 0;
}