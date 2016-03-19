#include <stdio.h>
#include <stdlib.h>

char mapa[103][103];

int main(void)
{
	int N, i, j, comida = 0, maior = 0;
	scanf("%d", &N);

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("\n%c", &mapa[i][j]);
		}
	}
	
	for(i=0;i<N;i++)
	{
		if(i % 2 == 0)
		{
			for(j=0;j<N;j++)
			{
				if(mapa[i][j] == 'o')
				{
					comida++;
				}
				else
				{
					if(mapa[i][j] == 'A')
					{
						if(comida>maior)maior = comida;
						comida = 0;
					}
				}
			}
		}
		else
		{
			for(j=N-1;j>=0;j--)
			{
				if(mapa[i][j] == 'o')
				{
					comida++;
				}
				else
				{
					if(mapa[i][j] == 'A')
					{
						if(comida>maior)maior = comida;
						comida = 0;
					}
				}
			}
		}
	}

	if(comida>maior)maior = comida;

	printf("%d\n", maior);
	return 0;
}