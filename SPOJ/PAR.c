#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char nome1[12], nome2[12];
	int N, i, num1, num2, teste = 0;

	while(1)
	{
		scanf("%d", &N);
		if(N==0)return 0;

		scanf("%s %s", nome1, nome2);
		printf("Teste %d\n", ++teste);

		for(i=0;i<N;i++)
		{
			scanf("%d %d", &num1, &num2);
			if((num1+num2) % 2 == 0)printf("%s\n", nome1);
			else printf("%s\n", nome2);  
		}
	}

	return 0;
}