#include "pch.h"
#include "LoadThis.h"


void usage()
{
	cout << "LoadThis 3dsMaxVersion (2010..2020)" << endl;
}


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		usage();
		return -1;
	}

	::ShowWindow(::GetConsoleWindow(), SW_HIDE);

	Kill3dsMax();

	string ver(argv[1]);
	string msg = "LoadThis for 3dsMax " + ver;
	cout << msg << endl;
	
	//2010
	if (ver == "2010")
	{
		try
		{
			LoadThis2010();
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
	}

	//2011
	if (ver == "2011")
	{
		try
		{
			LoadThis2011();
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
	}

	if (ver == "2012")
	{
		try
		{
			LoadThis2012();
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
	}

	cout << "DONE!" << endl;
	return 0;
}
