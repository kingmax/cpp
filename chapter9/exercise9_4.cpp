#include <iostream>
#include <vector>
using namespace std;

bool find(vector<int>::iterator beg, vector<int>::iterator end, int x)
{
	while(beg != end)
	{
		if(*beg == x)
			return true;
		++beg;
	}
	return false;
}

vector<int>::iterator &find2(vector<int>::iterator &beg, vector<int>::iterator &end, int x)
{
	while(beg != end)
		if(*beg++ == x)
			return beg;
	return end;
}

string truefalse(bool b)
{
	return b ? "true" : "false";
}

int main()
{
	vector<int> vi = {1,2,3,4,5,6,7,8,9,10};
	vector<int>::iterator beg = vi.begin();
	vector<int>::iterator end = vi.end();
	bool found = find(beg, end, 10);
	string s = truefalse(found);
	cout << "found? ";
	cout << (found ? "true" : "false") << endl;
	//cout << string(s) << endl;
	
	bool t = true;
	bool f = false;
	std::cout << std::noboolalpha << t << " == " << std::boolalpha << t << std::endl;        
	std::cout << std::noboolalpha << f << " == " << std::boolalpha << f << std::endl;
	
	cout << endl;
	vector<int>::iterator _found = find2(beg, end, 9);
	//cout << (_found != end ? ("found:" + *_found) : "not found") << endl;
	if(_found != end)
		cout << "found:" << *_found << endl;
	else
		cout << "not found" << endl;
	
	return 0;
}