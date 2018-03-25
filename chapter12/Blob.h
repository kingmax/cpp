#ifndef _BLOB_H_
#define _BLOB_H_

#include <string>
#include <vector>
#include <memory>
using std::string;
using std::vector;

class Blob
{
	public:
		typedef vector<string>::size_type size_type;
		Blob();
		Blob(std::initializer_list<string>);
		size_type size() const;
		bool empty() const;
		void push_back(const string&);
		void pop_back();
		string& front();
		string& back();
		const string& front() const;
		const string& back() const;
		
	private:
		std::shared_ptr<vector<string>> data;
		void check(size_type, const string&) const;
};

#endif