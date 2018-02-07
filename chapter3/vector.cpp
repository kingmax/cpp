#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<int> v1;
	vector<int> v2(v1);	  //copy v1 to v2
	vector<int> v3 = v1;  //copy v1 to v3
	vector<int> v4(10, 0);//count 10
	vector<int> v5(5);	  //count 5
	vector<int> v6{1,2,3,4,5};
	vector<int> v7 = {1,2,3,4};
	
	//vector<string> svector(v7); //error
	vector<string> svec;
	vector<string> articles = {"a", "an", "the"};
	//vector<string> sv3("a", "an", "the"); //error
	for(auto word : articles)
		cout << word << endl;
	
	vector<int> iv(10, -1);
	for(auto x : iv)
		cout << x << ' ';
	cout << endl;
	
	vector<string> sv(10, "hi!");
	for(auto s : sv)
		cout << s << ' ';
	cout << endl << endl;
	
	vector<int> va(10); //count 10, init to 0
	for(auto i : va)
		cout << i << ' ';
	cout << endl;
	vector<int> vb{10}; //count 1, only one element is 10
	for(auto i : vb)
		cout << i << ' ';
	cout << endl << endl;
	
	vector<int> vc(10,1);//count 10, init val is 1
	for(auto i : vc)
		cout << i << ' ';
	cout << endl;
	vector<int> vd{10,1};//count 2, 2 elements: 10 and 1
	for(auto i : vd)
		cout << i << ' ';
	cout << endl;
	
	vector<string> vs1{"hi"}; //one element is hi
	//vector<string> vs2("hi"); //error, can't using literal init string vector
	vector<string> vs3{10};	  //10 elements ""
	vector<string> vs4{10, "hi"};//10 hi
	
	vector<vector<int>> mvec; //2d vector
	vector<string> vs5(10, "null");
	for(string s : vs5)
		cout << s << ' ';
	cout << endl;
	
	return 0;
}