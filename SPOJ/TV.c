#include <stdio.h>
#include <stdlib.h>
 
int main(){
    int linhas, colunas, teste = 1;
 
    while( scanf( "%d%d", &linhas, &colunas ) ){
        if( !colunas ) return 0;
        register int i, j, ni = 0, nj = 0;
 
        int **mat  = (int **) malloc( 4 * linhas );
        for( i = 0; i < linhas; i++ ){
            mat[i] = (int *)malloc( 4 * colunas );
        }
 
 
        for( i = 0; i < linhas; i++ ){
            for( j = 0; j < colunas; j++ ){
                scanf( "%d", &mat[i][j] );
            }
        }
 
        int x, y;
 
        while( scanf( "%d%d", &x, &y ) ){
            if( !x && !y ) break;
            ni += y;
            nj += x;
        }
 
        printf( "Teste %d\n", teste++ );
 
        if( ni < 0 ) ni =  linhas + ni % linhas;
        else ni = ni % linhas;
 
        if( nj < 0 ) nj = abs(nj % colunas);
        else nj = colunas - nj % colunas;
 
        for( i = ni; i < linhas + ni; i++ ){
            for( j = nj; j < colunas + nj; j++ ){
                printf( "%d ", mat[ i % linhas][ j % colunas ] );
            }
            printf( "\n" );
        }
        printf( "\n" );
    }
}