#include <stdio.h>
#include <math.h>

using namespace std;

int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}

int main(void)
{
	double n;
	while(1)
	{
		scanf("%lf", &n);
		if(n==0)break;

		double vetor[40000];
		
		for(int i=0;i<n;i++)scanf("%lf",&vetor[i]); 
	
		double cont = 0;	

		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(gcd(vetor[i],vetor[j])==1)
				{
					cont++;
				}
			}
		}

		if(cont==0)
		{
			printf("No estimate for this data set.\n");
		}
		else
		{
			double b = n*(n-1)/2;
			double a = cont/b;
			a = 6.0/a;
			a = sqrt(a);
			printf("%lf\n", a);
		}
	}
	return 0;
}
