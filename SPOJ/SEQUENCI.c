#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n;

int main(void)
{
   register int i, j, op=1, k=1, M = 0;
    while(scanf("%d", &n)==1){
    int a[n];
    op=1;
    scanf("%d", &a[0]);
    for(i=1; i<n; i++)
      {
         scanf("%d", &a[i]);
         
         /*sequencia crescente */
         if(a[i] <= a[i-1])
            op = 0;
           
         M +=a[i];
         
      }
      printf("Case #%d:", k);   
    if(op==0)
      {
      for(i=0;i<n;i++)printf(" %d", a[i]);
      printf("\n");
      printf("This is not an A-sequence.\n");
      k++;
      continue;
      }
    int m[M+1];
    if(op==1)
    {
	    memset(m,0,4*(M+1));
	    m[0]=1;
	    for(i=0;i<n;i++)
    {
    for(j=M; j>= a[i]; j--)
    {
    m[j] |= m[j-a[i]];
    if((i+1)>=n)continue;
    if(m[a[i+1]]==1){op=0;break;}
    }
    if(op==0)break;
    }
    }
   
    if(op==0)
           {
    for(i=0;i<n;i++)printf(" %d", a[i]);
      printf("\n");
      printf("This is not an A-sequence.\n");
      k++;
      continue;
      }
     
      if(op==1)
      {
      for(i=0;i<n;i++)printf(" %d", a[i]);
      printf("\n");
      printf("This is an A-sequence.\n");
      k++;
      continue;
      }  
   
   
}
    return 0;
}


