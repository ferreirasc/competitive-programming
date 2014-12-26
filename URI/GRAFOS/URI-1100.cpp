#include <algorithm>
#include <stdio.h>

using namespace std;

int knightdist_inf(int x1, int y1, int x2, int y2)
{
	int dx = abs(x2-x1);
	int dy = abs(y2-y1);
	if(abs(dx)==1 && dy==0)return 3;
	if(abs(dy)==1 && dx==0)return 3;
	if(abs(dx)==2 && abs(dy)==2)return 4;
	
	int lb=max((dx+1)/2,(dy+1)/2);
	lb = max(lb,(dx+dy+2)/3);
	if((lb%2)!=(dx+dy)%2)lb++;
	return lb;
}

int n, m;
int knightdist(int x1, int y1, int x2, int y2)
{
	if(x1==n || x2==n)
	{
		x1 = n+1 -x1;
		x2 = n+1 - x2;
	}

	if(y1==m || y2==m)
	{
		y1 = m+1 - y1;
		y2 = m+1 - y2;
	}

	if((x1==1 && y1==1) || (x2==1 && y2==1))
	{
		int a = abs(x1-x2), b = abs(y1-y2);
		if(a==0 && b==3 && m==4)return 5;
		if(b==0 && a==3 && n==4)return 5;
		if(a==1 && b==1)return 4;
	}
	return knightdist_inf(x1,y1,x2,y2);
}

int main(void)
{
	n = m = 8;
	char jogada1[3], jogada2[3];

	while(scanf("%s %s", jogada1, jogada2)!=EOF)
	{
		int x1 = (int)jogada1[0] - 97 + 1;
		int y1 = jogada1[1] - '0';
		int x2 = (int)jogada2[0] - 97 + 1;
		int y2 = jogada2[1] - '0';
		printf("To get from %s to %s takes %d knight moves.\n", jogada1, jogada2, knightdist(x1,y1,x2,y2));
	}

	return 0;
}
