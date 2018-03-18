#ifndef _STRBLOBPTR_H_
#define _STRBLOBPTR_H_

class StrBlob; //forward-declaration A

class StrBlobPtr
{
	private:
		std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
		std::weak_ptr<std::vector<std::string>> wptr;
		std::size_t curr;
		
	public:
		StrBlobPtr();
		StrBlobPtr(StrBlob&, std::size_t=0);
		
		std::string &deref() const;
		StrBlobPtr &incr();
		
		bool operator != (const StrBlobPtr&);
};

#endif