#include <stdio.h>
#include <stdlib.h>

int vet[1000][1000], vet_linha[1000], vet_coluna[1000];

void cambia_linha(int i, int i2, int jtotal)
{
     register int j; 
     int aux;
     for(j=0;j<jtotal;j++)
     {
                          aux=vet[i][j];
                          vet[i][j]=vet[i2][j];
                          vet[i2][j]=aux;
     }
}

void cambia_coluna(int j, int j2, int itotal)
{
     register int i; 
     int aux;
     for(i=0;i<itotal;i++)
     {
                          aux=vet[i][j];
                          vet[i][j]=vet[i][j2];
                          vet[i][j2]=aux;
     }
}

int main(void)
{
    int jtotal, itotal, trocasc=0, trocasl=0;
    register int i,j, x, y, u, k;
    scanf("%d %d", &itotal, &jtotal); 
    
    for(i=0;i<itotal;i++)
    {
    for(j=0;j<jtotal;j++)scanf("%d", &vet[i][j]);
    }
    
    u=jtotal;
    k=jtotal;
    x=0;
    for(i=0;i<itotal;i++)
    {
    	for(j=0;j<jtotal;)
    	{
    		if(vet[i][j]>u)
    		{
    			k=jtotal;
    			while(1)
    			{
    				k+=jtotal;
    					if(vet[i][j]<=k)
    					{
    						cambia_linha(i, (k/jtotal)-1, jtotal);
    						trocasl++;
    						vet_linha[x]=(k/jtotal);
                            vet_linha[x+1]=i+1;
                            x+=2;
    						break;
     					}
    			}
    
    		}
    
    		else
    		{
                break;
    		}
    	}
    	u+=jtotal;
    }
    
    y=0;
    
    for(j=0;j<jtotal;)
    {
    if(vet[0][j]==(j+1))j++;
    else{
         trocasc++;
         vet_coluna[y]=(vet[0][j]);
         vet_coluna[y+1]=(j+1);
         y+=2;
         cambia_coluna(j,(vet[0][j]-1), itotal);
    }
    }
    
    printf("%d\n", trocasl+trocasc);
    for(i=0;i<(trocasl*2);i+=2)printf("L %d %d\n", vet_linha[i], vet_linha[i+1]);
    for(i=0;i<(trocasc*2);i+=2)printf("C %d %d\n", vet_coluna[i], vet_coluna[i+1]);
    
    return 0;
}

