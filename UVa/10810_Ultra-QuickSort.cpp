#include <stdio.h>
#include <string.h>  


long merge_count(long A[], long B[], long p, long q, long r){
 int i,j,k;
 
 long c;
 
 for(i=p;i<=q;i++)
  B[i] = A[i];
  
 for(j=q+1;j<=r;j++)
  B[r+q+1-j]=A[j];
  
 i = p;
 j = r;
 c = 0;
 
 for(k=p;k<=r;k++){
  if(B[i] <= B[j]){
   A[k] = B[i];
   i = i+1;
  }else{
   A[k] = B[j];
   j = j-1;
   c = c + (q-i+1);
  }
 }
 
 return c;
 
}
 
long sort_count(long A[], long B[], long i,long j){
 long q;
 if(i >=j ) return 0;
 else{
  q = (i+j)/2;
  return sort_count(A, B, i, q) +
      sort_count(A, B, q+1, j)+
      merge_count(A, B, i, q, j);
 }
 
}

int main(void)
{
	int N;
	while(1)
	{
		scanf("%d", &N);
		if(N==0)return 0;
		long A[N+5], B[N+5];

		for(int i=0;i<N;i++)
		{
			scanf("%ld", &A[i]);
		}

		memset(B, 0, sizeof(B));
		printf("%ld\n", sort_count(A,B,0,N-1));
	}
	return 0;
}

