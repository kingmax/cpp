#pragma once

#include <vector>
#include <string>
#include <initializer_list>
#include <memory> //shared_ptr

template<typename T>
class Blob
{
public:
	typedef T value_type;
	// ref: http://feihu.me/blog/2014/the-origin-and-usage-of-typename/
	typedef typename std::vector<T>::size_type size_type;
	
	Blob();
	Blob(std::initializer_list<T> il);
	
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();
	
	T& back();
	T& operator[](size_type i);
	
private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string &msg) const;
};
