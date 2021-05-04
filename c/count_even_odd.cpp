#include <stdio.h> 

int main()
{
	int x;
	int even=0, odd=0;
	scanf("%d", &x);
	while(x != -1)
	{
		if(x % 2)
			odd++;
		else
			even++;
	}
	printf("%d %d", odd, even);
	
	return 0;
}
