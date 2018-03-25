#include <iostream>
#include <vector>
#include <memory>
using namespace std;

vector<int> *make_vec()
{
	return new vector<int>();
}

void read(vector<int> &vec)
{
	int x;
	while(cin >> x)
		vec.push_back(x);
}

ostream &print(const vector<int> &vec)
{
	for(const auto &i : vec)
		cout << i << ' ';
	cout << endl;
	return cout;
}

int main()
{
	vector<int> *p = make_vec();
	
	read(*p);
	
	print(*p);
	
	delete p;
	
	
	return 0;
}