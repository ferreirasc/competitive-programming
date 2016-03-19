#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> marbles;
int pos = -1;

int bin_search(int p, int q, int x)
{
	int meio = (p+q)/2;
	if(p<=q)
	{
		if(marbles[meio] == x)pos = meio+1;
		if(marbles[meio] >= x)
			bin_search(p, meio-1, x);
		else
			bin_search(meio+1, q, x);
	}
}

int main(void)
{
	int qntm, query, k=0;

	while(++k)
	{
		scanf("%d %d", &qntm, &query);
		if(qntm==0 && query==0)break;

		printf("CASE# %d:\n", k);

		marbles.clear();

		for(int i=0;i<qntm;i++)
		{
			int m;
			scanf("%d", &m);
			marbles.push_back(m);
		}

		sort(marbles.begin(),marbles.end());
	
		for(int i=0;i<query;i++)
		{
			int c;
			scanf("%d", &c);
			pos = -1;
			bin_search(0, qntm-1, c);
			if(pos == -1)printf("%d not found\n", c);
			else printf ("%d found at %d\n", c, pos);
		}
	}	
	
	return 0;
}
