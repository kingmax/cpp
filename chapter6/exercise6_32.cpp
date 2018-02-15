#include <iostream>
#include <string>
#include <vector>
using namespace std;

int &get(int *array, int index)
{
	return array[index];
}

bool str_subrange(const string &str1, const string &str2)
{
	if(str1.size() == str2.size())
		return str1 == str2; //ok, return bool value
	
	auto size = str1.size() < str2.size() ? str1.size() : str2.size();
	for(decltype(size) i=0; i != size; ++i)
		if(str1[i] != str2[i])
			//return; //error
			return false;
		
	//need end return bool value
	return false;
}

void output_vector(vector<string> &vs)
{
	static int index = 0; //No reset!!!, only can call once!
	if(index != vs.size())
	{
		cout << vs[index++] << endl;
		output_vector(vs);
	}
}

void output_vector2(vector<string> &vs) //must be reference else param is copied!!!
{
	static auto beg = vs.begin();
	if(beg != vs.end())
	{
		cout << *beg++ << endl;
		output_vector2(vs);
	}
}

void output_vector(vector<string> &vs, int count)
{
	if(count == vs.size())
		return;
	cout << vs[count++] << endl;
	output_vector(vs, count);
}

int main()
{
	int ia[10];
	for(int i=0; i!=10; ++i)
		get(ia, i) = i;
	
	for(int i : ia)
		cout << i << ' ';
	cout << endl;
	
	vector<string> vs = {"hi", "jason"};
	output_vector(vs);
	
	cout << endl;
	vector<string> vs2 = {"hello", "world", "welcom", "jason"};
	output_vector2(vs2);
	
	//Not output yet, since static val in function!
	output_vector(vs);
	output_vector2(vs2);
	
	//this OKay
	cout << "ok" << endl;
	output_vector(vs, 0);
	cout << endl;
	output_vector(vs2, 0);
	cout << endl;
	output_vector(vs, 0);
	cout << endl;
	output_vector(vs2, 0);
	cout << endl;
	
	return 0;
}