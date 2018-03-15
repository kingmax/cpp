#include <iostream>
#include <memory>
using namespace std;

int main()
{
	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	typedef unique_ptr<int> IntP;
	
	//IntP p0(ix); //error, not pointer
	//IntP p1(pi); //error, not new pointer
	IntP p2(pi2);
	cout << *p2 << endl;
	
	//IntP p3(&ix); //error, not new pointer
	IntP p4(new int(4096));
	cout << *p4 << endl;
	
	IntP p5(p2.get()); //WARNING, don't using this!
	cout << *p5 << ' ' << (p2 ? "not nullptr" : "nullptr") << endl;
	
	IntP p6 = p2; //error
	
	return 0;
}