#include <stdio.h>

int main(void)
{
	int n, i, X, Y, somas[10000], ini=0, fim=0, maior=-1000, pred=0, aux=0, negativo=0, k=0, flag=0;
	
	for(k=0;;k++)
	{
		scanf("%d", &n);
		if(n==0)return 0;
	
		for(i=0;i<n;i++)
		{
			scanf("%d %d", &X, &Y);
			somas[i] = X - Y;
			if(somas[i]<=0)negativo++;
		}
		
		printf("Teste %d\n", k+1);
		if(negativo==n){printf("nenhum\n");flag=1;}
		
		if(flag!=1)
		{
			for(i=0;i<n;i++)
			{
	
				aux+=somas[i];
				if(aux<0){pred=i+1;aux=0;}
	
				if(aux>=maior)
				{
					maior=aux;
					fim = i;
					ini = pred;
				}
			}
	
			printf("%d %d\n", ini+1, fim+1);
		}
		flag = 0; negativo=0; aux=0; pred =0; ini=0; fim=0; maior=-1000;	
	}
	
	return 0;
}