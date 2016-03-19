#include <stdio.h>
#include <string.h>

typedef struct comp
{
        char nome[20];
        int pont[12];
        int total;
}comp;

comp info[1000];
comp aux;

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

int soma(int *v)
{
    int soma=0, i;
    for(i=1;i<11;i++)soma=soma+v[i];
    return soma;
}
    

int main(void)
{
    int j, i, ini, aux2, k, x=1;
    
    for(;;)
    {
    scanf("%d", &ini);
    if(ini==0)break;
    k=1;
        for(j=0;j<ini;j++)
        {
        scanf("%s", info[j].nome);
        for(i=0;i<12;i++)scanf("%d", &info[j].pont[i]);
        quick(info[j].pont, 0, 11);
        info[j].total = soma(info[j].pont);
        }
        
        for(i=0;i<ini;i++)
        {
            for(j=i+1;j<ini;j++)
            {
                if(info[i].total<info[j].total)
                {
                    aux=info[j];
                    info[j] = info[i];
                    info[i] = aux;
                }
                else
                {
                    if(info[i].total==info[j].total)
                    {
                        if(strcmp(info[i].nome,info[j].nome)>0)
                        {
                        aux=info[j];
                        info[j] = info[i];
                        info[i] = aux;
                        }
                    }
                }
                
            }
        }
        
        aux2=info[0].total;
        printf("Teste %d\n", x);
        printf("%d %d %s\n", k, info[0].total, info[0].nome);
        
        for(i=1;i<ini;i++)
        {
        if(aux2==info[i].total){
                                printf("%d %d %s\n", k, info[i].total, info[i].nome);
                                }
        else{
             aux2=info[i].total;
             k=i+1;
             printf("%d %d %s\n", i+1, info[i].total, info[i].nome);
             }
        }
        x++;
    }
    
    return 0;
}
