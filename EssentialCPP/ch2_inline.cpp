#include <iostream>
#include <vector>
using namespace std;

inline bool check_size(int size)
{
	const int max_size = 1024;
	if(size <= 0 || size > max_size)
	{
		cerr << "Oops: requested size is not supported: "
			 << size << " -- can't fulfill request.\n";
		return false;
	}
	return true;
}

inline const vector<int>* fibon_seq(int size)
{
	static vector<int> elems;
	const int max_size = 1024;
	
	if(!check_size(size))
		return 0;
	
	for(int i = elems.size(); i < size; ++i)
	{
		if(i == 0 || i == 1)
			elems.push_back(1);
		else
			elems.push_back(elems[i-2] + elems[i-1]);
	}
	
	return &elems;
}

bool fibon_elem(int pos, int &elem)
{
	const vector<int> *pv = fibon_seq(pos);
	
	if(!pv)
	{
		elem = 0;
		return false;
	}
	
	elem = (*pv)[pos-1];
	return true;
}

void print(const vector<int> *pv)
{
	for(const auto &e : *pv)
		cout << e << ' ';
	cout << endl;
}

int main()
{
	int pos;
	cout << "enter position:";
	cin >> pos;
	
	const vector<int> *pv = fibon_seq(pos);
	print(pv);
	
	cout << endl;
	int elem;
	if(fibon_elem(pos, elem))
		cout << elem << endl;
	
	return 0;
}