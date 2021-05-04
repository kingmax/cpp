#include <stdio.h>

int main()
{
	int input;
	scanf("%d", &input);
	
	int right, pos=0, binary=0;
	while(input)
	{
		pos++;
		right = input % 10;
		input /= 10;
		if(right % 2)
			if(pos==1)
				binary = 1;
			
		
	}
	
	return 0;
}
