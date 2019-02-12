#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

template <typename It, typename T>
auto find(It first, It last, const T &value)
{
	for(; first != last && *first != value; ++first);
	return first;
}

int main()
{
	vector<int> vec{1,2,3,4,5,6,7,8,9};
	auto found = vec.cend() != ::find(vec.cbegin(), vec.cend(), 9);
	cout << (found ? "true" : "false") << endl;
	
	found = vec.cend() != ::find(vec.cbegin(), vec.cend(), 10);
	cout << (found ? "true" : "false") << endl;
	
	list<string> words{"aa", "bb", "cc", "dd", "ee", "ff", "gg"};
	found = words.cend() != ::find(words.cbegin(), words.cend(), "aa");
	cout << (found? "True" : "False") << endl;
	
	return 0;
}