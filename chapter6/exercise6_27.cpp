#include <iostream>
using namespace std;

int sumX(initializer_list<int> iparams)
{
	int ret = 0;
	for(auto beg=iparams.begin(); beg != iparams.end(); ++beg)
		ret += *beg;
	return ret;
}

int sumX(int errCode, initializer_list<int> params)
{
	int sum = 0;
	cout << "errCode:" << errCode << endl;
	//initializer_list element all are const!!!
	for(const auto &elem : params)
		sum += elem;
	return sum;
}

//return
void swap(int &a, int &b)
{
	if(a == b)
		return;
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	cout << sumX({100, 200}) << endl;
	cout << sumX({100, 200, 300}) << endl;
	
	cout << endl;
	cout << sumX(0, {400, 500, 600}) << endl;
	
	int a=100, b=200;
	cout << a << ' ' << b << endl;
	swap(a, b);
	cout << a << ' ' << b << endl;
	
	return 0;
}