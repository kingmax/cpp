#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

template<typename T>
void mySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

void bubble_sort(vector<int> &v, ofstream *out_debug = 0)
{
	for(int i = 0; i < v.size(); ++i)
		for(int j = i+1; j < v.size(); ++j)
		{
			if(v[i] > v[j])
			{
				mySwap<int>(v[i], v[j]);
				if(out_debug)
					(*out_debug) << "about to call mySwap<int>! i:" << i
						<< " j:" << j << "\tmySwapping:"
						<< v[i] << " with " << v[j] << endl;
			}
		}
}

void display(const vector<int> &v, ostream &os = cout)
{
	//os << "in display(const vector<int>&, ostream&)" << endl;
	//for(const auto &e : v)
	for(auto &e : v)
		os << e << ' ';
	os << endl;
}

#define seperator() (cout << string(40, '-') << endl)

int main()
{
	int ia[8] = {8, 32, 3, 13, 1, 21, 5, 2};
	vector<int> vec(ia, ia+8);
	
	display(vec);
	//cout << string(40, '-') << endl;
	seperator();
	
	bubble_sort(vec);
	display(vec);
	//cout << string(40, '-') << endl;
	seperator();
	
	ofstream debug("debug.txt");
	
	bubble_sort(vec, &debug);	// pointer
	display(vec, debug);		// reference
	//cout << string(40, '-') << endl;
	seperator();
	
	//debug.close();
	
	return 0;
}