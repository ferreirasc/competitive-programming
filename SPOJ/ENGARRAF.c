#include <string.h> //memset
#include <stdlib.h>
#include <stdio.h>

// MAXV é uma constante que define a quantidade máxima de vértices

// Matriz de adjacências
// Se MAdj[i][j] > 0, então há aresta que liga 'i' a 'j' com custo MAdj[i][j].

// Armazena a distância mínima partindo de um vértice 'i' até todos os outros vértices
// dis[j] representa a menor distância de 'i' a 'j'.

// Calcula as distâncias de 'Vi' a todos os outros vértices de um grafo com 'V' vértices e armazena-as em dis[]
int dijkstra (int V, int m)
{
     int k, peso, x, w, s, t, i;
     int dis[V];
     int MAdj[V][V];
     
    for(k=0;k<V;k++)
    {
    for(i=0;i<V;i++)MAdj[k][i]=0;
    }
    for(k=0;k<m;k++)
    {
    scanf("%d %d %d", &x, &w, &peso);
    MAdj[x-1][w-1]=peso;
    }
    /*for(k=0;k<V;k++)
    {
    for(i=0;i<V;i++)printf("%d",MAdj[k][i]);
    printf("\n");
    }*/
    scanf("%d %d", &s, &t);
        // vis[i] informa se o vértice 'i' já foi visitado/analisado ou não (inicialmente nenhum vértice foi)
        char vis[V];
        memset (vis, 0, sizeof (vis));

        // Inicialmente afirmamos que a menor distância encontrada entre Vi e qualquer outro vértice (exceto o próprio Vi) é infinita
        memset (dis, 0x7f, sizeof (dis));
        dis[s-1] = 0;

        while (1)
        {
                
                int i, n = -1;

                for (i = 0; i < V; i++)
                        if (! vis[i] && (n < 0 || dis[i] < dis[n]))
                                n = i;

                if (n < 0)
                        break;
                vis[n] = 1;

                for (i = 0; i < V; i++)
                        if (MAdj[n][i] && dis[i] > dis[n] + MAdj[n][i])
                                dis[i] = dis[n] + MAdj[n][i];
        }
        if(dis[t-1]==2139062143)return -1;
        else return dis[t-1];
}

int main(void)
{
    for(;;)
    {
    int n, m, k, i, j, peso, s, t;
    scanf("%d %d", &n, &m);
    if(n==0 && m==0)return 0;
    printf("%d\n", dijkstra(n, m));
    }
    return 0;
}
