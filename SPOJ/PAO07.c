#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Quick(int vetor[], int inicio, int fim){
	
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
	
	if(inicio < j) Quick(vetor, inicio, j);
	if(i < fim) Quick(vetor, i, fim);	

}


int main(void)
{
    int n, k;
    register int soma=0, cont=0, i, flag=0, contatual, valorinicio, flag2=1, deu_mais=0;
    scanf("%d", &n);
    scanf("%d", &k);
    int vet[k];
    
    for(i=0;i<k;i++)
    {
    scanf("%d", &vet[i]);
    soma+=vet[i];
    }
    
    valorinicio=(int)(soma/n);
    Quick(vet, 0, k-1);
    valorinicio=(int)(valorinicio/(1.2));
    
    for(;;)
    {
        for(i=k-1;i>=0;i--)
        {
            cont+=(int)(vet[i]/valorinicio);
            contatual=(int)(vet[i]/valorinicio);
            if((i*contatual+cont)>=n){flag=1;continue;}
            else{flag=0;break;}
        }
        
        if(flag==1)
        {
        deu_mais=1;
        valorinicio++;
        }
        if(flag==0)
        {
        if(deu_mais==1){printf("%d\n", valorinicio-1);break;}
        valorinicio--;
        }
        cont=0;
    }
    
    return 0;
}
    
