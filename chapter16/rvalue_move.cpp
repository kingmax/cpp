// ��ֵ������ת������
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
		1. ��������ֵ���ķ��ű�������ֵ���÷��ţ�����&&����
		2. ��������ֵ���������ǳ�������Ϊ������Ҫ�޸���ֵ��
		3. ��������ֵ������Դ���Ӻͱ�Ǳ����޸ġ�������ֵ�����������ͻ��ͷ���Դ��ת�Ƶ��¶������ԴҲ����Ч�ˡ�
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
	��������ת�ƹ��캯����ת�Ƹ��Ʋ�������, ��������������ֵ����ֵ������ֵ������ת�ƹ��캯����ת�Ƹ�ֵ����������ʡ����Դ������˳������е�Ч�ʡ�
	������ֵ���ú�ת�����壬��������ƺ�ʵ����ʱ��������Ҫ��̬���������Դ���࣬Ӧ�����ת�ƹ��캯����ת�Ƹ�ֵ�����������Ӧ�ó����Ч�ʡ�
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
	process(std::move(L)); // RValue, std::move����ֵ����ת��Ϊ��ֵ����
	newline();
	
	// swap
	int a = 10, b = 100;
	std::cout << "a=" << a << ", b=" << b << std::endl;
	::swap(a, b);
	std::cout << "a=" << a << ", b=" << b << std::endl;
	
	return 0;
}