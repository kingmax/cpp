#include <string>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class StrBlob
{
	public:
		typedef std::vector<std::string>::size_type size_type;
		StrBlob();
		StrBlob(std::initializer_list<std::string> il);
		size_type size() const {return data->size();}
		bool empty() const {return data->empty();}
		void push_back(const std::string &s){data->push_back(s);}
		void pop_back();
		std::string &front();
		std::string &back();
		const std::string &front() const;
		const std::string &back() const;
		
	private:
		std::shared_ptr<std::vector<std::string>> data;
		void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()){}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)){}
void StrBlob::check(size_type i, const string &msg) const
{
	if(i >= data->size())
		throw out_of_range(msg);
}
string &StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}
const string &StrBlob::front() const
{
	check(0, "front on empty const StrBlob");
	return data->front();
}
string &StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}
const string &StrBlob::back() const
{
	check(0, "back on empty const StrBlob");
	return data->back();
}
void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}


int main()
{
	StrBlob b1;
	{
		StrBlob b2 = {"a", "an", "the"};
		b1 = b2;
		b2.push_back("about");
		
		cout << b1.size() << ' ' << b2.size() << endl;
	}
	
	return 0;
}