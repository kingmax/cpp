#include <iostream>

template<typename T, unsigned N>
T* beg(T (&arr)[N])
{
	return arr;
}

template<typename T, unsigned N>
T* end(T (&arr)[N])
{
	return arr+N;
}

int main()
{
	char cArray[] = {'a', 'c', 'o', 'k'};
	char *b = beg(cArray);
	std::cout << b << ' ' << *b << std::endl;
	
	std::cout << *(end(cArray)-1) << std::endl;
	
	return 0;
}