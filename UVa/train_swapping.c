#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int K, i, j, k, N, aux;
	scanf("%d", &K);
	for(k=0;k<K;k++)
	{
		scanf("%d", &N);
		int vet[N], cont = 0;
		for(j=0;j<N;j++)
		{
			scanf("%d", &vet[j]);
		}

		for(i=0;i<N;i++)
		{
			for(j=i+1;j<N;j++)
			{
				if(vet[i]>vet[j])
				{
					aux = vet[i];
					vet[i] =  vet[j];
					vet[j] = aux;
					cont++;
				}
			}
		}

		printf("Optimal train swapping takes %d swaps.\n", cont);
	}
	return 0;
}
