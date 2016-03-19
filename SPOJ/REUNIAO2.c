#include <stdio.h>
#include <string.h>

#define MAXV 101

int MAdj[MAXV][MAXV];
int dis[MAXV];

int dijkstra (int Vi, int V)
{
      
        char vis[MAXV];
        int maior=-1;
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
        int i;
        for(i=0;i<V;i++)if(dis[i]>maior)maior=dis[i];
        return maior;
       
}

int menor(int *vet, int n)
{
    int menor2=100002, i;
    for(i=0;i<n;i++)if(vet[i]<menor2)menor2=vet[i];
    return menor2;
}

int main(void)
{
    int n, m, k, l, peso, i;
    scanf("%d %d", &n, &m);
    int vet[n];
    memset(MAdj, 0x3f, sizeof(MAdj));
   
    for(i=0;i<m;i++)
    {
    scanf("%d %d %d", &k, &l, &peso);
    MAdj[k][l]=MAdj[l][k]=peso;
    }
   
    for(i=0;i<n;i++)
    {
    vet[i]=dijkstra(i, n);
    }
   
    printf("%d\n", menor(vet, n));
    return 0;
}