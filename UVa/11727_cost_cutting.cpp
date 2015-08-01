#include <stdio.h>
#include <string.h>

using namespace std;

int hash[20000];
int menor = 100000, maior = -1;

int main(void)
{
	int n;
	int salario[3];

	scanf("%d", &n);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d", &salario[j]);
			if(salario[j]>maior)maior = salario[j];
			if(salario[j]<menor)menor = salario[j];
		}

		hash[maior] = 1;
		hash[menor] = 1;

		if(hash[salario[0]] == 0)printf("Case %d: %d\n", i+1, salario[0]);
		else if(hash[salario[1]]==0)printf("Case %d: %d\n", i+1, salario[1]);
		else if(hash[salario[2]]==0)printf("Case %d: %d\n", i+1, salario[2]);
		else printf("Case %d: %d\n", i+1, salario[2]);

		menor = 100000, maior = -1;
		memset(hash,0,sizeof(hash));
		memset(salario,0,sizeof(salario));
	}	
	return 0;
}
