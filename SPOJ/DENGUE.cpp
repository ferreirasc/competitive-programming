#include <stdio.h>
#include <iostream>
#include <string.h>
#define INF 999

using namespace std;

int N, graph[200][200], dist[200][200];

int Process()
{ 
    int menor = 999,i,j;
    int maior = 0;
    int indice;
    int soma = 0;

    for (i = 0; i < N; i++)
    {
	maior = 0;
        for (j = 0; j < N; j++)
        {
            if(dist[i][j]>maior)
	    {
		maior = dist[i][j];
	    }
        }
	if(maior<menor)
	{
		menor = maior;
		indice = i;
	}
    }

    return indice;
}


int floydWarshell()
{
    int i, j, k, cle;
 
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < N; k++)
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
 
    cle = Process();
    return cle;
} 

int main(void)
{
	int o, d, teste = 0;

	while(1)
	{
		cin >> N;
		
		if(N==0)break;
		
		memset(dist,0,sizeof(dist));
		memset(graph,0,sizeof(graph));

		cout << "Teste " << ++teste << "\n";

		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(i!=j)graph[i][j]=INF;
				else graph[i][j] = 0;
			}
		}

		for(int i=0;i<(N-1);i++)
		{
			scanf("%d %d", &o, &d);
			o--, d--;
			graph[o][d] = graph[d][o] = 1;
		}

		printf("%d\n", floydWarshell()+1);
		printf("\n");
	}	
	return 0;
}
