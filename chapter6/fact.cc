#include "chapter6.h"

int fact(int n)
{
	int ret = 1;
	while(n > 0)
		ret *= n--;
	return ret;
}