#include <iostream>
using namespace std;

int main()
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	auto left = arr, right = end(arr);
	auto mid = left + (right - left)/2;
	int sought = 9;
	bool found = false;
	
	int times = 0;
	while(mid != right && !found)
	{
		if(*mid == sought)
		{
			found = true;
			break;
		}
		
		if(*mid < sought)
			left = mid;
		else
			right = mid;
		mid = left + (right - left)/2;
		
		cout << "mid now is: " << *mid << endl;
		++times;
	}
	
	if(found)
		cout << "found " << sought << " by " << times << " times\n";
	
	
	return 0;
}