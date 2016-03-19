#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct cartas
{
	int carta;
	int esta;
};

int vetorB[100000], flag = 0, acabou = 0;
cartas C[100000];
int N, M;

int binary_search(int ini, int end, int valor)
{
	if(ini <= end)
	{
		int meio = (ini+end)/2;
		if(vetorB[meio] == valor)return 1;
		else
		{
			if(valor>vetorB[meio])
			{
				binary_search(meio+1, end, valor);
			}
			else
			{
				binary_search(ini,meio-1,valor);
			}
		}
	}
	else return 0;
}

int acha(int value)
{
	for(int i=0;i<N;i++)
	{
		if(C[i].carta == value)
		{
			return 1;
		}
	}
	return 0;
}

int main(void)
{	
	int j;
	scanf("%d %d", &N, &M);
	for(int i=0;i<N;i++)
	{
		scanf("%d", &C[i].carta);
	}
	
	for(int i=0;i<M;i++)
	{

		scanf("%d", &vetorB[i]);	
		int temp = acha(vetorB[i]);
	
		if(temp != 1)
		{		
			flag = 0;
			
			for(j=0;j<i;j++)
			{
				int value = vetorB[i] - vetorB[j];
				if(binary_search (0,i-1, value))
				{
					
					for(int t=i-1;t>=0;t--)
					{
						if(vetorB[t+1]<vetorB[t])
						{
							swap(vetorB[t+1],vetorB[t]);
						}
					}
					flag = 1;
					break;
				}	
			}
			
			if(flag == 0)
			{
				acabou = 1;
				printf("%d\n", vetorB[i]);
				break;
			}
		}
		else
		{
			for(j=i-1;j>=0;j--)
			{
				if(vetorB[j+1]<vetorB[j])
				{
					swap(vetorB[j+1],vetorB[j]);
				}
			}
		}
	}
	
	if(!acabou)printf("sim\n");
	
	return 0;
}