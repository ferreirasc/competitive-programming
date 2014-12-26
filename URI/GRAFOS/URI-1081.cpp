#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int adj[30][30];
int visitados[30];
int V, E, flag = 0;

void dfs(int p, int cont)
{
	cont+=2;
	visitados[p]=1;
	for(int i=0;i<V;i++)
	{
		if(adj[p][i])
		{
			flag = 1;
			for(int j=0;j<cont;j++)printf(" ");
			printf("%d-%d", p, i);
			if(!visitados[i])
			{
				printf(" pathR(G,%d)\n", i);
				dfs(i,cont);
			}
			else
			{
				printf("\n");
			}
		}
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int k=0;k<t;k++)
	{
		printf("Caso %d:\n", k+1);
		scanf("%d %d", &V, &E);
		int foo, bar;
		memset(adj,0,sizeof(adj));
		memset(visitados,0,sizeof(visitados));
		flag = 0;	
		for(int i=0;i<E;i++)
		{
			scanf("%d %d", &foo, &bar);
			adj[foo][bar]=1;
		}
	
		for(int i=0;i<V;i++)
		{
			if(!visitados[i])
			{
				dfs(i,0);
			}
			if(flag==1)
			{	
				printf("\n");
				flag = 0;
			}
		}
	}
	return 0;	
}
