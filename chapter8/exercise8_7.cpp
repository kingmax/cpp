#include "Books_data.h"
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
	if(argc < 3)
	{
		cerr << "usage: exercise8_7.exe in_file out_file [append]" << endl;
		return -1;
	}
	
	Books_data total;
	ifstream in(argv[1]);
	//ofstream out(argv[2]);
	//exercise8.8 append to file
	ofstream out;
	if(argc > 3 && string(argv[3]) == "append")
	{
		cout << "Append mode" << endl;
		out.open(argv[2], ofstream::app);
	}
	else
		out.open(argv[2]);
	
	if(in && out && input(in, total))
	{
		Books_data trans;
		while(input(in, trans))
		{
			if(total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				output(out, total) << endl;
				total = trans;
			}
		}
		output(out, total) << endl;
	}
	else
	{
		cerr << "Couldn't open file: " << argv[1] << endl;
	}
	
	in.close();
	out.close();
	
	return 0;
}