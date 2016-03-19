#include <stdio.h>
#include <string.h>
#define MM 1024
#define N 1024
#define INF (1<<30)

using namespace std;
int mana[MM], dano[MM], menor[MM], m, n;
int adj[N][N], dis[N], visitado[N];

int min(int a, int b){return a < b ? a : b;}

int dijkstra() {
  int i;

  for(int j = 0; j<MM;j++)dis[j] = INF;
  memset(visitado, 0, sizeof(visitado));
  dis[0] = 0;

  for (;;) {
    int no = -1;
    for (i = 0; i < n; i++)
      if (!visitado[i] && (no == -1 || dis[i] < dis[no]))
	no = i;

    if (no == -1) break;
    visitado[no] = 1;

    for (i = 0; i < n; i++)
      if (adj[no][i] < INF && dis[no] + adj[no][i] < dis[i])
	dis[i] = dis[no] + adj[no][i];
  }    
  if(dis[n-1]!=INF)
  return dis[n-1];
  else return -1;
}

int menormana()
{
	menor[0] = 0;
	for(int i=1;i<MM;i++)
	{
		menor[i] = INF;
		for(int j=0;j<m;j++)
		{
			int il = i - dano[j];
			if(il<0)il = 0;
			menor[i] = min(menor[i], menor[il]+mana[j]);
		}
	}
}

int main(void)
{
	int u, v, g, k, salao, life, inicio;
	while(scanf("%d %d %d %d", &m, &n, &g, &k))
	{
		memset(menor, 0, sizeof(menor));
		memset(mana, 0, sizeof(mana));
		memset(dano, 0, sizeof(dano));
		if(m==0 && n==0 && g==0 && k==0)return 0;
		for(int i=0;i<m;i++)
		{
			scanf("%d %d", &mana[i], &dano[i]);
		}

		menormana();
		n++;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				adj[i][j] = INF;
			}
		}
		adj[0][1] = 0;
		for(int i=0;i<g;i++)
		{
			scanf("%d %d", &u, &v);
			adj[u][v] = adj[v][u] = 0;
		}

		for(int i=0;i<k;i++)
		{
			scanf("%d %d", &salao, &life);
			for(int j=0;j<n;j++)
			{
				if(adj[j][salao]<INF)adj[j][salao] += menor[life];
			}
		}
		
		printf("%d\n", dijkstra());
	}
	return 0;
}