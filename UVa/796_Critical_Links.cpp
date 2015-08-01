#include <cstring>
#include <stack>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1024
#define MAXM 1024*1024

#define VIZ(u,i) (orig[adj[u][i]] != (u) ? orig[adj[u][i]] : dest[adj[u][i]])

int n, m, npontes = 0;

int adj[MAXN][MAXN], nadj[MAXN];
int orig[MAXM], dest[MAXM];

int low[MAXN], part[MAXN], ponte[MAXM], ncomp, comp[MAXM];
int dt;

int vis[MAXN];
stack<int> stck;

int dfsbcc(int u, int p)
{
	int ch = 0;
	vis[u] = dt++;
	low[u] = vis[u];
	for(int i=0;i<nadj[u];i++)
	{
		int e = adj[u][i], v = VIZ(u,i);
		if(!vis[v])
		{
			stck.push(e);
			dfsbcc(v,u); ch++;
			low[u] = min(low[u], low[v]);
			if(low[v] >= vis[u])
			{
				part[u] = 1;
				ncomp++;
				while(stck.top() != e)
				{
					comp[stck.top()] = ncomp;
					stck.pop();
				}
				comp[stck.top()] = ncomp; stck.pop();
			}
			if(low[v] == vis[v])
			{
				npontes++;
				ponte[e] = 1;
			}
		}else if(v!=p)
		{
			if(vis[v] < vis[u])stck.push(e);
			low[u] = min(low[u],vis[v]);
		}
	}
	return ch;
}

void bcc()
{
	memset(low, 0, sizeof(low));
	memset(vis,0,sizeof(vis));
	memset(part, 0, sizeof(part));
	memset(ponte, 0, sizeof(ponte));
	memset(comp, 0, sizeof(comp));
	dt = 1;
	ncomp = 0;
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
			part[i] = dfsbcc(i,-1) >= 2;
	}
}


int main(void)
{
	while(scanf("%d", &n)!=EOF)
	{
		memset(nadj, 0, sizeof(nadj));
		memset(adj, 0, sizeof(adj));
		npontes = 0;
		int k = 0;
		for(int i=0;i<n;i++)
		{
			int o, m;
			scanf("%d %*c %d %*c", &o, &m);
			for(int j=0;j<m;j++,k++)
			{
				int d;
				scanf("%d", &d);
				orig[k] = o; dest[k] = d;
				adj[o][nadj[o]++] = adj[d][nadj[d]++] = k;
			} 
		}

		bcc();

		printf("%d critical links\n", npontes);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<nadj[i];j++)
			{
				if(ponte[adj[i][j]] && i < VIZ(i,j))
				{
					if(i < VIZ(i,j))printf("%d - %d\n", i, VIZ(i,j));
					else printf("%d - %d\n", VIZ(i,j),i);
				}
			}
		}
		printf("\n");
	}
	return 0;
}

