#include <stdio.h>

int main(void)
{
    int ano, aux;
    scanf("%d", &ano);
    
    if(ano<2010 || ano>10000)return (0);
    aux=2062;

    while(ano>=aux)aux+=76;
                
    printf("%d\n", aux);
    return (0);
}  
