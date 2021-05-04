#include <stdio.h>

int main(int argc, char *argv[]) {
	int digitOf3;
	scanf("%d", &digitOf3);
	int a = digitOf3 / 100;
	int b = digitOf3 / 10 % 10;
	int c = digitOf3 % 10;
	//printf("a=%d, b=%d, c=%d\n", a, b, c);
	
	int revert = c * 100 + b * 10 + a;
	printf("%d", revert);
	return 0;
}
