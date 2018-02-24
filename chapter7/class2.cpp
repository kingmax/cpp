#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Screen
{
	public:
		typedef std::string::size_type pos;
		
		//Constructor
		Screen() = default;
		Screen(pos ht, pos wd, char c) : height(ht), width(wd), 
				contents(ht * wd, c) {}
		
		//Methods
		char get() const
		{
			return contents[cursor];
		}
		
		inline char get(pos ht, pos wd) const;
		
		Screen &move(pos r, pos c);
		
		//mutable
		void some_member() const;
		
	private:
		pos cursor = 0;
		pos height = 0, width = 0;
		std::string contents;
		//mutable data member
		mutable size_t access_ctr; //can change in const!!
};

void Screen::some_member() const
{
	++access_ctr; //can change in const object!!!
}

inline Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

inline char Screen::get(pos ht, pos wd) const
{
	pos row = ht * width;
	return contents[row + wd];
}

class Window_mgr
{
	private:
		std::vector<Screen> screens{Screen(24, 80, ' ')};
};

int main()
{
	
	return 0;
}