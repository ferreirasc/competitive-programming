#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int esquerdo[100], direito[100];

int main(void)
{
	int n, i, M, cont=0;
	char L;
	while(scanf("%d", &n)!=EOF)
	{
	
		for(i=0;i<n;i++)
		{
			scanf("%d %c", &M, &L);
			if(L=='D')direito[M]++;
			else if(L=='E')esquerdo[M]++;
			if(direito[M]>=1 && esquerdo[M]>=1)
			{
				direito[M]--;
				esquerdo[M]--;
				cont++;
			}
		}
		printf("%d\n", cont);
		cont = 0;
		memset(esquerdo,0,sizeof(esquerdo));
		memset(direito,0,sizeof(direito));
	}
	return 0;
}