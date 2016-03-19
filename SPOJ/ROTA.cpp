#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

map<string, int> dados;
vector<int> grafo;
char cidades[128][32];
int mapa[128][128];
int u[10024],v[10024], cont, n, flag;
bool visitado[128];

void dfs(int p)
{
	visitado[p] = 1;
	cont++;
	for(int i=0;i<n;i++)
	{
		if(!visitado[i] && mapa[p][i])
		{
			dfs(i);	
		}
	}
}

int main(void)
{
	int m, a, b;
	char cidade1[30], cidade2[30];
	
	while(scanf("%d %d", &n, &m))
	{
		flag = 0;
		if(n==0 && m==0)break;
		
		dados.clear();
		for(int i = 0; i < n; i++)memset(mapa[i], 0, n << 2);
		
		for(int i=0;i<n;i++)
		{
			scanf("%s", cidades[i]);
			dados[string(cidades[i])] = i;
		}
	
		for(int i=0;i<m;i++)
		{
			scanf("%s %s", cidade1, cidade2);	
			a = dados[string(cidade2)], b = dados[string(cidade1)];
			mapa[a][b]++;
			u[i] = b, v[i] = a;
		}
		
		for(int i=0; i<m; i++)
		{
			if(mapa[v[i]][u[i]]>1)continue;
			mapa[v[i]][u[i]]--;
			cont = 0;		
			memset(visitado,0,n);		
			dfs(0);
			if(cont < n)
			{
				printf("%s %s\n", cidades[u[i]], cidades[v[i]]);
				flag = 1;
			}
			mapa[v[i]][u[i]]++; 
		}
		if(flag==0)printf("Nenhuma\n");
		printf("\n");
	}

	return 0;
}

