#include "Blob.h"

/* class Blob
{
	public:
		typedef vector<string>::size_type size_type;
		Blob();
		Blob(std::initializer_list<string>);
		size_type size() const;
		bool empty() const;
		void push_back(const string);
		void pop_back();
		string& front();
		string& back();
		const string& front() const;
		const string& back() const;
	private:
		std::shared_ptr<vector<string>> data;
		void check(size_type, const string) const;
}; */

Blob::Blob() : data(std::make_shared<vector<string>>()){}
Blob::Blob(std::initializer_list<string> il) :
			data(std::make_shared<vector<string>>(il)){}

void Blob::check(Blob::size_type i, const string &msg) const
{
	if(i >= size())
		throw std::out_of_range(msg);
}

Blob::size_type Blob::size() const
{
	return data->size();
}

bool Blob::empty() const
{
	return data->empty();
}

void Blob::push_back(const string &s)
{
	check(0, "push_back on empty Blob");
	data->push_back(s);
}

void Blob::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

string &Blob::front()
{
	check(0, "front on empty Blob");
	return data->front();
}

const string &Blob::front() const
{
	check(0, "const front on empty Blob");
	return data->front();
}

string &Blob::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

const string &Blob::back() const
{
	check(0, "const back on empty Blob");
	return data->back();
}