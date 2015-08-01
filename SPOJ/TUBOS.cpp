#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int N, M, num;
vector<int> graph[3000];
int cor[3000], dfsNum[3000];
int npossivel;

void reset()
{
	for(int i=0;i<N;i++)
	{
		cor[i] = dfsNum[i] = 0;
		graph[i].clear();
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
					npossivel = 1;
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
		scanf("%d %d", &N, &M);
		if(N==0 && M==0)break;
		reset();	
		npossivel = 0;
		for(int i=0;i<M;i++)
		{
			int a,b;
			scanf("%d %d", &a, &b);
			a--,b--;
			graph[a].push_back(b);
			graph[b].push_back(a); 
		}

		pontes(0,-1);
		if(npossivel==0)printf("S\n");
		else printf("N\n");
	}
	return 0;
}
