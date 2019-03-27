#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void display(vector<int> &vec)
{
	for(int i = 0; i < vec.size(); ++i)
		cout << vec[i] << ' ';
	cout << endl;
}

void swap(int &v1, int &v2)
{
	int temp = v1;
	v1 = v2;
	v2 = temp;
}

ofstream out("debug.txt");
void bubble_sort(vector<int> &vec)
{
	for(int i = 0; i < vec.size(); ++i)
		for(int j = i + 1; j < vec.size(); ++j)
			if(vec[i] > vec[j])
			{
				out << "about to call swap!"
					<< " i: " << i << " j: " << j << "\t"
					<< " swapping: " << vec[i]
					<< " with " << vec[j] << endl;
				swap(vec[i], vec[j]);
			}
}

int main()
{
	int a = 9, b = 10;
	swap(a, b);
	cout << a << ' ' << b << endl;
	
	int ia[8] = {8, 34, 3, 13, 1, 21, 5, 2};
	vector<int> vec(ia, ia+8); //template<typename InputIt> vector(InputIt first, InputIt last)
	
	cout << "vector before sort: ";
	display(vec);
	
	bubble_sort(vec);
	
	cout << "vector  after sort: ";
	display(vec);
	
	return 0;
}