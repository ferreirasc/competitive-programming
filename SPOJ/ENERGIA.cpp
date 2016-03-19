#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int mat[200][200], visitados[200];

int main(void)
{
	queue<int> fila;
	int N, M, i, k, l, j, valor, cont=0, flag=0;
	while(1)
	{
	memset(mat, 0, sizeof(mat));
	memset(visitados, 0, sizeof(visitados));
	scanf("%d %d", &N, &M);
	if(N==0 && M==0)return 0;
	
	for(i=0;i<M;i++)
	{
		scanf("%d %d", &k, &l);
		mat[k][l]=mat[l][k]=1;
	}

	fila.push(1);
	valor=1;
	visitados[1]=1;
	for(;!fila.empty();)
	{	
		for(j=1;j<=N;j++)
		{
			if(mat[valor][j]==1)
			{
				if(visitados[j]!=1)
				{
					fila.push(j);
					visitados[j]=1;
				}
			}
		}
		fila.pop();
		valor=fila.front();
	}

	for(i=1;i<=N;i++)if(visitados[i]==0){printf("Teste %d\n", ++cont);printf("falha\n");printf("\n");flag=1;break;}
	if(flag==0){printf("Teste %d\n", ++cont);printf("normal\n");printf("\n");}
	flag=0;
	}
	return 0;
}
		
