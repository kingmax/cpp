#include "blobPtr.h"
#include <iostream>

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	BlobPtr ret = *this;
	++*this;
	return ret;
}

int main()
{
	
	return 0;
}