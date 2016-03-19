#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;

vector < pair<int, int> > cod[11];
char senhas[20][8];
int senha_correta[8];

int main(void)
{
	int N, v1, v2, i, teste = 0;

	while(1)
	{
		cin >> N;
		if(N==0)break;
	
		memset(senha_correta,'\0',sizeof(senha_correta));	
		memset(senhas,'\0',sizeof(senhas));
		for(i=0;i<5;i++)cod[i].clear();	

		//Guarda dados...
		for(i=0;i<N;i++)
		{
			for(int j=0;j<5;j++)
			{
				scanf("%d %d", &v1, &v2);
				cod[i].push_back(make_pair(v1,v2));
			}
	 
			for(int j=0;j<6;j++)
			{
				char letra;
				cin >> letra;
				senhas[i][j] = letra;
			}

			senhas[i][6] = '\0';
		}

		int j,k;
		int teste1, teste2, achou = 0;

		//Encontra a senha...
		for(i=0;i<6;i++)
		{
			for(j=0;j<N;j++)
			{
				teste1 = senhas[j][i] - 'A';
				for(k=j+1;k<N;k++)
				{
					teste2 = senhas[k][i] - 'A';
					if((cod[j][teste1].first == cod[k][teste2].first && cod[j][teste1].second == cod[k][teste2].second) || (cod[j][teste1].second == cod[k][teste2].first && cod[j][teste1].first == cod[k][teste2].second))
					{
						continue;
					}
					else
					{
						if(cod[j][teste1].first == cod[k][teste2].first)senha_correta[i] = cod[k][teste2].first;
						else if(cod[j][teste1].second == cod[k][teste2].first)senha_correta[i] = cod[j][teste1].second;
						else if(cod[j][teste1].first == cod[k][teste2].second)senha_correta[i] = cod[j][teste1].first;
						else if(cod[j][teste1].second == cod[k][teste2].second)senha_correta[i] = cod[j][teste1].second;
						achou = 1;					
						break;
					}
				}
				if(achou)
				{
					achou = 0;
					break;
				}
			}
		}
	
		printf("Teste %d\n", ++teste);
		for(i=0;i<6;i++)
		{
			printf("%d ", senha_correta[i]);
		}
	
		printf("\n");
		printf("\n");
	}

	return 0;
}