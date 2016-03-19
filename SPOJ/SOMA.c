#include <stdio.h>

int main(void)
{
    int N, X, soma=0, i=0;
    scanf("%d", &N);
    if(N<1 || N>50)return(0);
    
    while(i<N)
    {
        scanf("%d", &X);
        if(X>5000)return(0);
        soma+=X;
        i++;
    }
    
    printf("%d\n", soma);
    return (0);
}
