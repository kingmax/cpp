#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vi;
	cout << "vec size: " << vi.size() //0
		 << ", vec capacity: " << vi.capacity() << endl; //0
		 
	for(vector<int>::size_type i = 0; i != 24; ++i)
		vi.push_back(i);
	cout << "vec size: " << vi.size() //24
		 << ", vec capacity: " << vi.capacity() << endl; //>24 (28)
		 
	vi.reserve(50);
	cout << "vec size: " << vi.size() //24
		 << ", vec capacity: " << vi.capacity() << endl; //50
	
	
	while(vi.size() != vi.capacity())
		vi.push_back(0);
	cout << "vec size: " << vi.size() //50
		 << ", vec capacity: " << vi.capacity() << endl; //50
		 
	vi.insert(vi.cbegin(), 100);
	cout << "vec size: " << vi.size() //51
		 << ", vec capacity: " << vi.capacity() << endl; //>51 (75)
		 
	vi.shrink_to_fit();
	cout << "vec size: " << vi.size() //51
		 << ", vec capacity: " << vi.capacity() << endl; //==51 or >51 (51)
		 
	vi.erase(vi.cbegin());
	cout << "vec size: " << vi.size() //50
		 << ", vec capacity: " << vi.capacity() << endl; //51
		 
	vi.clear();
	cout << "vec size: " << vi.size() //0
		 << ", vec capacity: " << vi.capacity() << endl; //51
		 
	vi.shrink_to_fit();
	cout << "vec size: " << vi.size() //0
		 << ", vec capacity: " << vi.capacity() << endl; //0
	
	return 0;
}