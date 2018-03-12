#include <iostream>
#include <string>
using namespace std;

class Date
{
	private:
		unsigned year=0, month=0, day=0;
	
	public:
		Date() = default;
		Date(const string &);
		
	friend ostream &print(ostream&, const Date&);
};

Date::Date(const string &s)
{
	// January 1, 1900
	// 1/1/1990
	// Jan 1 1900
	auto pa = s.find(",");
	auto pb = s.find_last_of("/");
	string str_m("");
	if(pa != string::npos)
	{
		year = stoi(s.substr(pa+1, -1));
		auto px = s.find_first_of(" ");
		if(px != string::npos)
		{
			day = stoi(s.substr(px, pa - px));
			str_m = s.substr(0, px);
		}
	}
	else if(pb != string::npos)
	{
		year = stoi(s.substr(pb+1, -1));
		auto py = s.find_first_of("/");
		if(py != string::npos)
		{
			day = stoi(s.substr(py+1, pb-py-1));
			str_m = s.substr(0, py);
		}
	}
	else
	{
		auto p1 = s.find_first_of(" ");
		auto p2 = s.find_last_of(" ");
		if(p1 != string::npos && p2 != string::npos)
		{
			year = stoi(s.substr(p2+1, -1));
			day = stoi(s.substr(p1, p2-p1));
			str_m = s.substr(0, p1);
		}
	}
	
	if(str_m == "Jan" || str_m == "January")
	{
		month = 1;
	}
}

ostream &print(ostream &os, const Date &d)
{
	os  << "Year: " << d.year
		<< ", Month: " << d.month
		<< ", Day: "	<< d.day << endl;
	return os;
}

int main()
{
	/* Date da("January 1, 1900");
	Date db("1/1/1990");
	Date dc("Jan 1 1900"); */
	
	string s1("January 1, 1900");
	auto p = s1.find(",");
	cout << p << endl;
	cout << s1.substr(p, -1) << endl;
	int y = stoi(s1.substr(p+1, -1));
	cout << y << endl;
	auto p2 = s1.find(" ");
	cout << p2 << ' ' << p - p2 << endl;
	cout << stoi(s1.substr(p2, p-p2)) << endl;
	string sm = s1.substr(0, p2);
	cout << sm << endl;
	
	string s2("1/1/1990");
	cout << s2.substr(s2.find_last_of("/")+1, -1) << endl;
	cout << s2.substr(s2.find_first_of("/")+1, s2.find_last_of("/")-s2.find_first_of("/")-1) << endl;
	cout << s2.substr(0, s2.find_first_of("/")) << endl;
	
	cout << "\n------------------" << endl;
	Date date1(s1);
	print(cout, date1) << endl;
	
	Date date2(s2);
	print(cout, date2) << endl;
	
	Date date3("Jan 2 1991");
	print(cout, date3) << endl;
	
	return 0;
}