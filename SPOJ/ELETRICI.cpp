#include <stdio.h>
#include <stdlib.h>

int dias=0, custo=0;

int ultimo_dia(int M, int Y)
{
    switch(M)
    {
    case 1: 
         return 31;
    case 2:
            if(Y%4 == 0 && Y%100 != 0)return 29;
            else return 28;
    case 3:
         return 31;
    case 4:
         return 30;
    case 5:
         return 31;
    case 6:
         return 30;
    case 7:
         return 31;
    case 8:
         return 31;
    case 9:
         return 30;
    case 10:
         return 31;
    case 11:
         return 30;
    case 12:
         return 31;
    }
} 

int main(void)
{
    int N, D, M, Y, C, Daux, Maux, Yaux, Caux;
    
    for(;;)
    {
        scanf("%d", &N);
        if(N==0)return 0;
        
        scanf("%d %d %d %d", &Daux, &Maux, &Yaux, &Caux);
        
        for(int i=0;i<(N-1);i++)
        {
            scanf("%d %d %d %d", &D, &M, &Y, &C);
            if(Maux == 12 && Daux == 31 && D == 1 && M==1 && Y-Yaux == 1)
            {
                    custo += (C-Caux);
                    dias++;
            }
            else
            {
                if(Daux == ultimo_dia(Maux, Yaux) && D == 1 && M-Maux == 1 && Yaux==Y)
                {
                        custo+=(C-Caux);
                        dias++;
                }
                else
                {
                    if(D - Daux == 1 && M == Maux && Yaux==Y)
                    {
                        custo+=(C-Caux);
                        dias++;
                    }
                }
            } 
            Maux = M; Daux = D; Yaux = Y; Caux = C;     
        }
        
        printf("%d %d\n", dias, custo);
        custo = 0; dias = 0;
    }
    return 0;
}
