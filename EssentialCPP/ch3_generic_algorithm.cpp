#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

// only for fibnacci
bool grow_vec(vector<int> &vec, int elem)
{
	vector<int> temp(vec.size());
	copy(vec.begin(), vec.end(), temp.begin());
	sort(temp.begin(), temp.end());
	int max_value = temp.empty() ? 0 : temp[temp.size()-1];
	if( max_value == elem )
		return true;
	if( max_value < elem )
	{
		// grow the vec?
		return false;
	}
	return false;
}

bool is_elem(vector<int> &vec, const int elem)
{
	int max_value = *std::max_element(vec.cbegin(), vec.cend());
	if ( max_value < elem )
		return grow_vec(vec, elem);
	
	if ( max_value == elem )
		return true;
	
	return binary_search(vec.cbegin(), vec.cend(), elem);
}



int main()
{
	int myints[] = {3, 7, 2, 5, 6, 4, 9};
	cout << "the smallest element is " << *std::min_element(myints, myints+(sizeof(myints)/sizeof(int))) << endl;
	cout << "the largest element is: " << *std::max_element(myints, myints+7) << endl;
	
	return 0;
}