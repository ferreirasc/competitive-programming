#include <stdio.h>

void shellSort(int * vet, int size) {
    int i , j , value;
    int gap = 1;
    do {
        gap = 3*gap+1;
    } while(gap < size);
    do {
 gap /= 3;
 for(i = gap; i < size; i++) {
            value =vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] =vet[j];
                j -= gap;
            }
            vet [j + gap] = value;
        }
    } while ( gap > 1);
}


int main(void)
{
    int n, i, k=0, j=0, z=0, count=0, maior, flag=0, aux;
    scanf("%d", &n);
    if(n<1 || n>100000)return 0;
    int vet1[n], vet2[(2*n)];
        for(i=0;i<n;i++)
        {
        scanf("%d", &vet1[i]);
        if(vet1[i]<=1 || vet1[i]>1000000000)return 0;
        }
        
        shellSort(vet1, n);
        
    maior=-1;                       
    for(i=0;i<n;i++)
    {
    for(j=i+1;j<n;j++)
    {
    if(vet1[i]==vet1[j]){
                         count++;
                         if(count>maior){
                                         maior=count;
                                         z=i;
                                         }
                         }
                         else{
                              break;
                              }
    }
    count=0;
    }
    
    printf("%d\n", vet1[z]);
                               
    return 0;
}

