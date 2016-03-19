#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, P, Q, R, S, X, Y, iref, jref;
    register int j;
    long long int valor = 0;
    scanf("%d", &N);
    scanf("%d %d %d %d %d %d", &P, &Q, &R, &S, &X, &Y);
    scanf("%d %d", &iref, &jref);
    
        for(j=0;j<N;j++)valor+=((P*(iref) + Q*(j+1))%X)*((R*(j+1) + S*(jref))%Y);
    
    printf("%lld\n", valor);
    
    return 0;
}
