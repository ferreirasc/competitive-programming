#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

typedef struct nodo
{
	int x, y;
}nodo2;

int mapa[102][102], visitado[102][102], n, m, k=0, tam_navio[1050], achou=0;
nodo2 navios[1050][1050];

int bfs(int x0, int y0)
{
	queue<nodo2> fila;
	int j=0;
	nodo2 aux;
	aux.x = x0;
	aux.y = y0;
	navios[k][j].x = x0;
	navios[k][j].y = y0;
	fila.push(aux);
	visitado[((fila.front()).x)][((fila.front()).y)]=1;
	
	while(!fila.empty())
	{
		if(((fila.front()).x+1) <= n && mapa[((fila.front()).x+1)][((fila.front()).y)]==-2 && !visitado[((fila.front()).x+1)][((fila.front()).y)])
		{
			aux.x = ((fila.front()).x+1);
			aux.y = ((fila.front()).y);
			j++;
			navios[k][j].x = ((fila.front()).x+1);
			navios[k][j].y = ((fila.front()).y);
			visitado[((fila.front()).x+1)][((fila.front()).y)]=1;
			fila.push(aux);
		}
		
		if(((fila.front()).x-1) >= 1 && mapa[((fila.front()).x-1)][((fila.front()).y)]==-2 && !visitado[((fila.front()).x-1)][((fila.front()).y)])
		{
			aux.x = ((fila.front()).x-1);
			aux.y = ((fila.front()).y);
			j++;
			navios[k][j].x = ((fila.front()).x-1);
			navios[k][j].y = ((fila.front()).y);
			visitado[((fila.front()).x-1)][((fila.front()).y)]=1;
			fila.push(aux);
		}
		
		if(((fila.front()).y+1) <= m && mapa[((fila.front()).x)][((fila.front()).y+1)]==-2 && !visitado[((fila.front()).x)][((fila.front()).y+1)])
		{
			aux.x = ((fila.front()).x);
			aux.y = ((fila.front()).y+1);
			j++;
			navios[k][j].x = ((fila.front()).x);
			navios[k][j].y = ((fila.front()).y+1);
			visitado[((fila.front()).x)][((fila.front()).y+1)]=1;
			fila.push(aux);
		}
		
		if(((fila.front()).y-1) >= 1 && mapa[((fila.front()).x)][((fila.front()).y-1)]==-2 && !visitado[((fila.front()).x)][((fila.front()).y-1)])
		{
			aux.x = ((fila.front()).x);
			aux.y = ((fila.front()).y-1);
			j++;
			navios[k][j].x = ((fila.front()).x);
			navios[k][j].y = ((fila.front()).y-1);
			visitado[((fila.front()).x)][((fila.front()).y-1)]=1;
			fila.push(aux);
		}
		fila.pop();
	}
	return j;
}

int main(void)
{
	int comandos, cont=0;
	scanf("%d %d", &n, &m);
	memset(mapa, 0, sizeof(mapa));
	for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= m; j++) {
            char tmp;

            scanf("\n%c", &tmp);

            if(tmp == '.')
                mapa[i][j] = -1;
            else
                mapa[i][j] = -2;
        }
    }
	
	memset(visitado, 0, sizeof(visitado));
	memset(navios, 0, sizeof(navios));
	memset(tam_navio, 0, sizeof(tam_navio));
	
	for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= m; j++) {
            if(mapa[i][j]==-2)
			{
				if(!visitado[i][j])
				{
					tam_navio[k]=bfs(i, j)+1;
					k++;
				}
			}
        }
    }
	
	scanf("%d", &comandos);
	for(register int i=0;i<comandos;i++)
	{
		int tiro1, tiro2;
		scanf("%d %d", &tiro1, &tiro2);
		if(mapa[tiro1][tiro2]==-2)
		{
			for(register int u=0;u<k;u++)
			{
				for(register int o=0;o<tam_navio[u];o++)
				{
					if(navios[u][o].x==tiro1 && navios[u][o].y==tiro2)
					{
						navios[u][o].x=-2;
						navios[u][o].y=-2;
						achou=1;
					}
					if(achou==1)break;
				}
				if(achou==1)break;
			}
		}
		achou=0;
	}
	
	achou=0;
	
	for(register int u=0;u<k;u++)
	{
		for(register int o=0;o<tam_navio[u];o++)
		{
			if(navios[u][o].x==-2 &&  navios[u][o].y==-2)achou=1;
			else{achou=0;break;}
		}
		if(achou==1)cont++;
	}
	
	printf("%d\n", cont);
	return 0;
	
}