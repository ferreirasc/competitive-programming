#include <stdio.h>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

pii mdc(int a, int b)
{
	if(b==0)return pii(1,0);
	pii u = mdc(b,a%b);
	return pii(u.second, u.first - (a/b)*u.second);
}

int main(void)
{
	int a,b;
	pii euext;

	while(scanf("%d %d", &a, &b)!=EOF)
	{
		euext = mdc(a,b);
		printf("%d %d %d\n", euext.first, euext.second, a*euext.first + euext.second*b);
	}
	return 0;
}
