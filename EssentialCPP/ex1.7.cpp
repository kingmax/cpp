#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	const string file = "ex1.7.cpp";
	ifstream in_file(file);
	if(!in_file)
	{
		cerr << "cann't read " << file << endl;
		return -1;
	}
	
	vector<string> words;
	string word;
	while(in_file >> word)
	{
		cout << word << ", ";
		words.push_back(word);
	}
	in_file.close();
	
	sort(words.begin(), words.end());
	
	ofstream outFile("sorted.txt");
	if(!outFile)
	{
		cerr << "create outFile (sorted.txt) failed!" << endl;
		return 1;
	}
	
	for(auto &w : words)
		outFile << w << " ";
	outFile.flush();
	
	outFile.close();
	cout << "output to file done!" << endl;
	
	return 0;
}