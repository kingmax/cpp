#include <iostream>
#include <vector>
using namespace std;

// < 10
vector<int> less_than_10(const vector<int> &vec)
{
	vector<int> nvec;
	for(int i=0; i<vec.size(); ++i)
		if(vec[i] < 10)
			nvec.push_back(vec[i]);
	return nvec;
}

// < any number
vector<int> less_than(const vector<int> &vec, int val)
{
	vector<int> vi;
	for(int x : vec)
		if(x < val)
			vi.push_back(x);
	return vi;
}

// any operator
vector<int> filter(const vector<int> &vec, int val, bool (*pred)(int,int))
{
	vector<int> vi;
	for(int x : vec)
		if(pred(x, val))
			vi.push_back(x);
	return vi;
}

bool less_than(int v1, int v2){ return v1 < v2 ? true : false; }
bool greater_than(int v1, int v2){return v1>v2 ? true : false;}

void print_vec(const vector<int> &vec)
{
	for(auto &x : vec)
		cout << x << ", ";
	cout << endl;
}

int main()
{
	vector<int> big_vec = {1, 20, 3, 40, 5, 60, 7};
	int val = 10;
	
	cout << "less_than_10:" << endl;
	vector<int> lt_10 = less_than_10(big_vec);
	print_vec(lt_10);
	
	cout << "\nless_than any(10):" << endl;
	vector<int> lt_10b = less_than(big_vec, 10);
	print_vec(lt_10b);
	
	cout << "\nfilter:" << endl;
	vector<int> lt_5 = filter(big_vec, 5, less_than);
	print_vec(lt_5);
	vector<int> gt_10 = filter(big_vec, 10, greater_than);
	print_vec(gt_10);
	
	return 0;
}