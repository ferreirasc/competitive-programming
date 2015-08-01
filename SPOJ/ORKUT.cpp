#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
#include <string.h>
#include <string>

#define CINZA 1
#define BRANCO 0
#define PRETO 2

using namespace std;

map<string,int> mapa;
vector<int> graph[40];
int N, visitados[40], nvertices, sorted[40];

bool dfs(int p)
{
	visitados[p] = CINZA;
	int tam = graph[p].size();
	for(int i=0;i<tam;i++)
	{
		int prox = graph[p][i];
		if(visitados[prox]==BRANCO)
		{
			if(!dfs(prox))return false;
		}
		else
		{
			if(visitados[prox]==CINZA)
			{
				return false;
			}
		}
	}
	
	visitados[p] = PRETO;
	return true;
}

bool existe_ciclo()
{
	for(int i=0;i<N;i++)
	{
		if(!visitados[i])
		{
			if(!dfs(i))return true;
		}
	}
	return false;
}

void dfsTopological(int p)
{
	visitados[p] = 1;
	int tam = graph[p].size();
	for(int i=0;i<tam;i++)
	{
		int prox = graph[p][i];
		if(!visitados[prox])
		dfsTopological(prox);
	}

	sorted[nvertices--] = p;
}

void topSort()
{
	nvertices = N-1;
	for(int i=0;i<N;i++)
	{
		if(!visitados[i])
		{
			dfsTopological(i);	
		}
	}
}

int main(void)
{
	int k=0;
	while(++k)
	{
		scanf("%d", &N);
		if(!N)break;
		printf("Teste %d\n", k); 
		string nomes[40];
		for(int i=0;i<N;i++)
		{
			cin >> nomes[i];
			mapa[nomes[i]] = i;
		}
		
		string b;
		int m;
	
		for(int i=0;i<N;i++)
		{
			cin >> b >> m;
			int id = mapa[b];
			for(int j=0;j<m;j++)
			{
				string a;
				cin >> a;
				graph[mapa[a]].push_back(id);
			}
		}

		memset(visitados,0,sizeof(visitados));

		if(existe_ciclo())
		{
			printf("impossivel\n");
		}
		else
		{
			memset(visitados,0,sizeof(visitados));
			topSort();
			for(int i=0;i<N;i++)
			{
				cout << nomes[sorted[i]] << " "; 
			}
			cout << endl;
		}

		cout << endl;
		for(int i=0;i<N;i++)
		{
			graph[i].clear();
		}
		mapa.clear();
	}
	return 0;
}
