#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
	int n, i, aux;
	char number[100] = { '\0' };
	char op;
	double visor = 1;
	scanf("%d", &n);
	
	for(i = 0;i<n;i++)
	{
		scanf("%d %c", &aux, &op);
		if(op == '*')visor *= aux;
		else visor /= aux;
	}
	if(visor > pow(2,30))printf("%.0f\n", pow(2,30));
	else if(visor < 1)printf("1\n");
	else
	{
		sprintf(number, "%.2f", visor);
		for(int i=0; i<strlen(number); i++)
		{
			if(number[i] == '.')break;
			else printf("%c", number[i]);
		}
		printf("\n");
	}
	return 0;
}
