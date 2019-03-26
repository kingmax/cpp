#include <iostream>
#include <vector>
using namespace std;

void sum_of_arr()
{
	const int size = 100;
	int arr[size] = {0}; // ref: https://stackoverflow.com/questions/201101/how-to-initialize-all-members-of-an-array-to-the-same-value
	int x;
	int cnt = 0;
	
	
	cout << "input some interge(s) (cout <= 100, 0 for stop)" << endl;
	while(cin >> x && x != 0)
	{
		arr[cnt++] = x;
		if(cnt >= 100)
			break;
	}
	
	int sum = arr[0];
	for(int i = 1; i < cnt; i++)
		sum += arr[i];
	
	float average = sum * 1.0 / cnt;
	
	cout << "sum of Array[" << cnt << "] is: "
		<< sum << ", average is: " << average << endl;
}


int main()
{
	sum_of_arr();
	
	cout << endl;
	cout << "verctor<int> version:\n input int please(0 for stop):" << endl;
	
	vector<int> vec;
	int x;
	do
	{
		cin >> x;
		if(x != 0)
			vec.push_back(x);
	}
	while(x != 0);
	
	int sum = 0;
	for(auto &x : vec)
		sum += x;
	int size = vec.size();
	float average = sum * 1.0f / size;
	
	cout << "vector<int> sum is:" << sum 
		<< ", size = " << size
		<< ", average is: " << average << endl;
	
	
	return 0;
}