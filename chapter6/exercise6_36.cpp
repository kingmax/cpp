#include <iostream>
#include <string>
#include <vector>
using namespace std;

//using static
string (&func())[10]
{
	static string s[10];
	static string (&ret)[10] = s;
	double d = 0;
	for(auto beg = begin(s); beg != end(s); ++beg)
	{
		*beg = to_string(d++);
	}
	return s; //ret; //s; //(&s)[10];
}

string sa[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
string sb[10];
string (&ra)[10] = sa, (&rb)[10] = sb;
//defined outside, similar to using static
string (&func(int param))[10]
{
	if(param < 0)
		//return ra;
		return sa;
	else
		//return rb;
		return sb;
}

//using reference param
string (&func(string (&arr)[10]))[10]
{
	return arr;
}

//exercise 6.37
typedef int arrIntTen[10]; //an Array contains 10 ints (int[10])
arrIntTen &fun(arrIntTen &ref)
{
	return ref;
}

//reference to int[10] array
using refArr10Ints = int (&)[10];
refArr10Ints funB(refArr10Ints ref)
{
	return ref;
}

//6.37 B:
auto funC(int (&ref)[10]) -> int (&)[10]
{
	return ref;
}

//6.37 C:
//string sa[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
decltype(sa) &funD(decltype(sa) &ref)
{
	return ref;
}

int main()
{
	//set sb (&rb)
	for(int i=0; i<10; ++i)
	{
		sb[i] = to_string(i);
	}
	for(auto i : rb)
		cout << i << ' ';
	cout << endl;
	
	cout << "\nusing static:" << endl;
	string (&arr)[10] = func();
	for(const auto a : arr)
		cout << a << ' ';
	cout << endl;
	
	cout << "\ndefined outside the function (global):" << endl;
	string (&sArr)[10] = func(-1);
	for(auto &s : sArr)
		cout << s << ' ';
	cout << endl;
	
	string (&sArr2)[10] = func(0);
	for(const auto &s : sArr2)
		cout << s << ' ';
	cout << endl;
	
	cout << "\nusing ref param:" << endl;
	string (&sArr3)[10] = func(ra);
	for(auto beg = begin(sArr3); beg != end(sArr3); ++beg)
		cout << *beg << ' ';
	cout << endl;
	
	//6.37
	cout << "\nexercise 6.37:" << endl;
	int x = 100, iArr[10];
	for(auto last = end(iArr)-1; last >= begin(iArr); --last)
		*last = (x -= 10);
	
	cout << "\ntesting" << endl;
	arrIntTen &refArr = fun(iArr);
	for(auto x : refArr)
		cout << x << ' ';
	cout << endl;
	
	cout << "\nrefArr10Ints:" << endl;
	refArr10Ints r = iArr;
	refArr10Ints r2 = funB(iArr);
	//output from last to begin:
	for(auto last = end(r2)-1; last >= begin(r2); --last)
		cout << *last << ' ';
	cout << endl;
	
	//auto
	cout << "\nusing auto funC(int (&ref)[10]) -> int(&)[10]:" << endl;
	
	auto ret = funC(iArr); //return ptr point to array, cann't using for(auto x : ret)!!!
	for(int i=0; i!=10; ++i)
		cout << ret[i] << ' ';
	cout << endl;
	auto &ret2 = funC(iArr);
	 for(auto x : ret2)
		cout << x << ' '; 
	cout << endl;
	
	cout << "\nusing decltype:" << endl;
	decltype(sa) &refSA = funD(sa);
	for(auto x : refSA)
		cout << x << ' ';
	cout << endl;
	
	return 0;
}