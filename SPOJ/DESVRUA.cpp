#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int g1[1000][1000], g2[1000][1000], g_inverse[1000][1000], N, M, cont2=0, cont=0, cont3=0;
int visitados2[1000], visitados[1000], visitados3[1000];
int cor[1005];
int num;
int ok = 1;
int dfsNum[1005];

int pontes( int u, int p ) {
	cor[u] = 1;
	dfsNum[u] = num++;
	int leastAncestor = num;
	for( int v = 0; v < N; v++ ) {
		if( g2[u][v] && v != p ) {
			if( cor[v] == 0 ) {
				// (u,v) is a forward edge
				int rec = pontes( v, u );
				if( rec > dfsNum[u] ){
					//cout << "Bridge: " << u << " " << v << endl;
					if(g1[u][v]==0 || g1[v][u]==0){ok = 0;break;}
					
					}
				leastAncestor = ( leastAncestor <  rec )? leastAncestor: rec;
			} else {
				// (u,v) is a back edge
				leastAncestor = ( leastAncestor< dfsNum[v] )? leastAncestor : dfsNum[v];
			}
		}
	}
	cor[u] = 2;
	return leastAncestor;
}

void dfs2(int p)
{
	visitados2[p] = 1;
	cont++;
	for(int i=0;i<N;i++)
	{
		if(g2[p][i] && !visitados2[i])
		{
			dfs2(i);
		}
	}
}

void dfs_inverse(int p)
{
	visitados3[p] = 1;
	cont2++;
	for(int i=0;i<N;i++)
	{
		if(g_inverse[p][i] && !visitados3[i])
		{
			dfs_inverse(i);
		}
	}
}

void dfs(int p)
{
	visitados[p] = 1;
	cont3++;
	for(int i=0;i<N;i++)
	{
		if(g1[p][i] && !visitados[i])
		{
			dfs(i);
		}
	}
}

int main(void)
{	
	while(scanf("%d %d", &N, &M)!=EOF)
	{
		memset(visitados2,0,sizeof(visitados2));
		memset(visitados3,0,sizeof(visitados3));
		memset(visitados,0,sizeof(visitados));
		memset( cor, 0, sizeof(cor));
		memset(dfsNum,0,sizeof(dfsNum));
		memset(g2,0,sizeof(g2));
		memset(g1,0,sizeof(g1));
		memset(g_inverse,0,sizeof(g_inverse));
		cont2 = cont = cont3 = 0, ok = 1;

		int lixo1, lixo2, lixo3;
		scanf("%d %d %d", &lixo1, &lixo2, &lixo3);
		lixo1--,lixo2--;
		for(int i=1;i<M;i++)
		{
			int a,b,d;
			scanf("%d %d %d", &a, &b, &d);
			a--,b--;
			if(d==1)
			{
				g1[a][b] = 1;
				g_inverse[b][a]=1;
			}
			else g1[a][b]=g1[b][a]=g_inverse[b][a]=g_inverse[a][b]=1;
			g2[a][b]=g2[b][a]=1;
		}

		dfs2(lixo1);
		if(cont!=N)
		{
			printf("*\n");
			continue;
		}
		cont = 0;

		dfs(lixo1);
		dfs_inverse(lixo1);
		if(cont2==N && cont3==N)
		{
			printf("-\n");
			continue;
		}

		pontes(lixo1,-1);

		if(ok)
		{
			printf("1\n");
			continue;
		}

		printf("2\n");

	}
	return 0;
}
