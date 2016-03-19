#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

typedef struct celula
{
	int indice, valor;
}celula;

void Quick(int vetor[], int inicio, int fim){
int pivo, aux, i, j, meio;
i = inicio;
j = fim;
meio = (int) ((i + j) / 2);
pivo = vetor[meio];
do{
while (vetor[i] < pivo) i = i + 1;
while (vetor[j] > pivo) j = j - 1;
if(i <= j){
aux = vetor[i];
vetor[i] = vetor[j];
vetor[j] = aux;
i = i + 1;
j = j - 1;
}
}while(j > i);
if(inicio < j) Quick(vetor, inicio, j);
if(i < fim) Quick(vetor, i, fim);
}

queue<celula>fila;
int adj[50][50], visitados[50], n, m, l, pedagio, ordem[50], k=0;

void bfs(int p)
{
	visitados[p]=1;
	celula aux;
	aux.valor = 0;
	aux.indice = p;
	fila.push(aux);
	
	for(;!fila.empty();)
	{
		for(register int i=0;i<n;i++)
		{
			if(adj[((fila.front()).indice)][i])
			{
				if(!visitados[i])
				{
					if((((fila.front()).valor)+1)<=pedagio)
					{
						visitados[i]=1;
						aux.valor = ((fila.front()).valor)+1;
						aux.indice = i;
						fila.push(aux);
						ordem[k]=i;
						k++;
					}
					else
					{
						return;
					}
				}
			}
		}
		fila.pop();
	}
}
				
			

int main(void)
{
	int x, y, u=0;
	while(1)
	{
		scanf("%d %d %d %d", &n, &m, &l, &pedagio);
		if(n==0 && m==0 && l==0 && pedagio==0)return 0;
		
		for(int j=0;j<m;j++)
		{
			scanf("%d %d", &x, &y);
			x--; y--;
			adj[x][y]=adj[y][x]=1;
		}
		
		l--;
		bfs(l);
		Quick(ordem, 0, (k-1));
		printf("Teste %d\n", u+1);
		for(int i=0; i<k; i++)printf("%d ", ordem[i]+1);
		printf("\n");
		memset(visitados, 0, sizeof(visitados));
		memset(adj, 0, sizeof(adj));
		memset(ordem, 0, sizeof(ordem));
		k=0;
		while(!fila.empty())fila.pop();
		u++;
	}
	
	return 0;
}