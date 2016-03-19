#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

string correta;

int main(void)
{
	while(1)
	{
		char estragado;
		int nao_zero = 0;
		char contrato[10000];
		scanf("\n%c %s", &estragado, contrato);
		if(estragado=='0' && !strcmp(contrato,"0"))return 0;

		for(int i=0;i<strlen(contrato);i++)
		{
			if(contrato[i]!=estragado)
				correta+=contrato[i];
		}

		int i, tam = correta.size();
		for(i=0;i<tam;i++)
			if(correta[i]!='0')
			{
				nao_zero = 1;
				break;
			}
		
		if(nao_zero)
		{	
			for(int j=i;j<tam;j++)
				printf("%c", correta[j]);
			printf("\n");
			nao_zero = 0;
		}
		else
		{
			printf("0\n");
		}
		correta.clear();
	}
	return 0;
}
