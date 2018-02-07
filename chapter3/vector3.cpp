#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<int> v{1,2,3,4,5,6,7,8,9};
	cout << "v.empty:" << v.empty() << endl;
	cout << "v.size: " << v.size() << endl;
	cout << "v[8]:	 " << v[8] << endl;
	for(auto &i : v)
		i *= i;
	for(int i : v)
		cout << i << ' ';
	cout << endl;
	
	vector<unsigned> scores(11, 0);
	unsigned grade;
	//42 65 95 100 39 67 95 76 88 76 83 92 76 93
	while(cin >> grade)
	{
		if(grade <= 100)
			++scores[grade/10];
	}
	for(auto n : scores)
		cout << n << ' ';
	cout << endl;
	
	for(decltype(scores.size()) index=0; index != scores.size(); ++index)
	{
		cout << (index*10) << ": \t" << scores[index] << " count" << endl;
	}
	
	return 0;
}