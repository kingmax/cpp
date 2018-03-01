#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec = {1,2,3,4,5};
	if(!vec.empty())
	{
		auto v1 = *vec.cbegin(), v2 = vec.front();
		cout << v1 << ' ' << v2 << endl; //1 1
		auto last = vec.cend();
		auto v3 = *(--last);
		auto v4 = vec.back();
		cout << v3 << ' ' << v4 << endl; //5 5
		
		cout << vec.at(0) << endl; //1
		
		vec.front() = 100; //front, back, at, [] return reference!
		auto &v = vec.back();
		v = 1024;
		vec.at(1) *= 2; //2*2
		vec[2] = 10;
		for(const auto i : vec)
			cout << i << ' ';
		cout << endl;
		
		//cout << vec.at(100) << endl; //out_of_range error 
	}
	
	return 0;
}