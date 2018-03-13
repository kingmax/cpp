#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	const string txt = "the quick red fox jumps over the slow red turtle   ";
	vector<string> words;
	string::size_type start = 0, pos = 0;
	
	while((pos = txt.find(" ", start)) != string::npos)
	{
		string s = txt.substr(start, pos - start);
		if(!s.empty())
			words.push_back(txt.substr(start, pos-start));
		start = pos + 1;
	}
	string s = txt.substr(start, -1);
	if(!s.empty())
		words.push_back(s);
	
	cout << words.size() << endl;
	for(const auto &w : words)
		cout << w << ' ';
	cout << endl;
	
	//exercise10.20
	unsigned int cnt = 0;
	count_if(words.cbegin(), words.cend(), [&cnt](const string &s)->unsigned{if(s.size() >= 4) ++cnt; return cnt;});
	cout << "length more than 4 word(s) count: " << cnt << endl;
	
	//exercise10.21
	int n = 10;
	auto lambda_expr = [&n]()->bool{while(n){cout << --n << endl;} return n > 0;};
	cout << "before call lambda, n = " << n << endl;
	if(lambda_expr())
		cout << "lambda run.." << endl;
	else
		cout << "lambda return false" << endl;
	cout << "after call lambda once, n = " << n << endl;
	cout << "call lambda again:" << endl;
	if(lambda_expr())
		cout << "lambda run.." << endl;
	else
		cout << "lambda return false" << endl;
	cout << n << endl;
	
	return 0;
}