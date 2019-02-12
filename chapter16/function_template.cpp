#include <iostream>
#include <vector>
#include <string>

template <typename T> T swap(T* p1, T* p2)
{
	T tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
	// just for testing
	return tmp;
}

// class and typename is same!
template <class T> T foo(T *p)
{
	T tmp = *p;
	return tmp;
}

template <typename T>
int compare(const T &v1, const T &v2)
{
	// only using <
	if(v1 < v2) return -1;
	if(v2 < v1) return 1;
	return 0;
}

// 非类型模板参数
template <unsigned N, unsigned M> 
int compareText(const char (&r1)[N], const char (&r2)[M])
{
	return strcmp(r1, r2);
}

// inline or constexpr
template <typename T> inline T min(const T&, const T&);
template <typename T> constexpr T fo(const T&);

int main()
{
	std::cout << compare(1, 0) << std::endl;
	
	std::vector<int> vec1{1,2,3};
	std::vector<int> vec2{4,5,6};
	std::cout << compare(vec1, vec2) << std::endl;
	
	std::cout << "swap testing:" << std::endl;
	int a = 1, b = 2;
	std::cout << a << ", " << b << std::endl;
	swap(&a, &b);
	std::cout << a << ", " << b << std::endl;
	
	double c = 3.14, d = 2.3;
	std::cout << c << ", " << d << std::endl;
	swap(&c, &d);
	std::cout << c << ", " << d << std::endl;
	
	std::string s1 = "hi", s2 = "hello";
	std::cout << s1 << ", " << s2 << std::endl;
	swap(&s1, &s2);
	std::cout << s1 << ", " << s2 << std::endl;
	
	std::cout << foo(&s2) << std::endl; // hi
	
	char t1[] = "hi", t2[] = "mom";
	std::cout << compareText(t1, t2) << std::endl;
	
	return 0;
}