#include <stdio.h>

int main() {
  int i,j,N,M,m,lastc,c,flag;
  char ans = 'S';
  
  scanf("%d%d",&N,&M);
  for ( lastc = -1, i = 0; i < N; i++ ){
    for ( flag = 1, c = 0, j = 0; j < M; j++ ){
      scanf("%d",&m);
      if ( m == 0 && flag ) c++; else flag = 0;
    }
    if ( c <= lastc && c < M ){
      ans = 'N'; break;
    }
    lastc = c;
  }

  printf("%c\n",ans);
  return 0;
}