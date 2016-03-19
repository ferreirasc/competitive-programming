#include <stdio.h>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef struct jogador_struct
{
        char nome[51];
        int habilidade;
}jogadores;

vector<jogadores>times[1001];
jogadores jogador[10001];

void Quick(jogadores vetor[], int inicio, int fim){
	
	int pivo, i, j, meio;
	jogadores aux;
	
	i = inicio;
	j = fim;
	
	meio = (int) ((i + j) / 2);
	pivo = vetor[meio].habilidade;
	
	do{
		while (vetor[i].habilidade < pivo) i = i + 1;
		while (vetor[j].habilidade > pivo) j = j - 1;
		
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
    int qtd_alunos, numero_times;
    register int i, j;
    scanf("%d %d", &qtd_alunos, &numero_times);
    
    jogadores aux;
    
    for(i=0;i<(qtd_alunos);i++)scanf("%s %d", jogador[i].nome, &(jogador[i].habilidade));
    for(i=0;i<1001;i++)times[i].clear();
    
    Quick(jogador, 0, (qtd_alunos)-1);    
    
    register int k = (qtd_alunos-1);
    while(k>=0)
    {
        for(j=0;j<(numero_times);j++,k--)
        {
            if(k<0)break;
            times[j].push_back(jogador[k]);
        }
    } 
    
    
    for(k=0;k<(numero_times);k++)
    {
        int prox = times[k].size();
        for(i=0;i<prox;i++)
        {
            for(j=i+1;j<prox;j++)
            {
                if(strcmp(times[k][i].nome,times[k][j].nome)>0)
                {
                    aux=times[k][j];
                    times[k][j] = times[k][i];
                    times[k][i] = aux;
                }
            }
        }
    }
    
    for(i=0;i<(numero_times);i++)
    {
        printf("Time %d\n", i+1);
        for(j=0;j<(times[i].size());j++)printf("%s\n", times[i][j].nome);
        printf("\n");
    }
    return 0;
}
