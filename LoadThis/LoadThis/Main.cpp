#include "pch.h"
#include "LoadThis.h"


void usage()
{
	cout << "LoadThis 3dsMaxVersion (2010..2020)" << endl;
}


int main(int argc, char* argv[])
{
	////////////////////temp testing
	//fs::path cd = fs::current_path();
	//cout << cd << endl;
	//const string vr = cd.filename().string(); // "V_Ray_Next__update_1_1";
	//cout << vr << endl;
	////cout << "Is VRay 3? " << (vr.find("V_Ray_Adv_3")==0 ? "Yes" : "No") << endl;
	////cout << "Is VRay 4? " << (vr.find("V_Ray_Next")==0 ? "Yes" : "No") << endl;
	//cout << "IsVRay3 ? " << IsVRay3() << endl;
	//cout << "IsVRay4 ? " << IsVRay4() << endl;

	//string path = (cd / "3ds Max 2013;").string();
	//cout << path << endl;
	//if (IsVRay4())
	//{
	//	path += (cd / "V-Ray\\3ds Max 2013\\bin;").string();
	//}
	//else
	//{
	//	path += (cd / "V-Ray\\RT for 3ds Max 2013 for x64\\bin;").string();
	//}
	//cout << path << endl;
	//path += path_env;
	//cout << path << endl;

	//cout << strlen(path_env.c_str()) << endl;
	//cout << path_env << endl;
	//wstring ws;
	//ws.assign(path_env.begin(), path_env.end());
	//wcout << ws << endl;
	//cout << lstrlen(ws.c_str()) << endl;
	//cout << sizeof(ws) << endl;
	//system("pause");
	//return 0;
	////////////////////end temp testing


	
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

	if (ver == "2013")
	{
		try
		{
			LoadThis2013();
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
	}

	cout << "DONE!" << endl;
	return 0;
}
