#include <stdio.h>
#include <string.h>  


int mergeSort2(int *vet1, int *vet2, int ini,int divisao_merge,int fim){
 int i,j,k;
 
 int contador;
 
 for(i=ini;i<=divisao_merge;i++)
  vet2[i] = vet1[i];
  
 for(j=divisao_merge+1;j<=fim;j++)
  vet2[fim+divisao_merge+1-j]=vet1[j];
  
 i = ini;
 j = fim;
 contador = 0;
 
 for(k=ini;k<=fim;k++){
  if(vet2[i] <= vet2[j]){
   vet1[k] = vet2[i];
   i = i+1;
  }else{
   vet1[k] = vet2[j];
   j = j-1;
   contador = contador + (divisao_merge-i+1);
  }
 }
 
 return contador;
 
}
 
 
 
int mergeSort(int *vet1, int *vet2, int ini,int fim){
 int divisao_merge, soma_final;
 if(ini >=fim ) return 0;
 else{
  divisao_merge = (ini+fim)*1/2;
  soma_final=mergeSort(vet1, vet2, ini, divisao_merge) + mergeSort(vet1, vet2, (divisao_merge)+1, fim)+mergeSort2(vet1, vet2, ini, (divisao_merge), fim);
 return soma_final;
 }
}

int main() 
{ 
  int N, i;
  scanf("%d", &N);
  int vet[N], vet3[N];
  memset(vet3, 0, sizeof(vet3));
  for(i=0;i<N;i++)scanf("%d", &vet[i]);
  printf("%d\n", mergeSort(vet, vet3, 0, N-1));
  return(0);
}  
