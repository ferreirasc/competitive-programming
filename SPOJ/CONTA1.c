#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	
	if(N>=0 && N<=10)
	{
		printf("7\n");
		return 0;
	}

	if(N>=11 && N<=30)
	{
		int soma = 7;
		soma = soma + (N-11+1);
		printf("%d\n", soma);
		return 0;
	}

	if(N>=31 && N<=100)
	{
		int soma = 7;
		soma = soma + 20;
		soma = soma + (N-31+1)*2;
		printf("%d\n", soma);
		return 0;
	}

	if(N>=101)
	{
		int soma = 7;
		soma = soma + 20 + 70*2 + (N-101+1)*5;
		printf("%d\n", soma);
		return 0;
	}

	return 0;
}