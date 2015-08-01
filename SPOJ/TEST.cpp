#include <stdio.h>

using namespace std;

int main(void)
{
	while(1)
	{
		int a;
		scanf("%d", &a);
		if(a==42)break;
		printf("%d\n", a);
	}
	return 0;
}
