#pragma once
#include "1612Blob.h"
#include <string>
#include <memory>
#include <vector>

// forward declare
template<typename> class BlobPtr;

template<typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template<typename T>
bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);


template<typename T>
class BlobPtr
{
	friend bool operator==<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
	friend bool operator<<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
	
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

