#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
	int cases;
	scanf("%d", &cases);
	while(cases--)
	{
		int n;
		scanf("%d", &n);
		int i = 1, sum = 0;
	    	while(pow(5,i)<= n)
	    	{
			sum += n/(pow(5,i));
			i++;
	    	}
		printf("%d\n", sum);
	}
	return 0;
}
