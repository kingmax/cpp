// https://www.icourse163.org/learn/ZJU-199001?tid=1463264446#/learn/ojhw?id=1237097070
#include <stdio.h>

int getN(int num)
{
	if(num < 10)
		return num;
	else
	{
		return getN(num/10);
	}
}

// https://stackoverflow.com/questions/41321533/how-to-extract-digits-from-a-number-from-left-to-right
// ERROR when num >= 11 numbers, eg:12345678901
void readN(int num, const char * ws[])
{
	if(num < 10)
		printf("%s", ws[num]);
	else
	{
		/*
			r(123)
				-> r(12)
					-> r(1) out:yi
				r(12) out: er
			r(123) out: san
		*/
		readN(num / 10, ws);
		printf(" %s", ws[num % 10]);
	}
}

int main()
{
	// enter -100 000 < number < 100 000
	int number;
	scanf("%d", &number);
	
	const char * fu = "fu";
	const char * words[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	
	if(number < 0)
	{
		printf("%s ", fu);
		number = -number;
	}
	
	readN(number, words);
	
//	if(number >= 10)
//	{
//		int last = number % 10;
//		while(number)
//		{
//			int n = getN(number);
//			if(number /= 10)
//			{
//				printf("%s ", words[n]);
//			}
//		}
//		printf("%s", words[last]);
//	}
//	else
//	{
//		printf("%s", words[number]);
//	}
	
//	printf("\n");
//	int n;
//	do
//	{
//		n = number / 10;
//		number /= 10;
//		printf("%d\t", n);
//	}while(n);
	
	return 0;
}
