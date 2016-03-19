#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pont
{
	int grandepremio[101];
}piloto;

int g, p, pos, s, k, pont, i, j, u, z=0, campeoes=1;
piloto pilotos[101];
int grid[101][101], score[101], campeao[101]; 

void maior_dos(int *score)
{
	int maior=-1, i;
	
	for(i=0;i<p;i++)
	{
		if(score[i]>maior)
		{
			campeao[z] = i+1;
			maior=score[i];
		}
	}
	
	for(i=0;i<p;i++)
	{
		if(score[i]==maior && campeao[z]!=(i+1))
		{
			z++;
			campeao[z] = i+1;
			maior=score[i];
			campeoes++;
		}
	}
	
}

int main(void)
{
	while(1)
	{
	scanf("%d %d", &g, &p);
	if(g==0 && p==0)return 0;
	for(i=0;i<g;i++)
	{
		for(j=0;j<p;j++)
		{
			scanf("%d", &pos);
			pilotos[j].grandepremio[i] = pos;
		}
	}
	
	scanf("%d", &s);
	
	for(i=0;i<s;i++)
	{
		scanf("%d", &k);
		for(j=0;j<k;j++)
		{
			scanf("%d", &pont);
			grid[i][j]=pont;
		}
	}
	
	for(i=0;i<s;i++)
	{
		for(u=0;u<g;u++)
		{
			for(j=0;j<p;j++)
			{
				score[j] += grid[i][(pilotos[j].grandepremio[u])-1];
			}
		}
		maior_dos(score);
		for(u=0;u<campeoes;u++)printf("%d ", campeao[u]);
		printf("\n");
		memset(score, 0, sizeof(score));
		memset(campeao, 0, sizeof(campeao));
		campeoes=1; z=0;
	}
	memset(grid, 0, sizeof(grid));
	memset(pilotos, 0, sizeof(pilotos));
	memset(score, 0, sizeof(score));
	memset(campeao, 0, sizeof(campeao));
	campeoes=1; z=0;
	}
	return 0;
}
	