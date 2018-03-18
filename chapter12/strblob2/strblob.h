#ifndef _STRBLOB_H_
#define _STRBLOB_H_

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>

#include "strblobptr.h" //include B.h

class StrBlob
{
	friend class StrBlobPtr;
	
	public:
		using size_type = std::vector<std::string>::size_type;
		StrBlob();
		StrBlob(std::initializer_list<std::string> il);
		
		bool empty() const;
		size_type size() const;
		
		std::string front();
		const std::string front() const;
		std::string back();
		const std::string back() const;
		
		void push_back(const std::string &);
		void pop_back();
		
		StrBlobPtr begin();/*  const; */
		StrBlobPtr end();/*  const; */
		
	private:
		std::shared_ptr<std::vector<std::string>> data;
		void check(size_type, const std::string &) const;
};

///////////////////////////////////////////////////////////////////


#endif