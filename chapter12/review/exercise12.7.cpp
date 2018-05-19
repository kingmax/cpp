#include <iostream>
#include <vector>
#include <memory>
using namespace std;

shared_ptr<vector<int>> get_ivec()
{
	return make_shared<vector<int>>();
}

void put_ivec(shared_ptr<vector<int>> sp)
{
	int x;
	while(cin >> x)
		sp->push_back(x);
}

void out_ivec(shared_ptr<vector<int>> sp)
{
	for(int x : (*sp))
		cout << x << ' ';
	cout << endl;
}

int main()
{
	shared_ptr<vector<int>> p = get_ivec();
	cout << p << endl;
	cout << "input integer:" << endl;
	put_ivec(p);
	cout << "output:" << endl;
	out_ivec(p);
	cout << p->size() << endl;
	return 0;
}