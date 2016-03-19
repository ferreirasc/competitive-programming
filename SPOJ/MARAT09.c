#include <stdio.h>

int main(void)
{
	int n, intermed, soma=0, aux=0, i, valor;
	scanf("%d %d", &n, &intermed);
	
	scanf("%d", &valor);
	
	for(i=1;i<n;i++)
	{
		scanf("%d", &valor);
		soma=aux+intermed;
		if(soma<valor){printf("N\n");return 0;}
		aux=valor;
	}
	
	if((aux+intermed)<42195){printf("N\n");return 0;}
	printf("S\n");
	return 0;
}