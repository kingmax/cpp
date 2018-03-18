#include "strblob.h"

/* public:
	using size_type = std::vector<std::string>::size_type;
	StrBlob();
	StrBlob(std::initializer_list<string> il);
	
	bool empty() const;
	size_type size() const;
	
	std::string front();
	const std::string front() const;
	std::string back();
	const std::string back() const;
	
	void push_back(const std::string &);
	void pop_back();
	
	StrBlobPtr begin() const;
	StrBlobPtr end() const;
	
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type, const std::string &) const; */
	
StrBlob::StrBlob() 
			: data(std::make_shared<std::vector<std::string>>())
			{}
StrBlob::StrBlob(std::initializer_list<std::string> il) 
			: data(std::make_shared<std::vector<std::string>>(il))
			{}
			
void StrBlob::check(size_type sz, const std::string &msg) const
{
	if(sz >= data->size())
		throw std::out_of_range(msg);
}

bool StrBlob::empty() const { return data->empty(); }
StrBlob::size_type StrBlob::size() const { return data->size(); }

std::string StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

const std::string StrBlob::front() const
{
	check(0, "const front on empty StrBlob");
	return data->front();
}

std::string StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

const std::string StrBlob::back() const
{
	check(0, "const back on empty StrBlob");
	return data->back();
}

void StrBlob::push_back(const std::string &s)
{
	data->push_back(s);
}

void StrBlob::pop_back()
{
	data->pop_back();
}

StrBlobPtr StrBlob::begin()/*  const */
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()/*  const */
{
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}

/////////////////////////////////////////////////////
