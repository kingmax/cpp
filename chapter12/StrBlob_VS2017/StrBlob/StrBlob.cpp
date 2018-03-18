#include "StrBlob.h"

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {};

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il))
{

}

void StrBlob::check(StrBlob::size_type sz, const std::string &msg) const
{
	if (sz >= data->size())
		throw std::out_of_range(msg);
}

bool StrBlob::empty() const
{
	return data->empty();
}

StrBlob::size_type StrBlob::size() const
{
	return data->size();
}

std::string &StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

const std::string &StrBlob::front() const
{
	check(0, "const front on empty StrBlob");
	return data->front();
}

std::string &StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

const std::string &StrBlob::back() const
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
	check(0, "pop_back on empty BlobStr");
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