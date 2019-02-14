#include <string>
#include <iostream>

template <typename T> class Foo
{
public:
	static std::size_t count() { return ctr; }
	
	Foo<T>(){ ++ctr; }
	
private:
	static std::size_t ctr;	// just declare.
};

// define and initialize ctr.
template <typename T>
std::size_t Foo<T>::ctr = 0;

int main()
{
	typedef Foo<int> iFoo;
	iFoo ifoo;
	std::cout << ifoo.count() << std::endl;
	iFoo ifoo2;
	std::cout << ifoo.count() <<", " << ifoo.count() << std::endl;
	
	Foo<std::string> sf;
	std::cout << sf.count() << std::endl;
	std::cout << Foo<std::string>::count() << std::endl;
	
	Foo<std::string> sf2;
	auto sct = Foo<std::string>::count();
	auto sct2 = sf2.count();
	std::cout << "sct == sct2 ? " << (sct == sct2 ? "True" : "False") << std::endl;
	std::cout << sct << std::endl;
	
	return 0;
}