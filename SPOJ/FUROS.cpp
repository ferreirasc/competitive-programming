#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int n, i, j, menor, teste=1;
	while(1)
	{
		scanf("%d", &n);
		if(n==0)return 0;
		int CENTROS[n][2], dis, maior[n];
		memset(maior, 0, sizeof(maior));
		for(i=0;i<n;i++)scanf("%d %d", &CENTROS[i][0], &CENTROS[i][1]);
		
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				dis=(CENTROS[i][0]-CENTROS[j][0])*(CENTROS[i][0]-CENTROS[j][0]) + (CENTROS[i][1]-CENTROS[j][1])*(CENTROS[i][1]-CENTROS[j][1]);
				if(dis>maior[i])maior[i]=dis;
			}
		
		menor=2147483646;
		
		for(i=0;i<n;i++)if(maior[i]<menor)menor=maior[i];
		
		printf("Teste %d\n", teste);
		printf("%.0f\n\n", (sqrt(menor)*2 + 5));
		menor=2147483646;
		memset(maior, 0, sizeof(maior));
		teste++;
	}
	return 0;
}
	
	