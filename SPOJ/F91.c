#include <stdio.h>
#include <stdlib.h>

int f91(int n)
{
    if(n<=100)return 91;
    if(n>=101)n=n-10;
    return n;
}

int main(void)
{
    int n, i=0;
    
    scanf("%d", &n);
    while(i<250000 && n!=0)
    {
        if(n>1000000)return(0);
        
            if(n!=0)
            {
                printf("f91(%d) = %d\n", n, f91(n));
            }
        i++;
        scanf("%d", &n);
    }
    
    return(0);
}
