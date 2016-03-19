#include <stdio.h>
#include <string.h>

char frase[1005];

int main(void)
{
	int pAtivo = 0;
	gets(frase);
	for(int i=0;i<strlen(frase);i++)
	{
		if(frase[i]=='p')
		{
			if(pAtivo == 1)
			{
				printf("%c", frase[i]);
				pAtivo = 0;
			}
			else
			{
				pAtivo = 1;
			}
		}
		else
		{
			printf("%c", frase[i]);
			pAtivo = 0;
		}
	}
	printf("\n");
	return 0;
}