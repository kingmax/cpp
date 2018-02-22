#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <string>
class Screen
{
	public:
		typedef std::string::size_type pos;
		//constructor
		Screen() = default;
		Screen(pos ht, pos wd, char c) : 
				height(ht), width(wd), contents(ht * wd, c) {}
		
	private:
		pos cursor = 0;
		pos height = 0, width = 0;
		std::string contents;
};

#endif