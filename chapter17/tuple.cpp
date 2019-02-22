#include <iostream>
#include <tuple>
#include <vector>
#include <list>
using namespace std;

int main()
{
	tuple<size_t, size_t, size_t> threeD;
	tuple<string, vector<double>, int, list<int>>
		someValue("constants", {3.14, 2.718}, 100, {0,1,2,3});
		
	
	return 0;
}