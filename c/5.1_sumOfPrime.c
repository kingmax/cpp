// https://www.icourse163.org/learn/ZJU-199001?tid=1463264446#/learn/ojhw?id=1237097070
#include <stdio.h>
#include <math.h>

/*
* param n: int n >= 0
* return 1 or 0
* 1: is prime, 0: is not prime
*/
int isPrime(int n)
{
	if(n <= 1) return 0;
	if(n == 2) return 1;
	
	int ret = 1;
//	if(n > 2)
	{
		int i;
		for(i=2; i<=sqrt(n); i++)
//		for(i=2; i<n; i++)
		{
			if(n % i == 0)
			{
				ret = 0;
				break;
			}
		}
	}
	
//	if(ret) printf("\nn(%d)is prime\n", n);
	return ret;
}


int *get200PrimeList()
{
	static int ret[200] = {0,};
	int i=0, j=2;
	while(i < 200)
	{
		if(isPrime(j))
		{
			ret[i] = j;
			i++;
		}
		j++;
	}
	return ret;
}

int main()
{
	int *p = get200PrimeList();
//	int i;
//	for(i=0; i<200; i++)
//	{
//		printf("%d\t", *(p + i));
//	}

	//printf("%s\n", "hello, world");
	int n, m; // 0 < n <= m <= 200
//	printf("enter n, m (0<n<=m):\n");
	// enter n, m
	scanf("%d %d", &n, &m);
	
	int sum = 0;
//	while(n <= m)
//	{
//		printf("%d\t", n);
//		if(isPrime(n))
//		{
////			printf("\tn=%d", n);
//			sum += n;
//		}
//		n++;
//	}
//	printf("\nsum is:");
//	printf("%d", sum);
	
	for(;n<=m;n++)
	{
		sum += *(p + n -1);
	}
	printf("%d", sum);
	
	return 0;
}
