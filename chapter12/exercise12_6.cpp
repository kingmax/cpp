#include <iostream>
#include <vector>
#include <memory>
using namespace std;

vector<int> *newVec(int cnt=1)
{
	return new vector<int>(cnt);
}

void input(vector<int> &vec)
{
	int x;
	cout << "Enter integer:" << endl;
	while(cin >> x && x != 0)
		vec.push_back(x);
}

void input(vector<int> *pv)
{
	int x;
	/* cout << "enter integer2:" << endl;
	cout << x << endl; */
	while(cin >> x)
		pv->push_back(x);
	pv = nullptr;
}

void output(vector<int> *pv)
{
	for(const auto &i : *pv)
		cout << i << ' ';
	cout << endl;
	/* delete pv; */
	pv = nullptr;
}

shared_ptr<int> clone(int p)
{
	//return new int(p); //Error
	return shared_ptr<int>(new int(p));
}

int main()
{
	vector<int> *pv = newVec();
	vector<int> &vec = *pv;
	input(vec);
	
	cout << "using input(vector<int>*)" << endl;
	input(pv);
	
	output(pv);
	
	delete pv; //free once!
	
	int *q = new int(121), *r = new int(100);
	r = q; //old r hold memory missing!!! can not free!
	
	auto q2 = make_shared<int>(121), r2 = make_shared<int>(100);
	r2 = q2; //old r2 pointed memory auto free.
	
	//mixed shared_ptr and ptr
	shared_ptr<int> p(new int(101));
	cout << *p << endl;
	
	return 0;
}