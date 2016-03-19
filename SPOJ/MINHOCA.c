#include <stdio.h>

int main(void)
{
    long int n,m,i,j, max, max2=0;
    scanf("%ld %ld", &n, &m);
    if(n<1 || m<1 || n>100 || m>100)return(0);
    long int mat[n][m], valor[m], valor2[n];
    
    for(i=0;i<m;i++)
    valor[i]=0;
    
    for(i=0;i<n;i++)valor2[i]=0;
    
    
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%ld", &mat[i][j]);
                if(mat[i][j]<0 || mat[i][j]>500)return(0);
              }
        }
    
    max=valor[0];
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            valor[i]=valor[i]+mat[j][i];
        }
        if(valor[i]<0 || valor[i]>50000)return(0);
        if(valor[i]>max)max=valor[i];
    }
    
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            valor2[i]=valor2[i]+mat[i][j];
        }
        if(valor2[i]<0 || valor2[i]>50000)return(0);
        if(valor2[i]>max2)max2=valor2[i];
    }
    
    if(max2>max)
    printf("%ld\n", max2);
    if(max>max2)printf("%ld\n", max);
    if(max==max2)printf("%ld\n", max);
    
    return 0;
}
