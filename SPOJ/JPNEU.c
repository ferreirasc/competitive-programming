#include <stdio.h>

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	if(N<1 || N>40 || M<1 || M>40)return 0;
	printf("%d\n", (N-M));
	return 0;
}