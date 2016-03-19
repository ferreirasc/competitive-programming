#include <stdio.h>

int main(void)
{
	int N, i, cont;
	scanf("%d", &N);
	int vet[N], vet2[N];
	
	for(i=0; i<N; i++)
	{
		scanf("%d", &vet[i]);
	}
	
	for(i=0; i<N; i++)
	{
		cont = 0;
		if(vet[i])cont++;
		if(i!=(N-1) && vet[i+1])cont++;
		if(i!=0 && vet[i-1])cont++;
		vet2[i] = cont;
		printf("%d\n", vet2[i]);
	}
	
	return 0;
}