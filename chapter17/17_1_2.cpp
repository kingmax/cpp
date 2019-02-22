#include <iostream>
#include <tuple>
#include <string>
#include <vector>
using namespace std;

int main()
{
	//17.1
	tuple<int, int, int> a(10, 20, 30);
	cout << tuple_size<decltype(a)>::value << endl;
	
	tuple<string, vector<string>, pair<string, int>> b("str", {"vec", "vector<string>"}, {"one", 1});
	cout << tuple_size<decltype(b)>::value << endl;
	auto p = get<2>(b);
	cout << '(' << p.first << ':' << p.second << ')' << endl;
	
	return 0;
}