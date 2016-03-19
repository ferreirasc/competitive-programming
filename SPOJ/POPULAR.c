#include <stdio.h>

int main(void)
{
	int n, maior, count=0, i, j;
	
	for(;;)
	{
		scanf("%d", &n);
		int vet[n][n];

		if(n==0 || n<1 || n>100)return 0;

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d", &vet[i][j]);
			}	
		}
	
		maior=count;
	
		for(j=0;j<n;j++)
		{
			for(i=0;i<n;i++)
			{
				if(vet[i][j]==1)count++;
			}
			
			if(count>maior)maior=count;
			count=0;
		}

		printf("%d\n", maior);
	}
	return 0;
}