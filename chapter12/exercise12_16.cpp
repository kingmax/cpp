#include <iostream>
#include <memory>
using namespace std;

int main()
{
	//unique_ptr<int> up = new int(100); //error, cannot copy
	unique_ptr<int> up(new int(100));
	unique_ptr<int> up2(new int(200));
	
	cout << *up << ' ' << *up2 << endl;
	//up = up2; //error
	
	up.reset(up2.release());
	cout << *up << ' ' ;//<< *up2 << endl;
	
	//exercise12.17
	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	typedef unique_ptr<int> IntP;
	
	//IntP p0(ix); //error, new ptr or nullptr
	//IntP p1(pi); //error, new ptr
	IntP p2(pi2);
	cout << *p2 << endl;
	cout << *pi2 << endl;
	
	//IntP p3(&ix); //error, new ptr
	IntP p4(new int(2048));
	cout << *p4 << endl;
	
	IntP p5(p2.get()); //WARNING!!!
	cout << "----------------" << endl;
	cout << *p5 << endl; //2048
	cout << *p2 << endl; //2048
	
	*p5 = 100;
	cout << "----------------" << endl;
	cout << *p5 << endl; //100
	cout << *p2 << endl; //100
	
	return 0;
}

unique_ptr<int> clone(int p)
{
	return unique_ptr<int>(new int(p));
}

unique_ptr<int> clone2(int p)
{
	unique_ptr<int> ret(new int(p));
	return ret;
}