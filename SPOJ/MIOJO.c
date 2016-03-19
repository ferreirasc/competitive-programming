#include <stdio.h>

int main(void)
{
    int t, a, b, i=1, fixa, fixb, dif, j=1, tt, aux;
    scanf("%d %d %d", &t, &a, &b);
    
    if(a>b)
    {
        aux=a;
        fixa=b;
        fixb=aux;
    }
    
    fixa=a;
    fixb=b;
    
    while(1)
    {
        if(fixa==t){tt=i*a;break;}
        else{
        if(fixb==t){tt=j*b;break;}
        }
        
        dif=fixa-fixb;
        
            if(dif<0)
            {
                fixa=a;
                fixb=dif*(-1);
                i++;
            }
        
            if(dif>0)
            {
                fixa=dif;
                fixb=b;
                j++;
            }   
    }
    printf("%d\n", tt);  
    return 0;
}
