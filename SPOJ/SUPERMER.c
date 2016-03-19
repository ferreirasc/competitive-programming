#include <stdio.h>
#include <stdlib.h>

void quick(int vetor[], int inicio, int fim){
	
	int pivo, aux, i, j, meio;
	
	i = inicio;
	j = fim;
	
	meio = (int) ((i + j) / 2);
	pivo = vetor[meio];
	
	do{
		while (vetor[i] < pivo) i = i + 1;
		while (vetor[j] > pivo) j = j - 1;
		
		if(i <= j){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i = i + 1;
			j = j - 1;
		}
	}while(j > i);
	
	if(inicio < j) quick(vetor, inicio, j);
	if(i < fim) quick(vetor, i, fim);	

}

int main(void)
{
    int n, k, i;
    for(k=0;;k++)
    {
        scanf("%d", &n);
        if(n==0)return 0;
        int coord_x[n], coord_y[n];
        
        for(i=0;i<n;i++)
        {
        scanf("%d %d", &coord_x[i], &coord_y[i]);
        }
        
        quick(coord_x, 0, n-1);
        quick(coord_y, 0, n-1);
        
        if(n % 2 == 0)
        {
        printf("Teste %d\n", k+1);
        printf("%d %d\n", (coord_x[((n/2)-1)]+coord_x[(((n+2)/2)-1)])/2, (coord_y[((n/2)-1)]+coord_y[(((n+2)/2)-1)])/2);
        }
        else
        {
        printf("Teste %d\n", k+1);
        printf("%d %d\n", coord_x[((n+1)/2)-1], coord_y[((n+1)/2)-1]);
        }
    }
    
    return 0;
    }
