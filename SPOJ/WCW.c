#include <stdio.h>
#include <stdlib.h>

int vet[10002], cont=0;

int main(void)
{
	int T, N, i, j, aux;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		scanf("%d", &N);
		for(j=0;j<N;j++)
		{
			scanf("%d", &vet[j]);
		}
		
		for(j=0;j<N;j++)
		{
			while(vet[j]!=(j+1))
			{
				aux = vet[j];
				vet[j] = vet[vet[j]-1];
				vet[aux-1] = aux;
				cont++;
			}
		}
			
		
		printf("%d\n", cont);
		cont = 0;
	}
	return 0;
}
			