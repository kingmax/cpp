#include "exercise12_19.h"

StrBlob::StrBlob() : 
		data(std::make_shared<vector<string>>())
		{}
		
StrBlob::StrBlob(std::initializer_list<string> il) :
		data(std::make_shared<vector<string>>(il))
		{}

void StrBlob::check(StrBlob::size_type sz, const string &msg) const
{
	if( sz >= data->size() )
		throw std::out_of_range(msg);
}
		
StrBlob::size_type StrBlob::size() const
{
	return data->size();
}

bool StrBlob::empty() const
{
	return data->empty();
}

string &StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

const string &StrBlob::front() const
{
	check(0, "const front on empty StrBlob");
	return data->front();
}

string &StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

const string &StrBlob::back() const
{
	check(0, "const back on empty StrBlob");
	return data->back();
}

void StrBlob::push_back(const string &s)
{
	data->push_back(s);
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

//////////////////////////////////////////////////////////////
StrBlobPtr::StrBlobPtr() :
		curr(0)
		{}
		
StrBlobPtr::StrBlobPtr(StrBlob &s, std::size_t i) :
		wptr(s.data), curr(i)
		{}
		
std::shared_ptr<vector<string>> StrBlobPtr::check(std::size_t curr, const string &msg) const
{
	auto p = wptr.lock();
	if(!p)
		throw std::runtime_error("unbound StrBlobPtr");
	if(curr >= p->size())
		throw std::out_of_range(msg);
	return p;
}

string &StrBlobPtr::deref() const
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

bool StrBlobPtr::operator!=(StrBlobPtr &p)
{
	return p.curr != curr;
}