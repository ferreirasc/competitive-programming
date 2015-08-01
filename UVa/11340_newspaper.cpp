#include <stdio.h>
#include <string.h>

using namespace std;

int main(void)
{
	int N, K, linhas;
	scanf("%d", &N);
	while(N--)
	{
		scanf("%d", &K);
		char letra;
		int centavos;
		double total=0;
		int valores[100000];
		char linha[100000];
		memset(valores, 0, sizeof(valores));

		for(int i=0;i<K;i++)
		{
			scanf("\n%c %d", &letra, &centavos);
			int aux = letra;
			valores[aux] = centavos;
		}

		scanf("%d", &linhas);
		getchar();
		double constr = 0;
		
		for(int i=0;i<linhas;i++)
		{
			gets(linha);
			total = 0;
			for(int i=0; i<strlen(linha); i++)
			{
				int aux = linha[i];
				if(valores[aux])
				{
					total+=valores[aux];
				}
			}

			while(total>100)
			{
				total = total - 100;
				constr = constr + 1;
			}
			
			constr = constr + (total/100);
			int p = constr*100;
			p = p % 100;
			if(p>100)
			{
				while(p > 100)
				{
					constr = constr + 1;
					p = p - 100;
				}
				double q = p;
				constr = constr + (q/100);
			}
		}
		printf("%.2lf$\n", constr); 
	}
	return 0;
}

