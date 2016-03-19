#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

vector<int> adj[102];

int cont=0, maior=-1, visitado[102];

int dfs(int p)
{
	int grau = adj[p].size();
	visitado[p]=1;
	for(register int i=0;i<grau;i++)
	{
		int prox = adj[p][i];
		if(!visitado[prox])
		{
			cont++;
			dfs(prox);
		}
	}
	return 0;
}

int main(void)
{
	int n, T, indice_maior, m;
	register int j, i;
	while(1)
	{
		scanf("%d", &n);
		if(n==0)return 0;
		for(i=0;i<n;i++)adj[i].clear();
		memset(visitado, 0, sizeof(visitado));
		for(i=0; i<n; i++)
		{
			scanf("%d", &T);
			for(j=0; j<T; j++)
			{
				scanf("%d", &m);
				m--;
				adj[i].push_back(m);
			}
		}
		
		for(i=0;i<n;i++)
		{
			dfs(i);
			if(cont>maior){maior=cont;indice_maior=i;}
			memset(visitado, 0, sizeof(visitado));
			cont=0;
		}
		
		printf("%d\n", indice_maior+1);
		maior=-1;
	}
	return 0;
}