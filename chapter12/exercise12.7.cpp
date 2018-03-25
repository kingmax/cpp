#include <iostream>
#include <vector>
#include <memory>
using namespace std;

shared_ptr<vector<int>> make_vec()
{
	return make_shared<vector<int>>();
}

void read(shared_ptr<vector<int>> &p)
{
	cout << "enter interge:" << endl;
	int x;
	while(cin >> x)
		p->push_back(x);
}

ostream &print(shared_ptr<vector<int>> &p)
{
	for(const auto &i : *p)
		cout << i << ' ';
	cout << endl;
	return cout;
}

int main()
{
	shared_ptr<vector<int>> vec = make_vec();
	
	read(vec);
	
	print(vec) << endl;
	
	return 0;
}