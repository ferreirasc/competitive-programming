#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

typedef struct edge
{
        int indice;
        int cont;
}edge;

int visitados[1000005];
vector<int> adj[1000005];

int main(void)
{
	queue<edge> fila;
	int N, k, l, valor;
	int maior = 0;
	
	scanf("%d", &N);
	
	for(int i=0;i<(N-1);i++)
	{
		scanf("%d %d", &k, &l);
		k--, l--;
                adj[k].push_back(l);
                adj[l].push_back(k);
	}

        edge aux;
        aux.indice = 0;
        aux.cont = 0;
	fila.push(aux);
	valor=0;
	visitados[0]=1;
	
        while(!fila.empty())
	{	
	        int tam = adj[valor].size();
	        
		for(int j=0;j<tam;j++)
		{
		        int prox = adj[valor][j];
			if(visitados[prox]!=1)
			{
			        aux.indice = prox;
			        aux.cont = fila.front().cont + 1;
				fila.push(aux);
				visitados[prox]=1;
			}
		}
		fila.pop();
		if(!fila.empty())
		valor=fila.front().indice;
	}

	memset(visitados, 0, sizeof(visitados));
        aux.indice = valor;
        aux.cont = 0;
	fila.push(aux);
	visitados[valor]=1;

        while(!fila.empty())
	{	
	        int tam = adj[valor].size();
	        
		for(int j=0;j<tam;j++)
		{
		        int prox = adj[valor][j];
			if(visitados[prox]!=1)
			{
			        aux.indice = prox;
			        aux.cont = fila.front().cont + 1;
				fila.push(aux);
				visitados[prox]=1;
			}
		}
                if(fila.front().cont > maior)maior = fila.front().cont;
		fila.pop();
		valor=fila.front().indice;
	}

        printf("%d\n", maior);
	
	return 0;
}
		
