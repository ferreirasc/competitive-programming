#include <stdio.h>
#include <stdlib.h>

int matriz[502][502];

int main(void)
{
        int i, N, k, l, flag = 0;
        scanf("%d", &N);
        for(i=0;i<N;i++)
        {
                scanf("%d %d", &k, &l);
                if(matriz[k][l])
                {
                        flag = 1;
                }
                matriz[k][l] = 1;
        }
        if(flag)printf("1\n");
        else printf("0\n");
        return 0;
}