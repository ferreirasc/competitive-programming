#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char n1[14], n2[14];
int resp[14];

int main(void)
{
	int cases;
	scanf("%d", &cases);
	while(cases--)
	{
		scanf("%s %s", n1, n2);
		int temp = 0, cont = 0;
		int maior = max(strlen(n1),strlen(n2));
		for(int i=strlen(n1);i<13;i++)n1[i] = '0';
		n1[13] = '\0';

		for(int i=strlen(n2);i<13;i++)n2[i] = '0';
		n2[13] = '\0';

		int i;
		for(i=0;i<maior;i++)
		{
			int aux = (n1[i] - '0') + (n2[i] - '0') + temp;
			resp[i] = aux % 10;
			temp = aux / 10;
			cont++;
		}

		while(temp>0)
		{
			cont++;
			resp[i] = temp%10;
			temp/=10;
		}
		int flag = 0;
		for(int j=0;j<cont;j++)
		{
			if(resp[j]!=0 || flag == 1)
			{
				flag = 1;
				printf("%d", resp[j]);
			}
		}
		printf("\n");
	}
	return 0;
}
