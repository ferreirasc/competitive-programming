#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <string.h>

using namespace std;

map<string, int> ids;
map<int, string> nomes;
vector<int> adj[3000];
int visitados[3000];
int maior = 0, indice1;

void dfs(int p, int cont)
{
	visitados[p] = 1;
	if(cont>maior)
	{
		indice1 = p;
		maior = cont;
	}
	int n = adj[p].size();
	for(int i=0;i<n;i++)
	{
		int prox = adj[p][i];
		if(!visitados[prox])
		{
			dfs(prox, cont+1);
		}
	}
}

int main(void)
{
	int N, aux1, aux2, v1, v2, maior1 = 0, maior2 = 0;
	int count = 0;
	string pai, filho;
	cin >> N;

	for(int i=0;i<N;i++)
	{
		cin >> pai >> filho;
		if(ids.find(pai) == ids.end())ids[pai] = count++;
		if(ids.find(filho) == ids.end())ids[filho] = count++;
		aux1 = ids[pai];
		aux2 = ids[filho];
		nomes[aux1] = pai;
		nomes[aux2] = filho;
		adj[aux1].push_back(aux2);
		adj[aux2].push_back(aux1);
	}
	
	dfs(0,0);
	
	maior1 = maior;
	v1 = indice1;

	maior = 0;
	memset(visitados,0,sizeof(visitados));
	dfs(indice1, 0);

	v2 = indice1;

	maior2 = maior;

	if(maior1>=maior2)
	{
		string A = nomes[v1];
		string B = nomes[v2];
		if(A<B)cout << A << " " << B << " " << maior1 << "\n";
		else cout << B << " " << A << " " << maior1 << "\n";
	}
	else 
	{
		string A = nomes[v1];
		string B = nomes[v2];
		if(A<B)cout << A << " " << B << " " << maior2 << "\n";
		else cout << B << " " << A << " " << maior2 << "\n";
	}
	
	return 0;
}
