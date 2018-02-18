#include <iostream>
#include <string>
#include <vector>
using namespace std;

void outputVector(const vector<string> &vs, int index = 0)
{
	#ifndef NDEBUG
		cerr << "index=" << index 
			 << ", vector.size: " << vs.size()
			 << ", __func__: " << __func__
			 << ", __LINE__: " << __LINE__ << endl << endl;
			 //<< ", __FILE__: " << __FILE__ << endl;
	#endif
	if(vs.size() == index)
		return;
	cout << vs[index++] << ' ';
	outputVector(vs, index);
}

int main()
{
	vector<string> vs = {"hi", "Jason", "hello", "world", "welcome"};
	outputVector(vs);
	
	return 0;
}