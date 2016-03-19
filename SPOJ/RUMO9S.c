#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int somadigit(char *x)
{
	int b=0, soma=0, i;
		for(i=0;i<strlen(x);i++){
		b = x[i]-'0';
		soma+=b;
		}
	return soma;	
}

int somadigit2(int k)
{
	int resto,somatorio;
	somatorio=0;

        while (k>0)
        {
        resto=k%10;
        k=(k-resto)/10;
        somatorio=somatorio+resto;
        }
return somatorio;
}

int main(void)
{
	char vet1[1001];
	for(;;)
	{
	int n=0, b=0;
	scanf("%s", vet1);
	if(vet1[0]=='0')return 0;
	if(somadigit(vet1)%9==0)
	{
	b = somadigit(vet1);
		for(;;)
		{
		if(somadigit2(b)==b){printf("%s is a multiple of 9 and has 9-degree %d.\n", vet1, n+1);break;}
		else{b=(somadigit2(b));n++;}
		}
	}
	else
	{
	printf("%s is not a multiple of 9.\n", vet1);
	}
	}
	return 0;
}