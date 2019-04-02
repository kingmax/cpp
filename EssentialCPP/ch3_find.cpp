#include <iostream>
#include <string>
#include <vector>
using namespace std;

// int *find(const vector<int> &vec, int value) // Error, const cann't cast to non const
/* const int *find(const vector<int> &vec, int value)
{
	for(int i = 0; i < vec.size(); ++i)
		if(value == vec[i])
			return &(vec[i]);
		
	return 0;
} */

template<typename T>
const T* find(const vector<T> &vec, const T &value)
{
	for(int i = 0; i < vec.size(); ++i)
		if(value == vec[i])
			return &vec[i];
		
	return 0;
} 

int main()
{
	vector<int> v{1,2,3,4,5,6};
	int x = 5;
	const int *p = find(v, x);
	if(p)
		cout << "find value:" << x << ", address:" << p << endl;
	
	vector<string> vs{"a", "b"};
	string s = "c";
	const string *ps = find(vs, s);
	if(ps)
		cout << "find string:" << s << ", address:" << ps << endl;
	else
		cout << "not find string:" << s << ", " << ps << endl;
	
	return 0;
}
