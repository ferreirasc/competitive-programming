#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N,i, cont = 1, maior = 0;
	scanf("%d", &N);
	int vetor[N];

	scanf("%d", &vetor[i]);

	for(i=1;i<N;i++)
	{
		scanf("%d", &vetor[i]);
		if(vetor[i]==vetor[i-1])cont++;
		else cont = 1;
		if(cont>maior)maior = cont; 
	}
	
	printf("%d\n", maior);
	return 0;
}
