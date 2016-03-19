#include <stdio.h>

int main(void)
{
    int n, m, u, indice;
    register int i, j;
    scanf("%d", &n);
    int vet[1000], valored[1000], valorde[1000], menor1=100000;
    
    for(u=0;u<n;u++)
    {
        scanf("%d", &m);
        for(i=0;i<m;i++)scanf("%d", &vet[i]);
        
            for(j=0;j<(m-1);j++)
            {
                if((vet[j]-vet[j+1])<=0)valored[u]+=abs(vet[j]-vet[j+1]);
                else{
                if((vet[j]-vet[j+1])>=0)valorde[u]+=((vet[j]-vet[j+1]));
                }
            }
            
            if(valored[u]==0 || valorde[u]==0){printf("%d\n", u+1);return 0;}
            if(valored[u]<menor1){menor1=valored[u];indice=u;}
            if(valorde[u]<menor1){menor1=valorde[u];indice=u;}
    }
    
    printf("%d\n", indice+1); 
    return 0;
}
