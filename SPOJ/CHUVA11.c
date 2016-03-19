#include <stdio.h>

int main(void)
{
    int n;
    register int i, j;
    scanf("%d", &n);
    unsigned int map[n][n], map2[n][n];
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)scanf("%d", &map[i][j]);
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
        scanf("%d", &map2[i][j]);
        printf("%d ", map[i][j]+map2[i][j]);
        }
        printf("\n");
    }
    
    return 0;   
}

