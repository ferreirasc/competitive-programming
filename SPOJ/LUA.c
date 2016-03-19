#include <stdio.h>

int main(void)
{
    int n, m, i, maior=-201, menor=201, j=0, temp=0, k=0, t=1, s=1, equal=0, rao=0, xis;
    
    for(;;)
    {
        scanf("%d %d", &n, &m);
        if(n==0 || m==0)return 0;
        if(n<0 || n>10000 || n<m || m<1)return 0;
        int vet[n];
        
            for(i=0;i<n;i++)
            {
                scanf("%d", &vet[i]);
                if(vet[i]<-200 || vet[i]>200)return 0;
            }
        
        
          if(k==0){
                for(i=0;i<m;i++)
                {
                    temp=(temp-rao)+vet[i];
                }
                k++;
                xis=temp/m;
                if(xis>maior)maior=xis;
                if(xis<menor)menor=xis;
            }
            s=1;
            if(k!=0)
            {
                while((s+m)<=n)
                {
                    rao=vet[j];
                    temp=(temp-rao)+vet[i];
                    i++;
                    s++;
                    j++;
                    xis=temp/m;
                    if(xis>maior)maior=xis;
                    if(xis<menor)menor=xis;
                }
            }
        
        printf("Teste %d\n", t);
        printf("%d %d\n\n", menor, maior);
        j=0;
        i=0;
        k=0;
        s=0;
        rao=0;
        xis=0;
        maior=-201;
        menor=201;
        temp=0;
        t++;
        }
       
return 0;
}
