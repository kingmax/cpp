#include "Screen.h"
using namespace std;

class S
{
	public:
		typedef std::string::size_type pos;
		void dummy_fcn(pos h)
		{
			cursor = width * h;
		}
	private:
		pos cursor = 0;
		pos height = 0, width = 0;
	/* public:
		typedef std::string::size_type pos; */
};

int main()
{
	Screen myScreen(5, 3);
	const Screen blank(5, 3);
	myScreen.set('#').display(cout);
	blank.display(cout); //call const display&(ostream&) const
	
	
	
	cout << endl;
	//myScreen.move(4, 0).set('*').display(cout);
	
	cout << endl;
	Screen::pos ht = 24, wd = 80;
	Screen scr(ht, wd, '$');
	Screen *p = &scr;
	cout << scr.get() << endl;
	char c = p->get();
	cout << c << endl;
	cout << p->size() << endl;
	
	return 0;
}