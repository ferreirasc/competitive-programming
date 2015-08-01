#include <stdio.h>
#include <queue>
#include <map>
#include <string.h>
#include <vector>

using namespace std;

typedef struct edge
{
	int n;
	int TTL;
}edge;

vector<int> graph[3000];
queue<edge> fila;
int visitado[3000];
int cont = 0;
map<long int,int> mapa;

int main(void)
{
	int N, indice = 0;
	for(int t=1;;)
	{
		scanf("%d", &N);
		if(N==0)break;
		for(int i=0;i<N;i++)
		{
			int n, m;
			scanf("%d %d", &n, &m);
			if(mapa.find(n) == mapa.end())
			{
				mapa[n] = ++indice;
			}
			if(mapa.find(m) == mapa.end())
			{
				mapa[m] = ++indice;
			}
			int a = mapa[m];
			int b = mapa[n];
			graph[a].push_back(b);
			graph[b].push_back(a);
		}	

		for(;;t++)
		{
			int m;
			long int n;
			scanf("%ld %d", &n, &m);
			if(n==0 && m==0)break;
			
			if(mapa.find(n)==mapa.end())
			{
				printf("Case %d: %d nodes not reachable from node %ld with TTL = %d.\n", t, indice, n, m);
				continue;
			}

			edge p;
			int valor = mapa[n];
			p.n = mapa[n];
			p.TTL = m;
			fila.push(p);
			visitado[mapa[n]] = 1;
		
			//BFS...
			while(!fila.empty())
			{
				int tam = graph[valor].size();
				if(fila.front().TTL!=0)
				{
					for(int i=0;i<tam;i++)
					{
						int prox = graph[valor][i];
						if(!visitado[prox])
						{
							visitado[prox] = 1;
							edge u;
							u.n = prox;
							cont++;
							u.TTL = fila.front().TTL - 1;
							fila.push(u);
						}
					}
				}
				fila.pop();
				valor = fila.front().n;
			}

			printf("Case %d: %d nodes not reachable from node %ld with TTL = %d.\n", t, indice - cont - 1, n, m);
		
			memset(visitado,0,sizeof(visitado));
			cont = 0;
		}

		getchar();
		mapa.clear();
		for(int i=0;i<3000;i++)
		{
			graph[i].clear();
		}
		indice = 0;
	}
	

	return 0;
}
