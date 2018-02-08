#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vi;
	for(int i=0; i<100; ++i)
		vi.push_back(i*i);
	for(auto i : vi)
		cout << i << ' ';
	cout << endl;
	
	int sought = 88 * 88;
	auto beg = vi.begin(), end = vi.end();
	auto mid = beg + (end - beg) / 2;
	while(mid != end && *mid != sought)
	{
		if(sought < *mid)
			end = mid;
		else
			beg = mid + 1;
		mid = beg + (end - beg) / 2;
	}
	
	
	return 0;
}