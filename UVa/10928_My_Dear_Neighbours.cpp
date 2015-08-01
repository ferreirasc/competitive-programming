#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

vector<int> vizinhos;

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int vertices;
		int min = 2147483647;
		scanf("%d", &vertices);
		getchar();
		for(int i=0;i<vertices;i++)
		{
			int cont = 0;
			char linha[10000];
			gets(linha);
			char *pch;
			pch = strtok(linha," \n");
			while (pch != NULL)
  			{
				int number;
				cont++;
    				pch = strtok (NULL, " \n");
  			}
			if(cont<min)min = cont;
			vizinhos.push_back(cont);
		}
		int k = 0;
		for(int i=0;i<vertices;i++)
		{
			if(vizinhos[i] == min)
			{
				if(k==0)
				{
					printf("%d", i+1);
					k++;
				}
				else printf(" %d", i+1);
			}
		}
		printf("\n");
		if(t!=0)getchar();
		vizinhos.clear();
	}
	return 0;
}
