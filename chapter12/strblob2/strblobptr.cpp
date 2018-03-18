//#include "strblobptr.h"
#include "strblob.h"	//in B.cpp just include A.h, since A.h always included B.h

/* private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
	
public:
	StrBlobPtr();
	StrBlobPtr(StrBlob&, std::size_t);
	
	std::string &deref() const;
	StrBlobPtr &incr(); */
	
StrBlobPtr::StrBlobPtr() : curr(0){}

StrBlobPtr::StrBlobPtr(StrBlob &s, std::size_t sz/*  = 0 */) : 
			wptr(s.data), curr(sz)
			{}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t sz, const std::string &msg) const
{
	auto ret = wptr.lock();
	if(!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if( sz >= ret->size() )
		throw std::out_of_range(msg);
	return ret;
}

std::string &StrBlobPtr::deref() const
{
	auto p = check(curr, "derefrence past end");
	return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

bool StrBlobPtr::operator != (const StrBlobPtr &p)
{
	return p.curr != curr;
}