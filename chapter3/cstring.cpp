#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	//char ca[] = {'C', '+', '+'}; //error, not '\0'!!!
	char ca[] = {'C', '+', '+', '\0'};
	cout << strlen(ca) << endl; //3
	
	const char ca1[] = "A string example";
	const char ca2[] = "A different string";
	//if(ca1 < ca2) //error, array is ptr
	int cmpResult = strcmp(ca1, ca2);
	if(cmpResult < 0 )
		cout << "ca1 < ca2" << endl;
	else if(cmpResult > 0)
		cout << "ca1 > ca2" << endl;
	else
		cout << "ca1 == ca2" << endl;
	
	char ca3[100];
	strcpy(ca3, ca1);
	strcat(ca3, " ");
	strcat(ca3, ca2);
	for(auto s : ca3)
		cout << s;
	cout << endl;
	
	return 0;
}