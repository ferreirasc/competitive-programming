#include <stdio.h>
#include <math.h>

using namespace std;

int main(void)
{
	int n;
	double A, B;
	int C, D;
	scanf("%d", &n);

	for(int i=0;i<n;i++)
	{	
		scanf("%lf %lf", &A, &B);
		C = ceil((A-2) / 3);
		D = ceil((B-2) / 3);
		printf("%d\n", C*D);
	}
	
	return 0;
}
