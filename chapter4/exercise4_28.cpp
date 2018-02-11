#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cout << "sizeof bool:\t" << sizeof(bool) << endl;					//1
	cout << endl;
	
	cout << "sizeof char:\t" << sizeof(char) << endl;					//1
	//byte
	cout << "sizeof unsigned char:\t" << sizeof(unsigned char) << endl;	//1
	cout << "sizeof wchar_t:\t" << sizeof(wchar_t) << endl;				//2
	cout << "sizeof char16_t:\t" << sizeof(char16_t) << endl;			//2
	cout << "sizeof char32_t:\t" << sizeof(char32_t) << endl;			//4
	cout << endl;
	
	//signed and unsigned have same words 
	//bytes <= 2 ** (words * 2 - 1), eg:
	//char.words = 1, short.bytes = 2 ** (8 * 1 -1) = 2 ** 7 = 128 (range: -128~127)
	cout << "sizeof short:\t"	<< sizeof(short) << endl;				//2
	cout << "sizeof unsigned short:\t" << sizeof(unsigned short) << endl;//2
	cout << "sizeof int:\t" << sizeof(int) << endl;						//4
	cout << "sizeof long:\t" << sizeof(long) << endl;					//4
	cout << "sizeof long long:\t" << sizeof(long long) << endl;			//8
	cout << endl;
	
	cout << "sizeof float:\t" << sizeof(float) << endl;					//4
	cout << "sizeof double:\t" << sizeof(double) << endl;				//8
	cout << "sizeof long double:\t" << sizeof(long double) << endl;		//8
	cout << endl;
	
	//4.29
	int x[10];
	int *p = x;
	cout << sizeof(x) << ' ' << sizeof(*x) << endl; //40 4
	cout << sizeof(x) / sizeof(*x) << endl; // 4 * 10 / 4 = 10
	cout << sizeof(p) << ' ' << sizeof(*p) << endl; //8 4
	cout << sizeof(p) / sizeof(*p) << endl; // 8 / 4 = 2, sizeof(ptr)/sizeof(int)
	cout << endl;
	
	cout << sizeof(&x) << endl; //8
	char c = 'c';
	cout << sizeof(&c) << endl; //8, sizeof(ptr) = 8!!	
	
	//4.32
	constexpr int size = 5;
	int ia[size] = {1,2,3,4,5};
	for(int *ptr = ia, ix = 0; ix != size && ptr != ia + size; ++ix, ++ptr)
	{
		cout << ia[ix] << ' ' << *ptr << endl;
	}
	cout << endl;
	
	vector<int> vi = {1,2,3,4,5};
	vector<int>::size_type cnt = vi.size();
	for(vector<int>::size_type ix = 0; ix != vi.size(); ++ix, --cnt)
		cout << ix << ' ' << cnt << endl;
	cout << endl;
	
	
	return 0;
}