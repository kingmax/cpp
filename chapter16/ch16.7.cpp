#include <iostream>

template<typename T, unsigned N> constexpr
unsigned size_of_arr(const T (&arr)[N])
{
	return N;
}

int main()
{
	char cs[]{'a', 'b', 'c'};
	const size_t size = size_of_arr(cs);
	std::cout << size << std::endl;
	
	return 0;
}