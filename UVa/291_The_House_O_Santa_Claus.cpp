#include <stdio.h>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct edge
{
	int indice;
	string caminho;
	bool caminho_possivel[5][5];
}edge;

queue<edge> q;

vector<int> graph[5];
vector<string> paths;

int main(void)
{
	//graph
	graph[0].push_back(1);
	graph[0].push_back(4);
	graph[0].push_back(2);
	graph[1].push_back(4);
	graph[1].push_back(0);
	graph[1].push_back(2);
	graph[2].push_back(4);
	graph[2].push_back(1);
	graph[2].push_back(0);
	graph[2].push_back(3);
	graph[3].push_back(2);
	graph[3].push_back(4);
	graph[4].push_back(3);
	graph[4].push_back(2);
	graph[4].push_back(0);
	graph[4].push_back(1);
	
	//bfs...
	edge a;
	a.indice = 0;
	a.caminho = a.caminho + '1';
	memset(a.caminho_possivel,true,sizeof(a.caminho_possivel));
	q.push(a);

	while(!q.empty())
	{
		int front = q.front().indice;
		int tam = graph[front].size();
		int i;
		for(i=0;i<tam;i++)
		{
			int prox = graph[front][i];
			if(q.front().caminho_possivel[front][prox] == true)
			{
				edge aux;
				aux.indice = prox;
				char buffer[10];
				sprintf(buffer, "%d", prox+1);
				aux.caminho = q.front().caminho + buffer;
				for(int b=0;b<5;b++)
					for(int j=0;j<5;j++)
						aux.caminho_possivel[b][j] = q.front().caminho_possivel[b][j];
						
				aux.caminho_possivel[front][prox] = false;
				aux.caminho_possivel[prox][front] = false;
				q.push(aux);
			}
		}
		if(q.front().caminho.size() == 9)paths.push_back(q.front().caminho);
		q.pop();
	}
	
	sort(paths.begin(),paths.end());
	int tam = paths.size();
	for(int i=0;i<tam;i++)
	{
		cout << paths[i] << endl;
	}
	return 0;
}
