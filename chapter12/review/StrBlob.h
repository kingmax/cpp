#ifndef __StrBlob_H__
#define __StrBlob_H__

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
using namespace std;

class StrBlobPtr;

class StrBlob
{
public:
	typedef vector<string>::size_type size_type;
	//using size_type = vector<string>::size_type;
	friend class StrBlobPtr;
	
	StrBlobPtr begin();
	StrBlobPtr end();
	
	StrBlob();
	StrBlob(initializer_list<string> il);
	
	size_type size() const;
	bool empty() const;
	void push_back(const string &s);
	void pop_back();
	string& front();
	string& back();
	const string& front() const;
	const string& back() const;
	
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;
};

#endif