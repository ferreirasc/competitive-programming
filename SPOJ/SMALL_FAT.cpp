#include <stdio.h>
#include <stdlib.h>

using namespace std;

int number[200], temp = 0, k = 0;

int main(void)
{
	int n, cases;
	scanf("%d", &cases);
	while(cases--)
	{
		number[0] = 1;
		scanf("%d", &n);
		
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<=k;j++)
			{
				int aux = (number[j]*i + temp);
				number[j] = aux % 10;
				temp = aux/10;
			}

			while(temp>0)
			{
				k++;
				number[k] = temp % 10;
				temp = temp / 10;
			}
		}

		for(int i=k;i>=0;i--)
		{
			printf("%d", number[i]);
		}
		printf("\n");
		k = 0, temp = 0;
	}
	return 0;
}
