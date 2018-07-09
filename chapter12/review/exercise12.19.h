#ifndef __EXERCISE1219_H__
#define __EXERCISE1219_H__

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
using std::vector;
using std::string;

class StrBlobPtr;

class StrBlob
{
public:
	typedef vector<string>::size_type size_type;
	//using size_type = vector<string>::size_type;
	friend class StrBlobPtr;
	
	StrBlobPtr begin();
	StrBlobPtr end();
	
	/* StrBlobPtr begin(){ return StrBlobPtr(*this); }
	StrBlobPtr end(){ return StrBlobPtr(*this, data->size()); } */
	
	StrBlob() : data(std::make_shared<vector<string>>()){}
	StrBlob(std::initializer_list<string> il) : data(
		std::make_shared<vector<string>>(il)){}
		
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &s){ data->push_back(s); }
	
	void pop_back()
	{
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}
	
	string& front()
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}
	
	string& back()
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}
	
	const string& front() const
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}
	
	const string& back() const
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}
	
private:
	std::shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const
	{
		if(i >= data->size())
			throw std::out_of_range(msg);
	}
};

class StrBlobPtr
{
public:
	StrBlobPtr() : curr(0){}
	StrBlobPtr(StrBlob &a, size_t sz=0) : wptr(a.data), curr(sz){}
	
	bool operator != (const StrBlobPtr &p)
	{
		return p.curr != curr;
	}
	
	string& deref() const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	
	StrBlobPtr& incr()
	{
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
	}
	

	
private:
	std::weak_ptr<vector<string>> wptr;
	size_t curr;
	
	std::shared_ptr<vector<string>> check(size_t i, const string &msg) const
	{
		auto ret = wptr.lock();
		if(!ret)
			throw std::runtime_error("unbound StrBlobPtr");
		if(i >= ret->size())
			throw std::out_of_range(msg);
		return ret;
	}
};

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

#endif