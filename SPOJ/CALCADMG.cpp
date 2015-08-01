#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b)
{
	if(b==0)
		return a;
	return mdc(b, a % b);
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int i=0;i<T;i++)
	{
		int x1,y1,x2,y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", mdc(abs(x2-x1),abs(y2-y1))+1);
	}
	return 0;
}
