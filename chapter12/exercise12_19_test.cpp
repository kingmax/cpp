#include "exercise12_19.h"
#include <iostream>

#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	//cl /EHsc exercise12_19_test.cpp exercise12_19.cpp
	
	StrBlob blob = {"hi", "jason", "welcome", "here"};
	cout << blob.size() << endl;
	StrBlobPtr beg = blob.begin();
	while(beg != blob.end())
	{
		cout << beg.deref() << endl;
		beg.incr();
	}
	
	cout << endl;
	//exercise12.20
	if(argc != 2)
	{
		cerr << "usage:exercise12_19_test.exe infile" << endl;
		return -1;
	}
	
	ifstream fp(argv[1]);
	if(!fp)
	{
		cerr << "Couldn't open file -> " << argv[1] << endl;
		return -2;
	}
	StrBlob blob2;
	while(!fp.eof())
	{
		string line;
		getline(fp, line);
		if(!line.empty())
			blob2.push_back(line);
	}
	fp.close();
	
	cout << "\nStrBlob blob2.size: " << blob2.size() << endl;
	cout << "using StrBlobPtr output:\n" << endl;
	for(auto beg = blob2.begin(); beg != blob2.end(); beg.incr()/* ++beg */)
	{
		cout << /* *beg */ beg.deref() << endl;
	}
	
	return 0;
}