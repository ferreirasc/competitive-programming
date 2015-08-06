#include <stdio.h>

using namespace std;


long long mpow(long long x, long long y, long long mod)
{
	long long ret = 1;
	while (y)
	{
        	if (y&1)
		{
			ret = (ret * x)%mod;
		}
		y >>= 1, x = (x * x)%mod;
	}
	return ret;
}

int main(void)
{
	int B, P, M;
	while(scanf("%d %d %d", &B, &P, &M)!=EOF)
	{
		printf("%lld\n", mpow(B, P, M));
	}
	return 0;
}
