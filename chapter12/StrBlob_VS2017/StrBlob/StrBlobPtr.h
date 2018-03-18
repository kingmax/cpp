#pragma once
#ifndef _STRBLOBPTR_H_
#define _STRBLOBPTR_H_

//#include <memory>
//#include <string>
//#include <vector>

//in B.h, forward-decl class A
class StrBlob;

class StrBlobPtr
{
public:
	StrBlobPtr();
	StrBlobPtr(StrBlob&, std::size_t=0);
	~StrBlobPtr();

	std::string &deref() const;
	StrBlobPtr &incr();

private:
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;

	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
};

#endif
