#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

istream &process_input(istream &input)
{
	auto state = input.rdstate();
	input.clear();
	vector<string> lines;
	while(!input.eof())
	{
		string s;
		input >> s;
		lines.push_back(s);
	}
	for(auto x : lines)
		cout << x << endl;
	input.setstate(state);
	return input;
}

int main(int argc, char **argv)
{
	cout << "enter any start testing..." << endl;
	process_input(cin);
	
	cout << "\nexercise8.9" << endl;
	istringstream iss("Hello, Jason, Welcom!");
	process_input(iss);
	
	return 0;
}