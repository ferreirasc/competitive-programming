#include <stdio.h>

int main(void)
{
    int N, soma=1, i=1;
    scanf("%d", &N);
    if(N<0 || N>12)return(0);
    for(;N--;i++)soma*=i;
    
    printf("%d\n", soma);
    
    return 0;
}
