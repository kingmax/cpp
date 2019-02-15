#pragma once
#include <memory>
#include <vector>
#include <string>

// forward declare
template <typename T> class BlobPtr;

template<typename T>
class Blob
{
	friend class BlobPtr<T>; // so, the ptr can access Blob private data!
	
public:
	typedef typename std::vector<T>::size_type size_type;
	
	// constructor
	Blob();
	Blob(std::initializer_list<T> il);
	
	// number of elements
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	
	void push_back(const T& t) { data->push_back(t); }
	void push_back(T&& t) { data->push_back(std::move(t)); }
	void pop_back();
	
	// element access
	T& back();
	T& operator[](size_type i);
	const T& back() const;
	const T& operator[](size_type i) const;
	
private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string &msg) const;
};

// Constructor
template<typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>())
{}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) :
	data(std::make_shared<std::vector<T>>(il))
	{}

template<typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
	if(i >= data->size())
		throw std::out_of_range(msg);
}

template<typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template<typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
const T& Blob<T>::back() const
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
T& Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
const T& Blob<T>::operator[](size_type i) const
{
	check(i, "subscript out of range");
	return (*data)[i];
}
