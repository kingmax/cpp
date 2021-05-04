#include <stdio.h>
//https://www.icourse163.org/learn/ZJU-199001?tid=1463264446#/learn/ojhw?id=1237096103
int main()
{
	int count;
	scanf("%d", &count);
	int i=1;
	for(; i<= count; i++)
	{
		if(i % 2)
		{
			if( i != count && i != count-1)
				printf("%d ", i);
			else
				printf("%d", i);
		}
	}
	return 0;
}
