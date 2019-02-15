#include "1612Blob.h"
#include "1612BlobPtr.h"
#include <iostream>
#include <string>

typedef Blob<std::string> StrBlob;

int main()
{
	StrBlob sb1;
	Blob<std::string> sb2{"a", "b"};
	std::cout << sb2.size() << std::endl;
	
	BlobPtr<std::string> sbPtr;
	BlobPtr<std::string> sbPtr2(sb2);
	std::cout << *sbPtr2 << std::endl;
	sbPtr2++;
	std::cout << *sbPtr2 << std::endl;
	
	return 0;
}