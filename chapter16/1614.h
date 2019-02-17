#pragma once
#include <string>
#include <iostream>

template <unsigned W, unsigned H>
class Screen
{
	unsigned width = W;
	unsigned height = H;
	std::string contents;
	
public:
	Screen() = default;
	Screen(unsigned w, unsigned h) : width(w), height(h){};
	~Screen() = default;
};