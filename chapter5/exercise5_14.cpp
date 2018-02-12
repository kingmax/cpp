#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;
	string most = "";
	string last = "";
	unsigned mostCnt = 1;
	unsigned lastCnt = 1;
	while(cin >> word)
	{
		if(word == last)
			++lastCnt;
		else
		{
			last = word;
			lastCnt = 1;
		}
		
		if(lastCnt >= mostCnt)
		{	
			mostCnt = lastCnt;
			most = last;
		}
	}
	if(mostCnt > 1)
		cout << "the most word is: " << most << ", times: " << mostCnt << endl;
	else
		cout << "no words continue.." << endl;
	
	return 0;
}