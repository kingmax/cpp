#include "StrBlob.h"
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

//cl /EHsc StrBlob2.cpp StrBlobPtr2.cpp exercise12.22.cpp /Fe:exercise12.22.exe

int main()
{
	cout << "\n----> exercise12.22" << endl;
	StrBlob sb({"hello, StrBlob", "exercise12.22", "the last line"});
	
	cout << sb.size() << endl;
	cout << sb.empty() << endl;
	cout << sb.front() << endl;
	const string& front = sb.front();
	cout << front << endl;
	
	cout << sb.back() << endl;
	sb.pop_back();
	cout << sb.back() << endl;
	cout << sb.size() << endl;
	
	sb.push_back("last");
	
	auto print = [](const string& s){ cout << " " << s; };
	//for_each(sb.begin(), sb.end(), print);
	
	const StrBlob cs({"hello", u8"const", u8"你好"});
	cout << cs.size() << endl;
	cout << cs.back() << endl;
	
	return 0;
}