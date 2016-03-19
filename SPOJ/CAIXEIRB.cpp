#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

vector<int> adj[302];

int visitado[301], valor_total=0, valores[301], cont_aux=0;

int dfs(int p)
{
	int grau = adj[p].size();
	visitado[p]=1;
	for(register int i=0;i<grau;i++)
	{
		int prox = adj[p][i];
		if(!visitado[prox])
		{
			cont_aux+=2;
			if(valores[prox]){
			valor_total+=cont_aux;cont_aux=0;
			}
			dfs(prox);
			if(cont_aux!=0)cont_aux-=2;
		}
	}
	
	return cont_aux;
}

int main(void)
{
	int n, T=0, indice_maior, m, k, l;
	register int j, i;
	while(1)
	{
		scanf("%d %d", &n, &m);
		if(n==0 && m==0)return 0;
		for(i=0;i<n;i++)adj[i].clear();
		memset(visitado, 0, sizeof(visitado));
		
		for(i=0; i<(n-1); i++)
		{
			scanf("%d %d", &k, &l);
			k--; l--;
			adj[k].push_back(l);
			adj[l].push_back(k);
		}
		
		for(i=0;i<m;i++)
		{
			scanf("%d", &k);
			if(k!=1)
			{
			k--;
			valores[k]=1;
			}
		}
		
		dfs(0);
		printf("Teste %d\n", T+1);
		printf("%d\n", valor_total);
		memset(valores, 0, sizeof(valores));
		valor_total=0;
		T++;
	}
	return 0;
}
