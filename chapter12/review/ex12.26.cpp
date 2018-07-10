#include <memory>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	allocator<string> alloc;
	auto *const ps = alloc.allocate(10);
	string s;
	auto qs = ps;
	while(cin >> s && qs != ps + 10)
		alloc.construct(qs++, s);
	
	const size_t size = qs - ps;
	cout << "You input " << size << " word(s)" << endl;
	
	while(qs != ps)
		cout << *(--qs) << endl;
	
	qs += size;
	while(qs != ps)
		alloc.destroy(--qs);
	
	alloc.deallocate(ps, 10);
	
	return 0;
}