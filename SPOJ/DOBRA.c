#include <stdio.h>
#include <math.h>

int main(void)
{
    int N, i=0;
    double valor;
    while(1)
    {
    scanf("%d", &N);
    if(N==-1 || N<-1 || N>15)return 0;
    valor=pow((pow(2.0,N)+1),2);
    printf("Teste %d\n", i+1);
    printf("%.0f\n", valor);
    printf("\n");
    i++;
    }
    return 0;
}
