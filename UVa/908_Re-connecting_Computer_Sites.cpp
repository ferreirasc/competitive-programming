#include <stdio.h>
#include <vector>
#include <algorithm>

#define NMAX 200005

using namespace std;

typedef struct Edge
{
	int o,d,p;
}Edge;

vector<Edge> edges;

int parent[NMAX], rank[NMAX], n, m, custo;

void reset()
{
	for(int i=0;i<NMAX;i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
	edges.clear();
}

int find(int x)
{
	if(parent[x]==x)return x;
	return parent[x] = find(parent[x]);
}

void union_rank(int a, int b)
{
	int x = find(a), y = find(b);
	if(rank[x] < rank[y])
	{
		parent[x] = y;
	}
	else
	{
		parent[y] = x;
		if(rank[x]==rank[y])rank[x]++;
	}
}

bool compare(Edge t1, Edge t2)
{
	return t1.p < t2.p;
}

void kruskal()
{
	sort(edges.begin(),edges.end(),compare);
	int m = edges.size();

	int nvertices = n;	

	for(int i=0; nvertices>1 && i<m; i++)
	{
		int paiA = find(edges[i].o);
		int paiB = find(edges[i].d);
		if(paiA != paiB)
		{
			union_rank(edges[i].o, edges[i].d);
			custo += edges[i].p;
			nvertices--;
		}
		
	}
}

int main(void)
{
	while(1)
	{
		scanf("%d %d", &n, &m);
		if(n==0 && m==0)break;
		reset();
		int total = 0;
		for(int i=0;i<m;i++)
		{
			int o, d, p;
			Edge e;
			scanf("%d %d %d", &o, &d, &p);
			e.o = o;
			e.d = d;
			e.p = p;
			total+=p;
			edges.push_back(e);
		}

		kruskal();

		printf("%d\n", total - custo);
		custo = 0;
	}
	return 0;
}
