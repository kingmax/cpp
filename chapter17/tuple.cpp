#include <iostream>
#include <tuple>
#include <vector>
#include <list>
#include <string>
using namespace std;

int main()
{
	tuple<size_t, size_t, size_t> threeD;
	tuple<string, vector<double>, int, list<int>>
		someValue("constants", {3.14, 2.718}, 100, {0,1,2,3});
		
	auto item = make_tuple("hi, hello", 3, 100.0);
	cout << sizeof("hi") << ' ' << sizeof("hello") << endl;
	cout << sizeof(const char*) << '+' << sizeof(int) << '+' << sizeof(double) << '=' << sizeof(item) << endl;
	
	cout << sizeof(size_t) << '*' << (sizeof(threeD) / sizeof(size_t)) << '=' << sizeof(threeD) << endl;
	
	auto book = get<0>(item);
	auto count = get<1>(item);
	auto price = get<2>(item) / count;
	get<2>(item) *= 0.8;
	cout << book << ' ' << count << ' ' << price << ' ' << get<2>(item) << endl;

	typedef decltype(item) trans;
	size_t sz = tuple_size<trans>::value;
	cout << sz << endl;
	cout << tuple_size<decltype(someValue)>::value << endl;
	
	tuple_element<0, trans>::type s = "string 100";
	tuple_element<1, trans>::type x = 100;
	cout << x << endl;
	cout << get<1>(item) << endl;

	cout << endl;
	tuple<string, string> duo("1", "2");
	tuple<size_t, size_t> twoD(1, 2);
	//bool b = (duo == twoD); //error, defferent type
	tuple<size_t, size_t, size_t> _3D(1, 2, 3);
	//bool b = (twoD < _3D); //error, defferent size
	decltype(twoD) origin(0, 0);
	bool b = (origin < twoD); //true
	cout << b << ' ' << (b ? "True" : "False") << endl;

	return 0;
}