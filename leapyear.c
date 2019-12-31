#include <windows.h>
#include <wchar.h>
#include <stdbool.h>

bool isLeapYear(int);

int wmain()
{
	int years[] = {2000, 2002, 2004, 2008, 2012, 2016, 2020, 
		1900, 1800, 1600};
		
	int size = sizeof(years) / sizeof(years[0]);
	for(int i = 0; i<size; i++)
	{
		if(isLeapYear(years[i]))
			wprintf(L"%ld is a leap year\n", years[i]);
		else
			wprintf(L"%ld is not a leap year\n", years[i]);
	}
	
	return 0;
}

bool isLeapYear(int year)
{
	if(year % 4 != 0)
	{
		return false;
	}
	else if(year % 400 == 0)
	{
		return true;
	}
	else if(year % 100 == 0)
	{
		return false;
	}
	else
		return true;
}