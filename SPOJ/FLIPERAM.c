#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return ( - *(int*)a + *(int*)b);
}

int main(void)
{
	int N, M, i;
	scanf("%d %d", &N, &M);

	int b[N];

	for(i=0;i<N;i++)
	{
		scanf("%d", &b[i]);
	}

	qsort (b, N, sizeof(int), compare);

	for(i=0;i<M;i++)
	{
		printf("%d\n", b[i]);
	}	

	return 0;
}
