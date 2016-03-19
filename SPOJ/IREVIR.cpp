#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

vector<int> adj[2002], adj2[2002];
int visitados[2002], n, cont=1;

void dfs(int p, int option)
{
	if(option==1)
	{
		int grau = adj[p].size();
	visitados[p]=1;
	for(register int i=0;i<grau;i++)
	{
		int prox = adj[p][i];
		if(!visitados[prox])
		{
			dfs(prox, 1);
		}
	}
		return;
	}
	
	if(option==2)
	{
		int grau = adj2[p].size();
	visitados[p]=1;
	for(register int i=0;i<grau;i++)
	{
		int prox = adj2[p][i];
		if(!visitados[prox])
		{
			dfs(prox, 2);
		}
	}
			return;
	}
}

int main(void)
{
	int m, v, w, p;
	
	while(1)
	{
	scanf("%d %d", &n, &m);
	if(n==0 && m==0)return 0;
	
	for(int i=0;i<n;i++)adj[i].clear();
	for(int i=0;i<n;i++)adj2[i].clear();
	
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d", &v, &w, &p);
		v--; w--;
		if(p==1)
		{
			adj[v].push_back(w);
			adj2[w].push_back(v);
		}
		else
		{
			if(p==2)
			{
				adj2[w].push_back(v); adj2[v].push_back(w);
				adj[w].push_back(v); adj[v].push_back(w);
			}
		}
	}
	
	dfs(0, 1);
	
	for(int i=0;i<n;i++)
	{
		if(visitados[i]==0){cont=0;break;}
	}
	
	if(cont==1)
	{
		memset(visitados, 0, sizeof(visitados));
		dfs(0, 2);
		
		for(int i=0;i<n;i++)
		{
			if(visitados[i]==0){cont=0;break;}
		}
		
	}
	
	if(cont==0)printf("0\n", cont);
	else printf("1\n", cont);
	
	cont=1;
	memset(visitados, 0, sizeof(visitados));
	}
	
	return 0;
}