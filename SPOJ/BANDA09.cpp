#include <stdio.h>

using namespace std;

int adj[105][105];

int main(void)
{
	int N, M, u, v, valor, maior = -1, bandai, bandaj, bandak;
	scanf("%d %d", &N, &M);
	
	for(int i=0;i<M;i++)
	{
		scanf("%d %d %d", &u, &v, &valor);
		u--; v--;
		adj[u][v] = adj[v][u] = valor;
	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(j!=i)
			{
				for(int k=0;k<N;k++)
				{
					if(k!=i && k!=j)
					{
						if((adj[j][k] + adj[i][j] + adj[k][i])>maior)
						{
							maior = (adj[j][k] + adj[i][j] + adj[k][i]);
							bandai = i+1;
							bandaj = j+1;
							bandak = k+1;
						}
					}
				}
			}
		}
	}
	
	printf("%d %d %d\n", bandai, bandaj, bandak);
	return 0;
}