#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <string>
#include <iostream>
#include <vector>

/* class Screen;

class Window_mgr
{
	public:
		using ScreenIndex = std::vector<Screen>::size_type;
		
		void clear(ScreenIndex);
		
	private:
		std::vector<Screen> screens{Screen(24, 80, ' ')};
}; */


class Screen
{
	friend class Window_mgr; //mgr class can access this.private data!!
	//friend void Window_mgr::clear(ScreenIndex);
	
	public:
		typedef std::string::size_type pos;
		
	private:
		pos width = 0;
		pos height = 0;
		std::string contents;
		pos cursor = 0;
		void do_display(std::ostream &os) const
		{
			os << contents;
		}
		
	public:
		Screen() = default;
		Screen(pos wd, pos ht) : width(wd), height(ht), 
				contents(wd*ht, ' '){}
		Screen(pos wd, pos ht, char c) : width(wd), height(ht), 
				contents(wd*ht, c){}
		
		inline char get() const
		{ 
			return contents[cursor]; 
		}
		
		inline char get(pos row, pos col) const
		{
			pos cur = row * width + col;
			return contents[cur];
		}
		
		inline Screen &set(char c)
		{
			contents[cursor] = c;
			return *this;
		}
		
		inline Screen &set(pos row, pos col, char c)
		{
			pos cur = row * width + col;
			contents[cur] = c;
			return *this;
		}
		
		//move cursor
		inline Screen &move(pos row, pos col)
		{
			pos dest = row * width + col;
			cursor = dest;
			return *this;
		}
		//myScreen.move(4, 0).set('#');
		
		Screen &display(std::ostream &os)
		{
			do_display(os);
			return *this; 
		}
		
		const Screen &display(std::ostream &os) const
		{
			do_display(os);
			return *this; //return const object
		}
		
		pos size() const;
};

Screen::pos Screen::size() const
{
	return height * width;
}

class Window_mgr
{
	public:
		using ScreenIndex = std::vector<Screen>::size_type;
		
		void clear(ScreenIndex);
		
	private:
		std::vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}

class Link_screen
{
	Screen window;
	Link_screen *next;
	Link_screen *prev;
};

#endif