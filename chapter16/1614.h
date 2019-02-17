#pragma once
#include <string>
#include <iostream>

template <unsigned W, unsigned H>
class Screen
{
	friend std::ostream& operator<< (std::ostream &os, const Screen<W, H> &s)
	{
		os << s.contents << std::endl;
		return os;
	}
	
	friend std::istream & operator>> (std::istream &is, Screen &s)
	{
		std::string tmp;
		is >> tmp;
		s.contents = tmp;
		return is;
	}
	
	unsigned width = W;
	unsigned height = H;
	std::string contents;
	
public:
	Screen() = default;
	Screen(std::string s) : contents(s){};
	~Screen() = default;
	
	void size_info();
};

template <unsigned W, unsigned H>
inline void Screen<W,H>::size_info()
{
	std::cout << "Width:" << W << ", Height:" << H << std::endl;
}
