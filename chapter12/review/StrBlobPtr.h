#ifndef __StrBlobPtr_H__
#define __StrBlobPtr_H__

#include <vector>
#include <string>
#include <memory>
using namespace std;

class StrBlob;

class StrBlobPtr
{
private:
	weak_ptr<vector<string>> wptr;
	size_t curr;
	shared_ptr<vector<string>> check(size_t i, const string &msg) const;
	
public:
	StrBlobPtr();
	StrBlobPtr(StrBlob &s, size_t sz=0);
	
	bool operator != (const StrBlobPtr &p);
	
	string& deref() const;
	
	StrBlobPtr& incr();
};

#endif