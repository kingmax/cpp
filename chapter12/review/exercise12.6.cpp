#include <iostream>
#include <vector>
#include <memory>
using namespace std;

vector<int> *get_vi()
{
	vector<int> *vi = new vector<int>();
	return vi;
}

void put_vi(vector<int> &vi)
{
	int x;
	while(cin >> x)
		vi.push_back(x);
}

void print_vi(vector<int> &vi)
{
	for(int x : vi)
		cout << x << ' ';
	cout << endl;
}

int main()
{
	vector<int> *vi = get_vi();
	put_vi(*vi);
	print_vi(*vi);
	
	delete vi;
	vi = nullptr;
	
	return 0;
}