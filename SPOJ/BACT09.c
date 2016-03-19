#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
	int n, C, D, bacteria_ideal;
	register int i;
	double maior;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d", &C, &D);
		if(D*log(C) > maior){
					maior=D*log(C); 
					bacteria_ideal=i;
					}
	}
	
	printf("%d\n", bacteria_ideal);
	return 0;
}