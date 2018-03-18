//#include "StrBlobPtr.h"
#include "StrBlob.h"  //in B.cpp only include A.h

StrBlobPtr::StrBlobPtr() : curr(0) {}

StrBlobPtr::StrBlobPtr(StrBlob &s, std::size_t i) : wptr(s.data), curr(i)
{
}

StrBlobPtr::~StrBlobPtr() {}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t n, const std::string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (n >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

std::string &StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}