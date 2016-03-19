#include <stdio.h>

void Quick(int vetor[], int vet2[], int inicio, int fim){
	
	register int pivo, aux, i, j, meio, aux2;
	
	i = inicio;
	j = fim;
	
	meio = (int) ((i + j) / 2);
	pivo = vetor[meio];
	
	do{
		while (vetor[i] < pivo) i = i + 1;
		while (vetor[j] > pivo) j = j - 1;
		
		if(i <= j){
			aux = vetor[i];
			aux2 = vet2[i];
			vetor[i] = vetor[j];
			vet2[i]=vet2[j];
			vet2[j]=aux2;
			vetor[j] = aux;
			i = i + 1;
			j = j - 1;
		}
	}while(j > i);
	
	if(inicio < j) Quick(vetor, vet2, inicio, j);
	if(i < fim) Quick(vetor, vet2, i, fim);	

}

int main(void)
{
	int n, m;
	register int i, cont=0;
	for(cont=0;;cont++)
	{
	scanf("%d %d", &n, &m);
	if(n==0 && m==0)return 0;
	int vet1[m], vet2[m], vet_atual[2];
	for(i=0;i<m;i++)scanf("%d %d", &vet1[i], &vet2[i]);
	
	Quick(vet1, vet2, 0, m-1);
	
	printf("Teste %d\n", cont+1);
	
	vet_atual[0] = vet1[0];
	vet_atual[1] = vet2[0];
	
	for(i=1;i<m;i++)
	{
		if(vet1[i]<=vet_atual[1])
		{
			if(vet2[i]>vet_atual[1])vet_atual[1]=vet2[i];
		}
		else
		{
			printf("%d %d\n", vet_atual[0], vet_atual[1]);
			vet_atual[0]=vet1[i];
			vet_atual[1]=vet2[i];
		}
	}
	
	printf("%d %d\n", vet_atual[0], vet_atual[1]);
	printf("\n");
	}
	return 0;
}