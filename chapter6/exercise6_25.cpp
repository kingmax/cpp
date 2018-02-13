#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	string args="";
	if(argc == 3)
	{
		for(int i=1; i<argc; ++i)
			args += argv[i]; //string(argv[i]);
	}
	cout << "arguments(1+2): " << args << endl;
	
	return 0;
}