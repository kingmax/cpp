#include <iostream>
#include <vector>
#include <list>
using namespace std;

int compare(const vector<int> &va, const vector<int> &vb)
{
	if(va.size() != vb.size())
		return va.size() > vb.size() ? 1 : -1;
	else
	{
		for(auto i = va.cbegin(), j = vb.cbegin();
				 i != va.cend(), j != vb.cend(); 
				 ++i, ++j)
		{
			return *i > *j ? 1 : (*i < *j ? -1 : 0);
		}
	}
	return 0;
}

//exercise 9.16
int compare(const list<int> &la, const vector<int> &vb)
{
	vector<int> va = {la.cbegin(), la.cend()};
	return compare(va, vb);
}

int main()
{
	vector<int> va = {1,2,3,4,5};
	vector<int> vb = va;
	cout << compare(va, vb) << endl;
	
	vb = {1,2,3};
	cout << compare(va, vb) << endl;
	
	vb.assign(10, 0);
	cout << compare(va, vb) << endl;
	
	cout << "\ncompare list<int> and vector<int>" << endl;
	vb = va;
	list<int> la = {1,2,3,4,5};
	cout << compare(la, vb) << endl;
	
	la = {1,3,5};
	cout << compare(la, vb) << endl;
	
	la.assign(10, 100);
	cout << compare(la, vb) << endl;
	
	return 0;
}