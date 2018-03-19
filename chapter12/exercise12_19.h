#ifndef _EXERCISE12_19_H
#define _EXERCISE12_19_H

#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
using std::string;
using std::vector;

class StrBlobPtr; //forward declaration

class StrBlob
{
	friend class StrBlobPtr;
	
	public:
		typedef vector<string>::size_type size_type;
		//constructor
		StrBlob();
		StrBlob(std::initializer_list<string>);
		//methods
		bool empty() const;
		size_type size() const;
		string &front();
		const string &front() const;
		string &back();
		const string &back() const;
		void push_back(const string&);
		void pop_back();
		StrBlobPtr begin();
		StrBlobPtr end();
	
	private:
		//data members
		std::shared_ptr<vector<string>> data;
		//private methods
		void check(size_type, const string&) const;
};

class StrBlobPtr
{
	public:
		//constructor
		StrBlobPtr();
		StrBlobPtr(StrBlob&, std::size_t=0);
		//methods
		string &deref() const;
		StrBlobPtr &incr();
		//operator
		bool operator!=(StrBlobPtr&);
		
	private:
		//data member
		std::weak_ptr<vector<string>> wptr;
		std::size_t curr;
		//private methods
		std::shared_ptr<vector<string>> check(std::size_t, const string&) const;
};

#endif