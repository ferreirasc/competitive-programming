#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

bool divisivel_11(char *digitos)
{
	int cont = digitos[0] - '0', i=0;
	while(1)
	{
		if(cont < 11)
		{
			i++;
			if(i==strlen(digitos))break;
			cont = cont*10 + (digitos[i]-'0');
		}
		else
		{
			cont = cont % 11;
		}
	}
	if(cont)return false;
	return true;
}

int main(void)
{
	char digitos[2000];
	while(1)
	{
		scanf("%s", digitos);
		if(!strcmp(digitos,"0"))return 0;
		if(divisivel_11(digitos))printf("%s is a multiple of 11.\n", digitos);
		else printf("%s is not a multiple of 11.\n", digitos);
		memset(digitos,'\0',sizeof(digitos));
	}
}