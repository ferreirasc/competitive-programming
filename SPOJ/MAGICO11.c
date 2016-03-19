#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int N, i, j;
    scanf("%d", &N);
    int esta[(N*N)+1], mat[N][N], somalinha[N], somacoluna[N], somadiagonal=0;
    memset(esta, 0, sizeof(esta));
    memset(somalinha, 0, sizeof(somalinha));
    memset(somacoluna, 0, sizeof(somacoluna));    
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d", &mat[i][j]);
            if(esta[(mat[i][j])]==1){printf("0\n");return 0;}
            else esta[(mat[i][j])]=1;
            somalinha[i]+=mat[i][j];
            somacoluna[j]+=mat[i][j];
            if(i==j)somadiagonal+=mat[i][j];
            if(i==N-1){
                       if(somacoluna[j]!=somalinha[0]){printf("0\n");return 0;}
                       }
        }
        if(i>0)
        {
            if(somalinha[i]==somalinha[i-1])continue;
            else{printf("0\n");return 0;}
        }
        if(i==N-1){
                   if(somadiagonal!=somalinha[0]){printf("0\n");return 0;}
                   }        
    }
    
    printf("%d\n", somadiagonal);                
        
    return 0;
}
