#include <stdio.h>

int main()
{
	double foot, inch;
	printf("please input foot inch\n");
	scanf("%lf %lf", &foot, &inch);
	printf("your are %f meters", (foot + inch / 12) * 0.3048 );
	return 0;
}
