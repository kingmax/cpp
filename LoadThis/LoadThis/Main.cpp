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

	//HKEY hKey;
	////LPCTSTR keyPath = TEXT("Environment");
	////LSTATUS lOpenStatus = RegOpenKeyEx(HKEY_CURRENT_USER, keyPath, 0, KEY_ALL_ACCESS, &hKey);
	//LPCTSTR keyPath = TEXT("System\\CurrentControlSet\\Control\\Session Manager\\Environment");
	//LSTATUS lOpenStatus = RegOpenKeyEx(/*HKEY_LOCAL_MACHINE*/HKEY_LOCAL_MACHINE, keyPath, 0, KEY_ALL_ACCESS, &hKey);
	//if (lOpenStatus == ERROR_SUCCESS)
	//{
	//	cout << "SUCCESS" << endl;
	//}
	//else
	//{
	//	cout << "open key failed" << endl;
	//}

	/*fs::path cd = fs::current_path();
	const string maxVersion = "2013";
	string path = (cd / string("3ds Max ").append(maxVersion).append(";")).string();
	cout << path << endl;
	cout << to_string(2013) << endl;*/
	/*cout << *GetPathEnvValue("2013");
	system("pause");
	return 0;*/
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

	//////////////////////////////////// 从2013开始，使用新的算法，针对VRay2~3 与 VRay Next (VRay4), 仅通过环境变量与ini文件方式实现
	// 本质上都是一样的处理，调用 LoadThis2013_2020(const string maxVersion)
	if (ver == "2013" ||
		ver == "2014" ||
		ver == "2015" ||
		ver == "2016" ||
		ver == "2017" ||
		ver == "2018" ||
		ver == "2019" ||
		ver == "2020"
		)
	{
		try
		{
			//LoadThis2013();
			LoadThis2013_2020(ver);
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
	}
	
/*
	if (ver == "2014")
	{
		try
		{
			LoadThis2014();
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
	}
	
	if (ver == "2015")
	{
		try
		{
			LoadThis2015();
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
	}
	
	if (ver == "2016")
	{
		try
		{
			LoadThis2016();
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
	}
	
	if (ver == "2017")
	{
		try
		{
			LoadThis2017();
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
	}
	
	if (ver == "2018")
	{
		try
		{
			LoadThis2018();
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
	}
	
	if (ver == "2019")
	{
		try
		{
			LoadThis2019();
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
	}
	
	if (ver == "2020")
	{
		try
		{
			LoadThis2020();
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
	}
*/

	//cout << "DONE!" << endl;
	return 0;
}
