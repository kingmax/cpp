#include <iostream>
#include <string>
using namespace std;

class Screen
{
	public:
		typedef string::size_type pos;
		
		Screen() = default;
		Screen(pos w, pos h, char c) : width(w), height(h), contents(w*h, c){}
		Screen(pos w, pos h) : width(w), height(h), contents(w*h, ' '){}
		
		char get() const {return contents[cursor];}
		char get(pos r, pos c) const {return contents[r*width+c];}
		
		Screen &set(char c)
		{
			contents[cursor] = c;
			return *this;
		}
		
		Screen &set(pos r, pos c, char _c)
		{
			contents[r*width + c] = _c;
			return *this;
		}
		
		Screen &move(pos r, pos c)
		{
			cursor = r * width + c;
			return *this;
		}
		
		const Screen &display(ostream &os) const
		{
			os << "call const version" << endl;
			do_display(os);
			return *this;
		}
		
		Screen &display(ostream &os)
		{
			os << "call Non-Const version" << endl;
			do_display(os);
			return *this;
		}
		
	private:
		pos width = 0, height = 0, cursor = 0;
		string contents;	
		
		void do_display(ostream &os) const
		{
			os << contents;
		}
};

int main()
{
	Screen myScreen(5, 5, 'X');
	myScreen.display(cout);
	cout << endl;
	
	myScreen.move(4, 0).set('#').display(cout).set('*');
	cout << endl;
	
	myScreen.move(2,0).display(cout);
	cout << endl;
	
	//call const version:
	cout << endl << endl;
	const Screen myScreen2(5,5, '$');
	myScreen2.display(cout);
	cout << endl;
	
	//myScreen2.move(4, 0).set('#').display(cout).set('*'); //Error const cann't call const display&() const!
	cout << endl;
	
	//myScreen2.move(2,0).display(cout); //Error
	cout << endl;
	
	return 0;
}