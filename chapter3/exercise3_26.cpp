#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vi;
	cout << "enter some integers:" << endl;
	int i;
	while(cin >> i && i != 0)
		vi.push_back(i);
	cout << "Your inputs:" << endl;
	for(int i : vi)
		cout << i << ' ';
	cout << endl;
	
	decltype(vi.size()) cnt = vi.size();
	if(cnt < 2)
		cout << "vi.size < 2, stop!" << endl;
	else
	{
		cout << "\nneighbor sum:" << endl;
		for(auto cbegin = vi.cbegin(); cbegin + 1 != vi.cend(); ++cbegin)
		{
			cout << *cbegin << " + " << *(cbegin+1) << " = " << *cbegin + *(cbegin+1) << endl;
		}
		
		cout << "\nbrother sum:" << endl;
		for(auto cbegin = vi.cbegin(); cbegin < vi.cend(); cbegin += 2)
		{
			if(cbegin+1 == vi.cend())
				cout << "last alone element: " << *cbegin << endl;
			else
				cout << *cbegin << " + " << *(cbegin+1) << " = " << *cbegin + *(cbegin+1) << endl;
		}
		
		cout << "\nfirst + last:" << endl;
		for(auto cbegin = vi.cbegin(), cend = vi.cend()-1; cbegin <= cend; ++cbegin, --cend)
		{
			if(cbegin == cend)
				cout << "middle element: " << *cbegin << endl;
			else
				cout << *cbegin << " + " << *cend << " = " << *cbegin + *cend << endl;
		}
	}
	
	return 0;
}