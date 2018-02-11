#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int a = 1, b = 2;
	cout << a << ' ' << b << endl;
	if(a != b)
		a = b;
	else
		a = b = 0;
	cout << a << ' ' << b << endl;
	cout << endl;
	
	int grade = 98;
	string lettergrade;
	const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
	if(grade < 60)
		lettergrade = scores[0];
	else
	{
		lettergrade = scores[(grade-50)/10];
		if(grade != 100)
		{
			int mod = grade % 10;
			(mod < 3) ? (lettergrade += "-") : ((mod > 7) ? (lettergrade += "+") : lettergrade);
		}
	}
	cout << grade << ' ' << lettergrade << endl;
	
	unsigned aCnt(0), eCnt(0), iCnt(0), oCnt(0), uCnt(0), otherCnt(0);
	char ch;
	while(cin >> ch)
	{
		switch(ch)
		{
			case 'a':
			case 'A':
				++aCnt;
				break;
			case 'e':
			case 'E':
				++eCnt;
				break;
			case 'i':
			case 'I':
				++iCnt;
				break;
			case 'o':
			case 'O':
				++oCnt;
				break;
			case 'u':
			case 'U':
				++uCnt;
				break;
			default:
				++otherCnt;
				break;
		}
	}
	cout << "Number of vowel a: \t" << aCnt << endl
		 << "Number of vowel e: \t" << eCnt << endl
		 << "Number of vowel i: \t" << iCnt << endl
		 << "Number of vowel o: \t" << oCnt << endl
		 << "Number of vowel u: \t" << uCnt << endl;
	
	
	return 0;
}