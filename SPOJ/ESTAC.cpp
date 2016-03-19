#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash[10001];
int hashposicao[10001];
int estacionamento [1000];

int main()
{
	int c, n, q, p, contador = 0;	
	char letra;
	int carros;
	
	while(scanf("%d %d ", &c, &n) != EOF)
	{
		for(int m = 0; m < 10001; m++)
			hash[m] = -1;

		memset(hashposicao,0,sizeof(hashposicao));
		memset(estacionamento,0,sizeof(estacionamento));

		carros = 0;

		for(int i = 0; i < n; i++)
		{
			scanf("%c ", &letra);
			if(letra == 'C')
			{
				scanf("%d %d ", &p, &q);
				contador = 0;

				for(int j = 0; j < c; j++)
				{
					if(estacionamento[j] == 0)
						contador++;
					else 
						contador = 0;	

					if(contador == q)
					{
						hash[p] = q;
						hashposicao[p] = j;
						carros++;
						for(int k = j; k >= (j - q) + 1; k--)
						{
							estacionamento[k] = 1;
						}
						
						break;						
					}
					
						
				}
	
			}
			else
			{
				scanf("%d ", &p);
				if(hash[p] != -1)
				{
					int tam = hash[p];
					int pos = hashposicao[p];
					for(int l = pos; l >= pos - tam + 1; l--)
					{
						estacionamento[l] = 0;
					}

					hash[p] = -1;
					hashposicao[p] = 0;
				}
			}
		} 
		printf("%d\n", carros*10);
		

	} //END WHIL
	
	return 0;			
} //END MAIN
