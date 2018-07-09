#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <initializer_list>
#include <algorithm>
using namespace std;

class ConstStrBlobPtr;

using size_type = vector<string>::size_type;

class StrBlob
{
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string& msg) const
	{
		if(i >= data->size())
			throw out_of_range(msg);
	}
	
public:
	StrBlob() : data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
	
	friend class ConstStrBlobPtr;
	
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string& s) { data->push_back(s); }
	void pop_back() { check(0, "pop_back on empty StrBlob"); data->pop_back(); }
	string& front() { check(0, "empty"); return data->front(); }
	string& back() { check(0, "empty"); return data->front(); }
	string& front() const { check(0, "empty"); return data->front(); }
	string& back() const { check(0, "empty"); return data->front(); }
	
	ConstStrBlobPtr begin(); //imp must After Class ConstStrBlobPtr
	ConstStrBlobPtr end();
	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;
};

class ConstStrBlobPtr
{
private:
	weak_ptr<vector<string>> wptr;
	size_t curr;
	shared_ptr<vector<string>> check(size_t i, const string& msg) const
	{
		auto ret = wptr.lock();
		if(!ret) throw runtime_error("unbound StrBlobPtr");
		if(i >= ret->size()) throw out_of_range(msg);
		return ret;
	}
	
public:
	ConstStrBlobPtr() : curr(0) {}
	ConstStrBlobPtr(const StrBlob& s, size_t sz=0) : wptr(s.data), curr(sz) {} //should add const
	bool operator != (ConstStrBlobPtr& p) { return p.curr != curr; }
	const string& deref() const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	ConstStrBlobPtr& incr()
	{
		check(curr, "increment past end");
		++curr;
		return *this;
	}
};

ConstStrBlobPtr StrBlob::begin()
{
	return ConstStrBlobPtr(*this);
}
	
ConstStrBlobPtr StrBlob::end()
{
	return ConstStrBlobPtr(*this, data->size());
}

ConstStrBlobPtr StrBlob::begin() const
{
	return ConstStrBlobPtr(*this);
}
	
ConstStrBlobPtr StrBlob::end() const
{
	return ConstStrBlobPtr(*this, data->size());
}

int main()
{
	StrBlob blob({"hello", "world", "okay"});
	cout << blob.size() << endl;
	
	vector<string> vs({"hello", "world", "okay"});
	auto print = [](const string& s){ cout << " " << s; };
	for_each(vs.cbegin(), vs.cend(), print);
	cout << endl;
	
	for(auto pb(blob.begin()), pe(blob.end()); pb != pe; pb.incr())
		cout << pb.deref() << endl;
	
	return 0;
}