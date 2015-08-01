#include <stdio.h>
#include <string.h>

using namespace std;

int devices[30];
int ligado[30];
int value, maior = 0;
long int rede = 0, flag = 0;

int main(void)
{
	int n, m, c, t=0;
	while(1)
	{
		scanf("%d %d %d", &n, &m, &c);
		if(n==0 && m==0 && c==0)return 0;
		printf("Sequence %d\n", ++t);

		for(int i=0;i<n;i++)
		{
			scanf("%d", &value);
			devices[i] = value;
		}

		for(int i=0;i<m;i++)
		{
			scanf("%d", &value);
			value--;
			if(ligado[value]==0)
			{
				rede+=devices[value];
				ligado[value]=1;
			}
			else
			{
				rede-=devices[value];
				ligado[value]=0;
			}

			if(rede>c)
			{
				flag = 1;
			}
			else
			{
				if(rede>maior)maior = rede;
			}
		}

		if(!flag)
		{
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n", maior);
		}
		else
		{
			printf("Fuse was blown.\n");
		}
	
		maior = 0;
		flag = 0;
		rede = 0;
		memset(devices,0,sizeof(devices));
		memset(ligado,0,sizeof(ligado));
	}	
	return 0;
}
