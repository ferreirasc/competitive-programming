#include <stdio.h>
#include <math.h>


int main(void)
{
    int L, A, P, R;
    scanf("%d %d %d %d", &L, &A, &P, &R);
    
    if(L<0 || A<0 || P<0 || R<0 || L>1000 || P>1000 || R>1000 || A>1000)return(0);
    
    if(sqrt(pow(L,2)+pow(A,2)+pow(P,2))<=(2*R))printf("S\n");
    else printf("N\n");
    return 0;
}
