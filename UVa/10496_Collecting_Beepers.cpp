#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

typedef struct edge
{
    int x, y;
    int cont;
    int caminho;
    int visitados[30][30];
}edge;

queue<edge> q;

int mapa[30][30];

int main(void)
{
    int casos;
    scanf("%d", &casos);
    
    while(casos--)
    {
        memset(mapa,0,sizeof(mapa));
        int n, m, ox, oy, pontos;
        scanf("%d %d", &n, &m);
        scanf("%d %d", &ox, &oy);
        scanf("%d", &pontos);
        for(int i=0;i<pontos;i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            x--, y--;
            mapa[x][y] = 1;
        }
        edge a;
        ox--;
        oy--;
        a.x = ox;
        a.y = oy;
        a.caminho = 0;
        a.cont = pontos;
        memset(a.visitados,0,sizeof(a.visitados));
        a.visitados[a.x][a.y] = 1;
        q.push(a);
        int aux;
        if(mapa[q.front().x][q.front().y] == 1)aux = q.front().cont - 1;
        int ultimox, ultimoy, cont = 0;
        
        while(!q.empty() && aux!=0)
        {
            if((q.front().x+1) < n && !q.front().visitados[q.front().x+1][q.front().y])
            {
                edge b;
                b.x = q.front().x+1;
                b.y = q.front().y;
                b.caminho = q.front().caminho + 1;
                if(mapa[q.front().x+1][q.front().y] == 1)
                {
                    b.cont = q.front().cont - 1;
                    if(b.cont == 0)
                    {
                        ultimox = b.x;
                        ultimoy = b.y;
                        cont = cont + b.caminho;
                        break;
                    }
                }
                else b.cont = q.front().cont;
                for(int i=0;i<20;i++)
                    for(int j=0;j<20;j++)b.visitados[i][j] = q.front().visitados[i][j];
                b.visitados[b.x][b.y] = 1;
                q.push(b);
            }
            if((q.front().y+1) < m && !q.front().visitados[q.front().x][q.front().y+1])
            {
                edge b;
                b.x = q.front().x;
                b.y = q.front().y+1;
                b.caminho = q.front().caminho + 1;
                if(mapa[q.front().x][q.front().y+1] == 1)
                {
                    b.cont = q.front().cont - 1;
                    if(b.cont == 0)
                    {
                        ultimox = b.x;
                        ultimoy = b.y;
                        cont = cont + b.caminho;
                        break;
                    }
                }
                else b.cont = q.front().cont;
                for(int i=0;i<20;i++)
                    for(int j=0;j<20;j++)b.visitados[i][j] = q.front().visitados[i][j];
                b.visitados[b.x][b.y] = 1;
                q.push(b);
            }
            if((q.front().x-1) >= 0 && !q.front().visitados[q.front().x-1][q.front().y])
            {
                edge b;
                b.x = q.front().x-1;
                b.y = q.front().y;
                b.caminho = q.front().caminho + 1;
                if(mapa[q.front().x-1][q.front().y] == 1)
                {
                    b.cont = q.front().cont - 1;
                    if(b.cont == 0)
                    {
                        ultimox = b.x;
                        ultimoy = b.y;
                        cont = cont + b.caminho;                        
                        break;
                    }
                }
                else b.cont = q.front().cont;
               for(int i=0;i<20;i++)
                    for(int j=0;j<20;j++)b.visitados[i][j] = q.front().visitados[i][j];
                b.visitados[b.x][b.y] = 1;
                q.push(b);
            }
            if((q.front().y-1) >= 0 && !q.front().visitados[q.front().x][q.front().y-1])
            {
                edge b;
                b.x = q.front().x;
                b.y = q.front().y-1;
                b.caminho = q.front().caminho + 1;
                if(mapa[q.front().x][q.front().y-1] == 1)
                {
                    b.cont = q.front().cont - 1;
                    if(b.cont == 0)
                    {
                        ultimox = b.x;
                        ultimoy = b.y;
                        cont = cont + b.caminho;
                        break;
                    }
                }
                else b.cont = q.front().cont;
               for(int i=0;i<20;i++)
                    for(int j=0;j<20;j++)b.visitados[i][j] = q.front().visitados[i][j];
                b.visitados[b.x][b.y] = 1;
                q.push(b);
            }
            q.pop();
        }
        
        while(!q.empty())q.pop();
        a.x = ultimox;
        a.y = ultimoy;
        a.caminho = 0;
        int visitados[30][30];
        memset(visitados,0,sizeof(visitados));
        visitados[a.x][a.y] = 1;
        q.push(a);
        
        while(!q.empty())
        {
            if((q.front().x+1) < n && !visitados[q.front().x+1][q.front().y])
            {
                edge b;
                b.x = q.front().x+1;
                b.y = q.front().y;
                b.caminho = q.front().caminho + 1;
                if(b.x == ox && b.y == oy)
                {
                        cont = cont + b.caminho;
                        break;
                }
                visitados[b.x][b.y] = 1;
                q.push(b);
            }
            if((q.front().y+1) < m && !visitados[q.front().x][q.front().y+1])
            {
                 edge b;
                b.x = q.front().x;
                b.y = q.front().y+1;
                b.caminho = q.front().caminho + 1;
                if(b.x == ox && b.y == oy)
                {
                        cont = cont + b.caminho;
                        break;
                }
                visitados[b.x][b.y] = 1;
                q.push(b);
            }
            if((q.front().x-1) >= 0 && !visitados[q.front().x-1][q.front().y])
            {
                 edge b;
                b.x = q.front().x-1;
                b.y = q.front().y;
                b.caminho = q.front().caminho + 1;
                if(b.x == ox && b.y == oy)
                {
                        cont = cont + b.caminho;
                        break;
                }
                visitados[b.x][b.y] = 1;
                q.push(b);
            }
            if((q.front().y-1) >= 0 && !visitados[q.front().x][q.front().y-1])
            {
                 edge b;
                b.x = q.front().x;
                b.y = q.front().y-1;
                b.caminho = q.front().caminho + 1;
                if(b.x == ox && b.y == oy)
                {
                        cont = cont + b.caminho;
                        break;
                }
                visitados[b.x][b.y] = 1;
                q.push(b);
            }
            q.pop();
        }
        printf("The shortest path has length %d\n", cont);
        while(!q.empty())q.pop();
    }
    
    return 0;
}
