#include <stdio.h>

int main()
{
	const int AMOUNT=100;
	double price;
	printf("input price please:\n");
	scanf("%lf", &price);
	printf("give you change: %f\n", AMOUNT-price);
	return 0;
}
