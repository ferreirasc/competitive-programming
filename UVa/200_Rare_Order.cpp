#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int cont = 0, sorted;
map<char,int> mapa;
char mapa_r[300];
vector<int> graph[300];
int visitados[300];
int lista_ordenada[300];

void reset()
{
	for(int i=0;i<cont;i++)graph[i].clear();
	mapa.clear();
	memset(visitados,0,sizeof(visitados));
	memset(lista_ordenada,0,sizeof(lista_ordenada));
	memset(mapa_r,'\0',sizeof(mapa_r));
	cont = 0;
}

void dfs(int p)
{
	visitados[p] = 1;
	int tam = graph[p].size();
	for(int i=0;i<tam;i++)
	{
		int prox = graph[p][i];
		if(!visitados[prox])
		{
			dfs(prox);
		}
	}
	lista_ordenada[sorted--] = p;
}

void topological_sort()
{
	sorted = cont-1;
	
	for(int i=0;i<cont;i++)
	{
		if(!visitados[i])
		{
			dfs(i);
		}
	}
}

int main(void)
{
	string ant, pos;
	while(cin >> ant)
	{
		if(ant == "#")continue;

		while(true)
		{
			cin >> pos;
			if(pos == "#")break;

			int tam = pos.size();
			int tam2 = ant.size();
			for(int i=0;i<tam && i<tam2;i++)
			{
				if(pos[i]!=ant[i])
				{
					if(mapa.find(pos[i]) == mapa.end())
					{
						mapa_r[cont] = pos[i];
						mapa[pos[i]] = cont++;
					}
					if(mapa.find(ant[i]) == mapa.end())
					{
						mapa_r[cont] = ant[i];
						mapa[ant[i]] = cont++;
					}
					graph[mapa[ant[i]]].push_back(mapa[pos[i]]);
					//printf("%c -> %c\n", ant[i], pos[i]);
					//printf("%d -> %d\n", mapa[ant[i]], mapa[pos[i]]); 
					break;
				}
			}
			ant = pos;		
		}

		topological_sort();

		for(int i=0;i<cont;i++)
		{
			printf("%c", mapa_r[lista_ordenada[i]]);
		}
		
		reset();
		printf("\n");
	}
	return 0;
}
