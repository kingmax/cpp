#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vi = {100};
	if(!vi.empty())
	{
		auto v1 = *vi.cbegin();
		auto v2 = vi.front();
		auto v3 = *(--vi.end());
		auto v4 = vi.back();
		cout << "vi.size = " << vi.size() << endl;
		cout << v1 << ' ' << v2 << ' ' << v3 << ' ' << v4 << endl; //100 100 100 100
		
		//exercise 9.24
		int i1 = vi.at(0);
		int i2 = vi[0];
		int i3 = vi.front();
		int i4 = *vi.begin();
		cout << i1 << ' ' << i2 << ' ' << i3 << ' ' << i4 << endl; //100 100 100 100
	}
	
	return 0;
}