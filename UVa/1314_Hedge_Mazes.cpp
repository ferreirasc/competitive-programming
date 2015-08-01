#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int rank[10005], parent[10005], cor[10005], dfsNum[10005];
int N, M, Q, num = 0;	
vector<int> graph[10005];

void reset()
{
	for(int i=0;i<N;i++)
	{
		graph[i].clear();
		rank[i] = cor[i] = dfsNum[i] = 0;
		parent[i] = i;
	}
}

int find(int x)
{
	if(parent[x]==x)return parent[x];
	return parent[x] = find(parent[x]);
}

void union_by_rank(int a, int b)
{
	int x = find(a), y = find(b);
	if(rank[x] < rank[y])
		parent[x] = y;
	else
	{
		parent[y] = x;
		if(rank[x] == rank[y])rank[x]++;
	}
}

int pontes( int u, int p ) 
{
	cor[u] = 1;
	dfsNum[u] = num++;
	int leastAncestor = num;
	int tam = graph[u].size();
	for(int v = 0;v < tam; v++) 
	{
		int prox = graph[u][v];
		if(prox != p) 
		{
			if(cor[prox] == 0) 
			{
				// (u,v) is a forward edge
				int rec = pontes(prox, u);
				if(rec > dfsNum[u])
				{
					//cout << "Bridge: " << u << " " << prox << endl;
					union_by_rank(u, prox);
				}
				leastAncestor = (leastAncestor <  rec) ? leastAncestor: rec;
			} 
			else 
			{
				// (u,v) is a back edge
				leastAncestor = (leastAncestor< dfsNum[prox]) ? leastAncestor : dfsNum[prox];
			}
		}
	}

	cor[u] = 2;
	return leastAncestor;
}

int main(void)
{
	while(1)
	{
		scanf("%d %d %d", &N, &M, &Q);
		if(N==0 && M==0 && Q==0)break;
		reset();
		for(int i=0;i<M;i++)
		{
			int o, d;
			scanf("%d %d", &o, &d);
			o--, d--;
			graph[o].push_back(d);
			graph[d].push_back(o);
		}

		pontes(0,-1);

		for(int i=0;i<Q;i++)
		{
			int start, end;
			scanf("%d %d", &start, &end);
			start--, end--;
			if(find(start) == find(end))printf("Y\n");
			else printf("N\n");
		}

		printf("-\n");
	}
	return 0;
}
