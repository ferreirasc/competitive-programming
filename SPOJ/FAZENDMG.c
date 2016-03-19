#include <stdio.h>
#include <stdlib.h>
#include <string.h>

short int mat[1600][1600];

int main(void)
{
	int N, X, Y, L, C, u, i, j, k, w, cont = 0, cont2 = 0, maiori = 0, maiorj = 0;
	while(1)
	{
		scanf("%d", &N);
		if(N==0)return 0;
		for(u=0;u<N;u++)
		{
			scanf("%d %d %d %d", &X, &Y, &L, &C);

			for(i=Y,k=0;k<C;i++,k++)
			{
				for(j=X,w=0;w<L;w++,j++)
				{
					if(!mat[i][j])
	 				{
						mat[i][j] = 1;
						cont++;
					}
				}
			}

			if((i-1)>maiori)maiori = i-1;
			if((j-1)>maiorj)maiorj = j-1;
		}
	
		for(i=0;i<=maiori;i++)
		{
			for(j=0;j<=maiorj;j++)
			{	
				if(mat[i][j])
				{
					if((i+1)>maiori || !mat[i+1][j])cont2++;
					if((j+1)>maiorj || !mat[i][j+1])cont2++;
					if((i-1)<0 || !mat[i-1][j])cont2++;
					if((j-1)<0 || !mat[i][j-1])cont2++;
				}
			}
		}
	
		printf("%d %d\n", cont, cont2);
		cont = 0, cont2 = 0, maiori = 0, maiorj = 0;
		memset(mat, 0, sizeof(mat));
	}
	return 0;
}