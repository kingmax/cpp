// 右值引用与转移语义
// ref: https://www.ibm.com/developerworks/cn/aix/library/1307_lisl_c11/index.html

#include <iostream>
#include <string>
#include <vector>

// 001
void process(int& leftValue)
{
	std::cout << "LValue processed: " << leftValue << std::endl;
}

void process(int&& rightValue)
{
	std::cout << "RValue processed: " << rightValue << std::endl;
}

void forward(int&& rv)
{
	process(rv);
}

// 002
class MyString
{
	char* _data;
	size_t _len;
	void _init_data(const char* s)
	{
		_data = new char[_len+1];
		memcpy(_data, s, _len);
		_data[_len] = '\0';
	}
	
public:
	MyString()
	{
		_data = nullptr;
		_len = 0;
	}
	
	MyString(const char* p)
	{
		_len = strlen(p);
		_init_data(p);
	}
	
	// Copy Constructor
	MyString(const MyString& str)
	{
		_len = str._len;
		_init_data(str._data);
		std::cout << "Copy Constructor is called! source: " << str._data << std::endl;
	}
	
	// Copy Assignment
	MyString& operator=(const MyString& str)
	{
		std::cout << this << std::endl;
		std::cout << &str << std::endl;
		if(this != &str)
		{
			_len = str._len;
			_init_data(str._data);
		}
		std::cout << "Copy Assignment is called! source: " << str._data << std::endl;
		return *this;
	}
	
	// Move Constructor
	MyString(MyString&& str)
	{
		std::cout << "Move Constructor is called! source: " << str._data << std::endl;
		_len = str._len;
		_data = str._data;
		/*
		1. 参数（右值）的符号必须是右值引用符号，即“&&”。
		2. 参数（右值）不可以是常量，因为我们需要修改右值。
		3. 参数（右值）的资源链接和标记必须修改。否则，右值的析构函数就会释放资源。转移到新对象的资源也就无效了。
		*/
		str._len = 0;
		str._data = nullptr;
	}
	
	// Move Assignment
	MyString& operator=(MyString&& str)
	{
		std::cout << "Move Assignment is called! source: " << str._data << std::endl;
		std::cout << this << std::endl;
		std::cout << &str << std::endl;
		if(this != &str)
		{
			_len = str._len;
			_data = str._data;
			str._len = 0;
			str._data = nullptr;
		}
		return *this;
	}
	
	virtual ~MyString()
	{
		if(_data)
			free(_data);
	}
	
	char* data(){ return _data; }
};


template<typename T> void swap_classic(T& a, T& b)
{
	T tmp(a);
	a = b;
	b = tmp;
}

template<typename T> void swap(T& a, T& b)
{
	T tmp(std::move(a));
	a = std::move(b);
	b = std::move(tmp);
}

#define newline() (std::cout << std::endl)

int main()
{
	int L = 0;
	process(L); // LValue
	process(1);	// RValue
	forward(2); // LValue processed: 2, RValue changed to LValue!
	newline();
	
	/*
	当定义了转移构造函数和转移复制操作符后, 编译器区分了左值和右值，对右值调用了转移构造函数和转移赋值操作符。节省了资源，提高了程序运行的效率。
	有了右值引用和转移语义，我们在设计和实现类时，对于需要动态申请大量资源的类，应该设计转移构造函数和转移赋值函数，以提高应用程序的效率。
	*/
	MyString s;
	s = MyString("Hello");
	std::vector<MyString> vec;
	vec.push_back(MyString("World"));
	for(auto&& v : vec)
		std::cout << v.data() << ", ";
	std::cout << std::endl;
	newline();
	
	// move
	process(std::move(L)); // RValue, std::move将左值引用转换为右值引用
	newline();
	
	// swap
	int a = 10, b = 100;
	std::cout << "a=" << a << ", b=" << b << std::endl;
	::swap(a, b);
	std::cout << "a=" << a << ", b=" << b << std::endl;
	
	return 0;
}