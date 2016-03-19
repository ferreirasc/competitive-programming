#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

int visitado[102], flag=0, cor[102], MAdj[102][102], n;

int bfs_identificando_biparticidade(int p)
{
	queue<int> fila;
	cor[p]=1;
	visitado[p] = 1;
	fila.push(p);
	
	while(!fila.empty())
	{
		for(int i=0;i<n;i++)
		{
			if(MAdj[(fila.front())][i])
			{
				if(cor[i]!=cor[fila.front()])
				{
					if(!visitado[i])
					{
						if(cor[(fila.front())] == 1)cor[i] = 2;
						else cor[i] = 1;
						visitado[i]=1;
						fila.push(i);
					}
				}
				else{
				flag=1;
				break;
				}
			}
		}
		if(flag==1){flag=0;return 0;}
		fila.pop();
	}
	return 1;
}
	

int main(void)
{
	int m, k, l, u=0;
	while(scanf("%d %d", &n, &m)!=EOF)
	{
		for(int i=0;i<m;i++)
		{
			scanf("%d %d", &k, &l);
			k--; l--;
			MAdj[k][l]=MAdj[l][k]=1;
		}
		
		if(bfs_identificando_biparticidade(0))
		{
			printf("Instancia %d\n", u+1);
			printf("sim\n");
		}
		else
		{
			printf("Instancia %d\n", u+1);
			printf("nao\n");
		}
		
		memset(MAdj, 0, sizeof(MAdj));
		memset(cor, 0, sizeof(cor));
		memset(visitado, 0, sizeof(visitado));
		u++;
	}
	
	return 0;
}