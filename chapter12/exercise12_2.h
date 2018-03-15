#ifndef __EXERCISE12_2_H__
#define __EXERCISE12_2_H__

#include <string>
#include <vector>
#include <memory>

class BlobStr
{
	public:
		using size_type = std::vector<std::string>::size_type;
		
	private:
		std::shared_ptr<std::vector<std::string>> data;
		void check(size_type, const std::string &) const;
	
	public:
		BlobStr();/*  = default; */
		//Note if explicit then cannot do:   BlobStr b = {"x", "y"}; 
		//explicit constructor only do this: BlobStr b{"x", "y"};
		//explicit only used for one param constructor!!!
		explicit BlobStr(std::initializer_list<std::string> il);
		
		bool empty() const {return data->empty();}
		size_type size() const {return data->size();}
		
		std::string &front();
		const std::string &front() const;
		std::string &back();
		const std::string &back() const;
		
		void push_back(const std::string &s){data->push_back(s);}
		void pop_back();
};

BlobStr::BlobStr() : data(std::make_shared<std::vector<std::string>>())
{
	/* data = std::make_shared<std::vector<std::string>>(); */
}

BlobStr::BlobStr(std::initializer_list<std::string> il) /* : data(std::make_shared<std::vector<std::string>>(il)) */
{
	data = std::make_shared<std::vector<std::string>>(il);
}

void BlobStr::check(size_type i, const std::string &msg) const
{
	if(i >= data->size())
		throw std::out_of_range(msg);
}

std::string &BlobStr::front()
{
	check(0, "front on empty BlobStr");
	return data->front();
}

const std::string &BlobStr::front() const
{
	check(0, "const front on empty BlobStr");
	return data->front();
}

std::string &BlobStr::back()
{
	check(0, "back on empty BlobStr");
	return data->back();
}

const std::string &BlobStr::back() const
{
	check(0, "const back on empty BlobStr");
	return data->back();
}

void BlobStr::pop_back()
{
	check(0, "pop_back on empty BlobStr");
	data->pop_back();
}

#endif