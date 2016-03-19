#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int N;
    register int i,j;
    scanf("%d", &N);
    int vet_x[N], vet_y[N];
    double menor=20000000000000.0, aux;
    
    for(i=0;i<N;i++)
    {
    scanf("%d %d", &vet_x[i], &vet_y[i]);
    }
    
    for(i=0;i<N;i++)
    {
    for(j=i+1;j<N;j++)
    {
    aux=(pow((vet_x[i]-vet_x[j]),2)+pow((vet_y[i]-vet_y[j]),2));
    if(aux<menor)menor=aux;
    }
    }
    
    printf("%.03f\n", sqrt(menor));
    return 0;
}

