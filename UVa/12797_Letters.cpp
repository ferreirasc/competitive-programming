#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <ctype.h>

using namespace std;

typedef struct no
{
	int x,y;
	int cont;
}no;
	
int N, mask;
char mapa[100][100];
bool visitados[100][100];
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int menor = 0x3f3f3f3f;

bool limite(int i, int j)
{
	if(i<0 || j<0 || i>=N || j>=N)return false;
	else return true;
}

bool permitido(char c)
{
	int pos = tolower(c) - 'a';
	if(islower(c))
		return !((1 << pos) & mask);
	return ((1<<pos) & mask);
}

void bfs(int x, int y)
{
	queue<no> fila;
	no aux;
	aux.x = x;
	aux.y = y;
	aux.cont = 0;
	if(permitido(mapa[x][y]))
	{
		fila.push(aux);
		visitados[x][y] = true;
	}
	while(!fila.empty())
	{	
		for(int k=0;k<4;k++)
		{
			int i = fila.front().x + dx[k];
			int j = fila.front().y + dy[k]; 
			if(limite(i,j) && !visitados[i][j])
			{
				if(permitido(mapa[i][j]))
				{
					no aux;
					aux.x = i;
					aux.y = j;
					aux.cont = fila.front().cont+1;
					if(i==N-1 && j==N-1)
					{
						if(aux.cont<menor)menor = aux.cont;
						return;
					}
					visitados[i][j] = true;
					fila.push(aux);
				}
			}
		}
		fila.pop();	
	}
}

void solve()
{
	for(int i=0;i<1024;i++)
	{
		mask = i;
		memset(visitados,0,sizeof(visitados));
		bfs(0,0);
	}
}

int main(void)
{
	scanf("%d", &N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("\n%c", &mapa[i][j]);
		}
	}

	solve();
	if(menor==0x3f3f3f3f)printf("-1\n");
	else printf("%d\n", menor+1);
	return 0;
}
