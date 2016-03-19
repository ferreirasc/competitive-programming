#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stack>
#include <vector>

using namespace std;
int numcidades, cont=0, visitados[6005], nao_pode[6005], marcados[6005];
vector<int> adj[6005];
stack<int> pilha;

void dfs(int p)
{	
	pilha.push(p);
	visitados[p]=1;
	int grau = adj[p].size();
	while(!pilha.empty())
	{
		for(register int i=0; i<grau; i++)
		{
				int prox = adj[p][i];
				if(!visitados[prox])
				{
				dfs(prox);
				if(marcados[prox]==1)nao_pode[p]=1;
				}
		}
		if(nao_pode[p]!=1){cont++;marcados[p]=1;}
		pilha.pop();
		return;
	}
}

int main(void)
{
	int n, k, l;
	register int i, j;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &numcidades);
		
		for (j = 0; j < numcidades; j++)adj[j].clear();
            
		memset(visitados, 0, sizeof(visitados));
		memset(nao_pode, 0, sizeof(nao_pode));
		memset(marcados, 0, sizeof(marcados));
		
		for(j=0;j<numcidades-1;j++)
		{
			scanf("%d %d", &k, &l);
			k--;
			l--;
			adj[l].push_back(k);
            adj[k].push_back(l);

		}
		
		dfs(0);
		printf("%d\n", cont);
		cont=0;
		
	}
	
	return 0;
}