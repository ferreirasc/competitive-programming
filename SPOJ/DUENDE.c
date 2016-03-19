/*Leonardo Ferreira - ENG COMP - UFES*/
/*PROBLEMA SPOJ - "DUENDES" - BFS*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct nofila
{
        int x, y, mov;
        struct nofila *prox;
}nofila;

typedef struct fila
{
        nofila *inicio;
        nofila *fim;
}fila;

void cria_fila(fila *p)
{
     p->inicio=p->fim=NULL;
}

void insere_fila(fila *p, int x, int y, int mov)
{
     nofila *novo;
     novo = (nofila *)malloc(sizeof(nofila));
     novo->x = x;
     novo->y = y;
     novo->mov = mov;
     novo->prox = NULL;
     if((*p).inicio==NULL && (*p).fim==NULL)
     {
        p->inicio = novo;
     }
     else
     {
     p->fim->prox = novo;
     }
     p->fim = novo;
}

void remove_fila(fila *p)
{
     nofila *aux;
     aux=p->inicio;
     p->inicio = p->inicio->prox;
     free(aux);
}

int lista_vazia(fila *p)
{
     if(p->inicio==NULL && p->fim==NULL)return 1;
     else return 0;
}

int mat[MAX][MAX], visitados[MAX][MAX];

int verifica(int x, int y, int N, int M){
    return(x >= 0 && y >= 0 && x < N && y < M && !visitados[x][y] && mat[x][y] != 2);
    }

int bfs(fila *q, int xi, int yi, int N, int M)
{
    insere_fila(q, xi, yi, 0);
    nofila *atual;
    atual = (nofila *)malloc(sizeof(nofila));
    while(!lista_vazia(q))
    { 
    atual=q->inicio;
    visitados[(*atual).x][(*atual).y]=1;
    if(mat[(*atual).x][(*atual).y]==0)return ((*atual).mov);
    
    /*Adjacencias - Pensar num modo mais inteligente*/
    if(verifica(((*atual).x)+1, (*atual).y, N, M))insere_fila(q,((*atual).x)+1, (*atual).y, ((*atual).mov)+1);
    if(verifica(((*atual).x), ((*atual).y)+1, N, M))insere_fila(q,((*atual).x), ((*atual).y)+1, ((*atual).mov)+1);
    if(verifica(((*atual).x), ((*atual).y)-1, N, M))insere_fila(q,((*atual).x), ((*atual).y)-1, ((*atual).mov)+1);
    if(verifica(((*atual).x)-1, ((*atual).y), N, M))insere_fila(q,((*atual).x)-1, ((*atual).y), ((*atual).mov)+1);
    
    remove_fila(q);
    }
    free(atual);        
}

int main(void)
{
    int N,M,xi,yi,i,j;
    scanf("%d %d", &N, &M);
    
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            scanf("%d", &mat[i][j]);
            if(mat[i][j]==3){xi=i;yi=j;}
        }
    }
    
    fila *fila2;
    fila2 = (fila *)malloc(sizeof(fila));
    cria_fila(fila2);
    printf("%d\n",bfs(fila2, xi, yi, N, M));
    free(fila2);
    return 0;
}
