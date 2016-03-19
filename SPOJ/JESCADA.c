#include <stdio.h>

int main(void)
{
    int n, valor, i, cont=0, inicio, cont2=0, aux, instante;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
    scanf("%d", &valor);
    if(i==0){inicio=valor;cont=valor+10;instante=cont;continue;}
    else{
         if(valor<=instante)
         {
         cont=cont+(valor+10-instante);
         instante=instante+(valor+10-instante);
         }
         else
         {
             cont=cont+10;
             instante=valor+10;
         }
         }
    }
    printf("%d\n", cont-inicio);
    return 0;
}
