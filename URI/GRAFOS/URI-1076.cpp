#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

queue<int> fila;

int main(void)
{
	int N, V, A, k, m,t;
	scanf("%d", &t);
	for(int j=0;j<t;j++)
	{
		scanf("%d", &N);
		scanf("%d %d", &V, &A);
		int visitados[V];
		vector<int> adj[V];
		memset(visitados,0,sizeof(visitados));
		int cont = 0;
		
		for(int i=0;i<V;i++)adj[i].clear();	
	
		for(int i=0;i<A;i++)
		{
			scanf("%d %d", &k, &m);
			adj[k].push_back(m);
			adj[m].push_back(k);
		}

		fila.push(N);
		visitados[N] = 1;	
	
		while(!fila.empty())
		{
			int grau = adj[fila.front()].size();
			for(int i=0;i<grau;i++)
			{
				int prox = adj[fila.front()][i];
				if(!visitados[prox])
				{
					visitados[prox]=1;
					fila.push(adj[fila.front()][i]);
					cont++;
				}
			}
			cont++;
			fila.pop();
		}
	
		printf("%d\n",cont-1);
	}
	return 0;
}
