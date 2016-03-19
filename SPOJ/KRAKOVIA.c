#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    
    int N=1, n, f, cont, res[31], soma[31], i, tam, y, sob, x, p, max; 
    
    while (1) {
          
          scanf ("%d %d", &n, &f);
          
          if (n==0&&f==0) break;
          
          for (i=0; i<=30; i++) res[i]=soma[i]=0;
          sob=0;
          max=30;
          
          for (cont=1; cont<=n; cont++) {
              char num[31];
              scanf ("%s", &num);
              tam=strlen(num);
              p=30;
              for (i=tam-1; i>=0; i--) {
                  x=soma[p]+(num[i]%48)+sob;
                  soma[p]=x%10;
                  sob=(x-(x%10))/10;
                  p--;
              }
          
              if (sob!=0) 
                 while (sob!=0) { 
                       x=soma[p]+sob;
                       soma[p]=x%10;
                       sob=(x-(x%10))/10;
                       p--;      
                   }
                   
              if (p<max) max=p;
          }
          
          printf ("Bill #%d costs ", N++);
          for (i=max+1; i<=30; i++) printf ("%d", soma[i]);
          printf (": each friend should pay ");
          
          int resto=0;      
          for (i=max+1; i<30; i++) {
              resto=soma[i]%f;
              soma[i]=(soma[i]-resto)/f;
              soma[i+1]+=(10*resto);   
          }
          soma[i]=soma[i]/f;
          
          for (i=0; i<=30; i++) if (soma[i]!=0) break;
          if(i == 31){
          printf("%d\n\n", 0);
          continue;
          }
          for (i=i; i<=30; i++) printf ("%d", soma[i]);
          printf ("\n\n");
    
    }
    
    return 0;
}