#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXV 1010


int MAdj[MAXV][MAXV];


int dis[MAXV];

void dijkstra (int Vi, int V)
{
       
        char vis[MAXV];
        memset (vis, 0, sizeof (vis));

       
        memset (dis, 0x3f, sizeof (dis));
        dis[Vi] = 0;

        while (1)
        {
                int i, n = -1;

                for (i = 0; i < V; i++)
                        if (! vis[i] && (n == -1 || dis[i] < dis[n]))
                                n = i;

                if (n == -1)
                        break;
                vis[n] = 1;

                for (i = 0; i < V; i++)
                        if (dis[i] > dis[n] + MAdj[n][i])
                                dis[i] = dis[n] + MAdj[n][i];
        }
}

int main(void)
{
    int N, M, i, j, pilar1, pilar2, peso;
    memset(MAdj, 0x3f, sizeof(MAdj));
    scanf("%d%d", &N, &M);
    for(i=0;i<M;i++)
    {
    scanf("%d%d%d", &pilar1, &pilar2, &peso);
    MAdj[pilar1][pilar2]=MAdj[pilar2][pilar1]=peso;
    }
    
    dijkstra(0, N+2);
    printf("%d\n", dis[N+1]);
    return 0;
}


