#include <iostream>
#include <vector>
using namespace std;

const vector<int>* fibon_seq(int size)
{
	const int max_size = 1024;
	static vector<int> elems;
	
	if(size <= 0 || size > max_size)
	{
		cerr << "fibon_seq(): oops: invalid size: "
			 << size << " -- can't fulfill request.\n";
		return 0;
	}
	
	//at first, elems is empty, size=0
	for(int i = elems.size(); i < size; ++i)
	{
		if(i == 0 || i == 1)
			elems.push_back(1);
		else
			elems.push_back(elems[i-2] + elems[i-1]);
	}
	
	return &elems;
}

void print(const vector<int> &v)
{
	for(int i = 0; i < v.size(); ++i)
		cout << v[i] << (i==0 ? " " : (((i+1) % 10) ? " " : "\n"));
	cout << endl;
}

int main()
{
	int pos;
	cout << "enter a position of fibonacci: ";
	cin >> pos;
	
	const vector<int> *pv = fibon_seq(pos);
	print(*pv);
	cout << endl;
	
	for(int i=1; i<4; ++i)
	{
		cout << "next (10 * n) fibonacci:" << endl;
		fibon_seq(10*i + pos);
		print(*pv);
		cout << endl;
	}
	
	return 0;
}