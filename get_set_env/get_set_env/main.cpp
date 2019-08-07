#include <cstdlib>
#include <iostream>
using namespace std;

//´íÎó	C4996	'getenv': This function or variable may be unsafe.Consider using _dupenv_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.get_set_env	d : \git\cpp\get_set_env\get_set_env\main.cpp	8
#pragma warning(disable:4996)

// https://stackoverflow.com/questions/17258029/c-setenv-undefined-identifier-in-visual-studio
int setenv(const char *name, const char *value, int overwrite)
{
	int errcode = 0;
	if (!overwrite) {
		size_t envsize = 0;
		errcode = getenv_s(&envsize, NULL, 0, name);
		if (errcode || envsize) return errcode;
	}
	return _putenv_s(name, value);
}


int main()
{
	const char* env = "PYTHONPATH";
	char* val = getenv(env);

	if (val != NULL)
	{
		cout << env << " = " << val << endl;
	}

	cout << setenv("mytest", "TST", 0) << endl; 

	system("pause");
	return 0;
}