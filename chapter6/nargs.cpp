#include <iostream>
#include <string>
#include <vector>
using namespace std;

void error_msg(initializer_list<string> il)
{
	for(auto beg = il.begin(); beg != il.end(); ++beg)
		cout << *beg << ' ';
	cout << endl;
}

void error_msg(int err_code, initializer_list<string> il)
{
	cout << "Error Code:" << err_code << endl;
	error_msg(il);
}

//void foo(parm_list, ...);
//using cstd::varargs, for C++ access some C code!
void foo(...){};

int main()
{
	initializer_list<string> ls = {"arg1", "arg2", "arg3", "arg4"};
	cout << ls.size() << endl;
	/* for(auto beg = ls.begin(); beg != ls.end(); ++beg)
		cout << *beg << ' ';
	cout << endl; */
	error_msg(ls);
	
	error_msg({"a"});
	error_msg({"a", "b"});
	error_msg({"a", "b", "c"});
	
	error_msg(-1, {"failed"});
	error_msg(0, {"ok", "success"});
	
	
	return 0;
}