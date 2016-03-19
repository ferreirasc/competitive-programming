#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct paises
{
	int ind;
	int O, P, B;
};

int main(void)
{
	int N, M, O, P, B;
	scanf("%d %d", &N, &M);

	paises p[N+1];
	
	for(int i=1;i<=N;i++)
	{
		p[i].O = p[i].P = p[i].B = 0;
		p[i].ind = i;
	}	
	
	for(int i=0;i<M;i++)
	{
		scanf("%d %d %d", &O, &P, &B);
		p[O].O++;
		p[P].P++;
		p[B].B++;
	}

	for(int i=1;i<=N;i++)
	{
		for(int j=i+1;j<=N;j++)
		{
			if(p[i].O < p[j].O)
			{
				swap(p[i],p[j]);
			}
			else
			{
				if(p[i].O == p[j].O)
				{
					if(p[i].P < p[j].P)
					{			
						swap(p[i],p[j]);
					}
					else
					{
						if(p[i].P == p[j].P)
						{
							if(p[i].B < p[j].B)
							{					
								swap(p[i],p[j]);
							}
							else
							{
								if(p[i].ind > p[j].ind)
								{
									swap(p[i],p[j]);
								}
							}
						}
					}
				}
			}
		}
	}

	for(int i=1;i<=N;i++)
	{
		printf("%d ", p[i].ind);
	}
	
	printf("\n");
	return 0;
}