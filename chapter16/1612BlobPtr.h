#pragma once
#include "1612Blob.h"
#include <string>
#include <memory>
#include <vector>

// forward declare
template<typename> class BlobPtr;

/*
template<typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template<typename T>
bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
*/

template<typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	if(lhs.wptr.lock() != rhs.wptr.lock())
		throw runtime_error("wptrs to different Blobs!");
	return lhs.i == rhs.i;
}

template<typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	if(lhs.wptr.lock() != rhs.wptr.lock())
		throw runtime_error("wptrs to different Blobs!");
	return lhs.i < rhs.i;
}

template<typename T>
class BlobPtr
{
	// == and < 后面不带<T>似乎也行？反正编译是能过
	friend bool operator==<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
	friend bool operator< <T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
	
public:
	BlobPtr() : curr(0){}
	BlobPtr(Blob<T>& a, std::size_t sz=0) :
		wptr(a.data), curr(sz)
		{}
		
	T& operator*() const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	
	// prefix
	BlobPtr& operator++();
	BlobPtr& operator--();
	// postfix
	BlobPtr operator++(int);
	BlobPtr operator--(int);
	
private:
	std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};

template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check
	(std::size_t i, const std::string &msg) const
{
	//ref: chapter12/weak_ptr.cpp
	auto ret = wptr.lock();
	
	if(!ret)
		throw std::runtime_error("unbound BlobPtr");
	
	if(i >= ret->size())
		throw std::out_of_range(msg);
	
	return ret;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "increment past end of StrBlob");
	++curr;
	return *this;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	check(curr, "decrement past begin of BlobPtr");
	--curr;
	return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	BlobPtr ret = *this;
	++*this;
	return ret;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
	BlobPtr ret = *this;
	--*this;
	return ret;
}

/*
template<typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	if(lhs.wptr.lock() != rhs.wptr.lock())
		throw runtime_error("wptrs to different Blobs!");
	return lhs.i == rhs.i;
}

template<typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	if(lhs.wptr.lock() != rhs.wptr.lock())
		throw runtime_error("wptrs to different Blobs!");
	return lhs.i < rhs.i;
}
*/