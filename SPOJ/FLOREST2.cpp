#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N, cont=0;
	scanf("%d", &N);
	for(int a=2;a <=((N+a-1)/(2*a-1));a++)
		if((N+a-1) % (2*a-1) == 0)cont++;
	printf("%d\n", cont);
	return 0;
}