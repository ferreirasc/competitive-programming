#include <stdio.h>
#include <string.h>
#define MAX 100000
 
/* Entrada */
int T,N,A,Q;
long long L;
/* Árvore */
int pai[MAX];
long long len[MAX];
int heigth[MAX];
 
/* Encontra o pai comum entre x e y */
/* Retorna o tamanho do caminho que liga os dois nós */
long long solve(int x, int y)
{
  int i,j;
  long long r=0;
  if(heigth[x]>heigth[y]){
    for(i=x; heigth[i]!=heigth[y]; i=pai[i])
      r+=len[i];
    x=i;
  }
  else if(heigth[y]>heigth[x])
  {
    for(i=y; heigth[i]!=heigth[x]; i=pai[i])
      r+=len[i];
    y=i;
  }
  /* Vai subindo na arvore, um nó por vez. */
  /* Pára quando os pais forem iguais */
  for(i=x, j=y; i!=j; i=pai[i],j=pai[j])
    r+=(len[i]+len[j]);
  return r;
}
int main()
{
  int i;
  while(1)
  {
    scanf("%d",&N);
    if(N==0) break;
    /* Criamos várias árvores de altura 1 */
    for(i=0;i<=N;i++)
    {
      pai[i]=i;
      heigth[i]=1;
    }
    /* Construir uma única árvore */
    /* Isso é feito unindo os árvores do passo anterior */
    /* As uniões são feitas com base na entrada */
    for(i=1;i<N;i++)
    {
      /* Ant hill i is connected to A */
      /* The path has length L */
      scanf("%d %d",&A,&L);
      pai[i]=A; len[i]=L;
      /* Como juntamos 2 árvores a altura é a soma das 2 */
      heigth[i]+=heigth[A];
    }
    scanf("%d",&Q);
    for(i=0;i<Q;i++)     {       /* Query: src -> dest */
      scanf("%d %d",&A,&L);
      /* Encontra o pai comum */
      printf("%lld ", solve(A,L));
    }
    printf("\n");
  }
  return 0;
}