#pragma once
#include <memory>
#include <vector>

template<typename T>
class Blob
{
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
	
	
};