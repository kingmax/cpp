#include <string>
#include <iostream>
#include <regex>
using namespace std;

int main()
{
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern);
	smatch results;
	string test_str = "receipt freind theif receive";
	if(regex_search(test_str, results, r))	// 找到一个就停止,只输出freind
		cout << results.str() << endl;
	
	/*
	cout << "input filename *.(cpp|cxx|cc):";
	regex r2("[[:lanum:]]+\\.(cpp|cxx|cc)$", regex::icase);
	smatch matches;
	string filename;
	do
	{
		if(regex_search(filename, matches, r2))
			cout << matches.str() << endl;
	}
	while(cin >> filename);
	*/
	
	cout << endl;
	try
	{
		regex r3("[[:lanum:]+\\.(cpp|cxx|cc)$", regex::icase);
	}
	catch(regex_error e)
	{
		cout << e.what() << "\ncode: " << e.code() << endl;
	}
		
	return 0;
}