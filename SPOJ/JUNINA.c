#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int verifica(int *relatorio, int *estao)
{
    int j;
    for(j=1;;j++)
    {
        if(relatorio[j]==0)return 0;
        else if(estao[(relatorio[j])]==1)return 1;
    }
}

int main(void)
{   
    int u;
    for(u=0;;u++)
    {
        int n, i, j, cont=0, k, x, maior=0;
        scanf("%d", &n);
        if(n==0)break;
        int nentra[n+1], relatorio[n+1][n+2], estao[n+1], maiores[n+1], maiores2[n+1];
        memset(nentra, 0, sizeof(nentra)); 
        memset(estao, 0, sizeof(estao));
        memset(maiores, 0, sizeof(maiores)); 
        memset(maiores2, 0, sizeof(maiores2));
        
            for(i=1;i<=n;i++)
            {
                for(j=1;;j++)
                {
                    scanf("%d", &relatorio[i][j]);
                    if(relatorio[i][j]==0)break;
                }
            }
            
            for(k=1;k<=n;k++)
            {
                for(x=k,i=1;i<=n;i++,x--)
                {
                    if(x==0)x=n;
                    if(nentra[x]!=1 && verifica(relatorio[x], estao)!=1)
                    {
                        estao[x]=1;
                        cont++;
                               for(j=1;;j++)
                               {
                                    if(relatorio[x][j]==0)break;
                                    else nentra[(relatorio[x][j])]=1;
                               }
                    }
                }
                if(cont>maior)maior=cont;
                cont=0;
                memset(nentra, 0, sizeof(nentra)); 
                memset(estao, 0, sizeof(estao));
                for(x=k,i=1;i<=n;i++,x++)
                {
                    if(x==(n+1))x=1;
                    if(nentra[x]!=1 && verifica(relatorio[x], estao)!=1)
                    {
                        estao[x]=1;
                        cont++;
                               for(j=1;;j++)
                               {
                                    if(relatorio[x][j]==0)break;
                                    else nentra[(relatorio[x][j])]=1;
                               }
                    }
                }
                if(cont>maior)maior=cont;
                cont=0;
                memset(nentra, 0, sizeof(nentra)); 
                memset(estao, 0, sizeof(estao));
            }
            
            printf("Teste %d\n", u+1);
            printf("%d\n", maior);
            printf("\n");
    }
    return 0;  
}


