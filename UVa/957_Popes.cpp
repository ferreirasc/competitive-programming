#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void)
{
	for(int y, begin, end, maior = 0; scanf("%d", &y)!=EOF; 1)
	{
		int p;
		scanf("%d", &p);
		int years[p];
		
		for(register int i=0;i<p;i++)scanf("%d", &years[i]);

		for(int i=0, cont = 0;i<p;i++, cont = 0)
		{
			int j;
			for(j=i;(years[j] <= years[i]+y-1);j++)cont++;
			if(cont > maior)
			{
				maior = cont;
				begin = years[i], end = years[j-1];
			}
		}
		printf("%d %d %d\n", maior, begin, end);
	}
	return 0;
}
