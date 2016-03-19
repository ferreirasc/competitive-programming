#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<long int> V1, V2;

int main(void)
{
	int N, C;
	scanf("%d %d", &N, &C);
	for(int i=0;i<N;i++)
	{
		long int A, B, lixo, lixo2;
		scanf("%ld %ld %ld %ld", &A, &lixo, &B, &lixo2);
		if(A>B)swap(A,B);
		V1.push_back(A);
		V2.push_back(B);
	}

	sort(V1.begin(),V1.end());
	sort(V2.begin(),V2.end());

	for(int i=0;i<C;i++)
	{
		long int X1, X2;
		scanf("%ld %ld", &X1, &X2);
		if(X1>X2)swap(X1,X2);
		printf("%ld\n", long(lower_bound(V1.begin(),V1.end(),X1)-V1.begin()-1)+N-long(upper_bound(V2.begin(),V2.end(),X2)-V2.begin()-1)); 
	}
	return 0;
}
