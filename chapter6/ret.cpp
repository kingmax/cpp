#include <iostream>
#include <string>
#include <vector>
using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return ctr > 1 ? word + ending : word;
}

const string &shorterString(const string &s1, const string &s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}

//return left-value
char &get_val(string &str, string::size_type ix)
{
	return str[ix];
}

//list init return
vector<string> process()
{
	/* if(expected.empty())
		return {};
	else if(expected == actual)
		return {"functionX", "okay"};
	else
		return {"functionX", expected, actual}; */
	return {"functionX", "okay"};
}

int factorial(int val)
{
	//if(val != 0) //error, factorial(0) => 1, -val...
	if(val > 1)
		//return factorial(val--) * val; //error, val--
		return factorial(val-1) * val;
	else
		return 1;
}

int main(int argc, char *argv[])
{
	cout << make_plural(1, "Apple", "s") << endl;
	string apple_plural = make_plural(2, "Apple", "s");
	cout << apple_plural << endl;
	
	const string s1 = "Dog", s2 = "Tiger";
	const string ss = shorterString(s1, s2);
	cout << ss << endl;
	cout << &s1 << ' ' << &shorterString(s1, s2) << ' ' << &ss << endl;
	
	string s("a value");
	cout << s << endl;
	get_val(s, 0) = 'A'; //can change lvalue
	cout << s << endl;
	
	for(auto s : process())
		cout << s << endl;
	cout << endl;
	
	cout << factorial(5) << endl;
	cout << factorial(1) << endl;
	//cout << factorial(0) << endl; //error
	
	if(argc == 0)
		return EXIT_FAILURE;
	else
		return EXIT_SUCCESS;
	
	return 0;
}