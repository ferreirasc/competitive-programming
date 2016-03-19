#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        int L, D, K, P, cont = 0, flag=0, caminho = 0;
        scanf("%d %d", &L, &D);
        scanf("%d %d", &K, &P);
        //Numero de Pedagios
        
        while(1)
        {
                caminho = caminho + D;
                if(caminho<=L)cont++;
                else break;
                flag = 1;
        }
        if(flag)
        printf("%d\n", K*L + cont*P);
        else printf("%d\n", K*L);
        return 0;
}