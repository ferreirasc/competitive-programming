#include <stdio.h>

int main(void)
{
    int T, N, i=0, j=0, balao=1, max[4], k, maximo=0, t=0;
    max[0]=max[1]=max[2]=max[3]=0;
    scanf("%d", &T);
    
    for(k=0;k<T;k++)
    {
        scanf("%d", &N);
        if(N<1 || N>1000)return 0;
        int vetx[N], vety[N];
    
        for(i=0;i<N;i++)
        {
            scanf("%d %d", &vetx[i], &vety[i]);
            if(vetx[i]<(-100000) || vetx[i]>100000 || vety[i]<(-1000000) || vety[i]>1000000)return 0;
        }
    
        for(i=0;i<N-1;i++)
        {
            for(j=i+1;j<N;j++)
            {
                if(vetx[i]==vetx[j] && vety[i]==vety[j])return 0;
            }
        }
    
        for(i=0;i<N-1;i++)
        {
            for(j=i+1;j<N;j++)
            {
                if(vetx[i]==vetx[j])balao++;
                if(balao>max[0])max[0]=balao;
            }
            balao=1;
        }
        
        for(i=0;i<N-1;i++)
        {
            for(j=i+1;j<N;j++)
            {
                if(vety[i]==vety[j])balao++;
                if(balao>max[1])max[1]=balao;
            }
            balao=1;
        }
        
        
        
        for(i=0;i<N-1;i++)
        {
            for(j=i+1;j<N;j++)
            {
                if((vety[i]-vety[j])==(vetx[i]-vetx[j]))balao++;
                if(balao>max[2])max[2]=balao;
            }
            balao=1;
        }
        
        for(i=0;i<N-1;i++)
        {
            for(j=i+1;j<N;j++)
            {
                if(((vety[i]-vety[j])*(-1))==(vetx[i]-vetx[j]) || (vety[i]-vety[j])==((vetx[i]-vetx[j])*(-1)))balao++;
                if(balao>max[3])max[3]=balao;
            }
            balao=1;
        }
        
                
        for(i=0;i<4;i++)
        {
        if(max[i]>=maximo)maximo=max[i];
        }
        printf("%d\n", maximo);
        max[0]=max[1]=max[2]=max[3]=0;
        maximo=0;
   
    }
    
    return 0;
}
