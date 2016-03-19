#include <stdio.h>

int main ()
{
	int max,resultado,a,b;
	char operacao;
	scanf("%d %d %c %d",&max,&a,&operacao,&b);
	if(operacao == '+')
	{
		resultado = a+b;
		if(resultado <= max)
		{
			printf("OK\n");
		}
		else 
		{
			printf("OVERFLOW\n");
		}
	}
	else 
	{
		resultado = a*b;
		if(resultado <= max)
		{
			printf("OK\n");
		}
		else 
		{
			printf("OVERFLOW\n");
		}
	}
	
	return 0;
}