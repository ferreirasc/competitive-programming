#include <stdio.h>
#include <math.h>

int main(void)
{
	register int i;
	unsigned long long int N;
	scanf("%llu", &N);	
	if(N<1 || N>10000000000)return 0;
	
	if(N==1 || N==2 || N==3)
	{
	printf("N\n");
	return 0;
	}

	if(N>2 && N<=10000000000 && (N%2==0 || N%3==0))
	{
	printf("S\n");
	return 0;
	}
	
		for(i=3;i<=sqrt(N);i+=2)
		{
			if(N%i==0)
			{
			i=1;
			break;
			}
		}

		if(i!=1)printf("N\n");
		else printf("S\n");

	return 0;
}

