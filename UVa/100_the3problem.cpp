/* Pra passar esse código, só verificar as condições em que N > M.... flw vlw */

#include <stdio.h>

using namespace std;

long int memoization[1000002];
long int cont = 0, maior = 0;

long int dump(long int i)
{
	if(i<1000000)
	{
		if(memoization[i]!=0)
		{
			return (cont + memoization[i]);
		}
	}

	if(i == 1)
	{
		cont++;
		return cont;
	}

	if(i % 2 == 1)
	{
		i = 3*i + 1;
		cont++;
		dump(i);
	}
	else
	{
		i = i/2;
		cont++;
		dump(i);
	}
}

int main(void)
{
	long int N, M;
	
	while(scanf("%ld %ld", &N, &M)!=EOF)
	{
		maior = 0;
		for(long int i=N;i<=M;i++)
		{
			memoization[i] = dump(i);
			if(memoization[i] > maior)
			{
				maior = memoization[i];
			}
			cont = 0;
		}
		printf("%ld %ld %ld\n", N, M, maior);
	}
	return 0;
}
