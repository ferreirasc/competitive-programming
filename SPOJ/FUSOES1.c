#include <stdio.h>

int uf[100020];
int rank[100020];

int find(int x)
{
	if(uf[x] != uf[uf[x]])
		uf[x] = find(uf[x]);
	return uf[x];
}

int union2 (int x, int y)
{
	int xx = find(x), yy = find(y);
	if (xx == yy)
	return 0;

	//make sure rank [xx] is smaller
	if (rank [xx] > rank[yy])
	{
		int t = xx;
		xx = yy;
		yy = t;
	}
	
	//if both are equal, the combined tree becomes 1 deeper
	if(rank[xx] == rank [yy])
		rank[yy]++;

	uf[xx] = yy;
	return 1;
}

int main(void)
{
	int N, K, i;
	int a,b;
	char caracter;
	scanf("%d %d", &N, &K);
	

	for(i=1;i<=N;i++)
	{
		uf[i] = i;
		rank[i] = 1;
	}

	for(i=0;i<K;i++)
	{
		scanf("\n%c", &caracter);
		if(caracter=='C')
		{
			scanf("%d %d", &a, &b);
			if(find(a)==find(b))printf("S\n");
			else printf("N\n");
		}
		else
		{
			scanf("%d %d", &a, &b);
			union2(a,b);
		}
	}
	return 0;
}