#include <memory>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	allocator<string> alloc;
	auto const p = alloc.allocate(10);
	
	auto q = p; //q is just a pointer for move
	
	cout << q << endl; //address
	
	//alloc.construct(p++, "hello"); //error, p is const cannot change(move)
	alloc.construct(q++, 10, 'c');
	alloc.construct(q++, "hi");
	alloc.construct(q++);
	
	cout << q << endl;	//address after moved
	
	cout << p << *p << endl;
	cout << *(p + 1) << endl;
	cout << *(p + 2) << endl;
	//cout << *q << endl; //error, q is not construct!
	while(q != p)
		alloc.destroy(--q);	//destroy object
	//cout << p << *p << endl; //is null
	
	alloc.deallocate(p, 10); //release memory
	
	///////////////////////////////////////////
	vector<int> vi = {1,2,3,4,5};
	allocator<int> ai;
	auto pi = ai.allocate(vi.size() * 2);
	auto qi = uninitialized_copy(vi.begin(), vi.end(), pi); //copy to pi, return a pointer at last constructed element
	cout << pi << ' ' << qi << endl;
	cout << *pi << ' ' << *qi << endl;
	//uninitialized_fill_n(qi, vi.size(), 100);
	qi = uninitialized_fill_n(qi, vi.size(), 100); //others is 100, set qi point to the last
	cout << *qi << endl;
	cout << *pi << endl;
	cout << pi << ' ' << qi << endl;
	while(qi != pi)
		cout << *(--qi) << ' ';
	cout << endl;
	
	cout << "qi == pi ? " << (qi == pi ? "True" : "False") << endl;
	
	qi += 10;
	while(qi != pi)
		ai.destroy(--qi);
	ai.deallocate(pi, 10);
	
	return 0;
}