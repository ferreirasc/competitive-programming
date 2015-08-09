#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

typedef pair<long long,long long> pii;

pii mdc(long long a, long long b)
{
	if(b==0)return pii(1,0);
	pii u = mdc(b,a%b);
	return pii(u.second, u.first - (a/b)*u.second);
}

int main(void)
{
	pii euext;
	long long n;
	long long n1,n2,c1,c2;
	while(1)
	{
		scanf("%lld", &n);
		if(n==0)break;
		scanf("%lld %lld %lld %lld", &c1, &n1, &c2, &n2);
		euext = mdc(n1,n2);
		long long gcd = n1*euext.first + euext.second*n2;
	
		if(n%gcd!=0)
		{
			printf("failed\n");
			continue;
		}	
	
		euext.first*=n/gcd;
		euext.second*=n/gcd;

		n1 = n1/gcd;
		n2 = n2/gcd;

		long long ini = ceil(-(double)euext.first/n2), fim = floor((double)euext.second/n1);

		if(ini>fim)
		{
			printf("failed\n");
			continue;
		}

		long long solution1_x = euext.first + n2*ini;
		long long solution2_x = euext.first + n2*fim;
		long long solution1_y = euext.second - n1*ini;
		long long solution2_y = euext.second - n1*fim;
		long long preco1 = -1, preco2 = -1;
	
		if(solution1_x >= 0)
		{
			if(solution1_y>=0)
			{
				preco1 = solution1_x * c1 + solution1_y * c2;
			}
		}

		if(solution2_x >= 0)
		{
			if(solution2_y>=0)
			{
				preco2 = solution2_x * c1 + solution2_y * c2;
			}
		}
	
		if(preco2 == -1 && preco1 == -1)
		{
			printf("failed\n");
			continue;
		}
		else
		{
			if(preco1<preco2)
			{
				printf("%lld %lld\n", solution1_x, solution1_y);
			}
			else printf("%lld %lld\n", solution2_x, solution2_y);
		}
	}	
	return 0;
}
