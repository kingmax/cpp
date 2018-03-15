#include "exercise12_2.h"
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class StrBlobPtr
{
	private:
		shared_ptr<vector<string>> check(size_t, const string&) const;
		
		weak_ptr<vector<string>> wptr;
		size_t curr;
		
	public:
		StrBlobPtr() : curr(0) {}
		StrBlobPtr(StrBlob &a, size_t sz=0) : wptr(a.data), curr(sz) {}
		
		string &deref() const;
		StrBlobPtr &incr();
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();
	if(!ret)
		throw runtime_error("unbound StrBlobPtr");
	if(i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

string &BlobStrPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr]; //vector<string>[index]
}

StrBlobPtr &StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

int main()
{
	
	
	return 0;
}