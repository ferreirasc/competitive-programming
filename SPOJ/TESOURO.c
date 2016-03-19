    #include <stdio.h>   
    int v[101];  
    char m[101][10001];  
      
    int main (void)  
    {  
      int x, y, n;  
      int i, j, max, b;  
      int iCaso = 1;  
      int result;  
      
      for (;;)  
      {  
          scanf ("%d %d %d", &x, &y, &n);  
          if ((x == 0) && (y == 0) && (n == 0))  
              break;  
          max = 0;  
          for (i = 1; i <= n; i++)  
          {  
              scanf ("%d", &v[i]);  
              max += v[i];  
          }  
          if (x > y)  
              b = max + y - x;  
          else  
              b = max + x - y;  
          if ((b < 0) || ((b & 1) != 0))  
              result = 0;  
          else if (b == 0)  
              result = 1;  
          else  
          {  
              b = b/2;   
              for (i = 1; i <= b; i++)  
                  m[1][i] = 0;
                  
              m[1][v[1]] = 1;  
                
              for (i = 2; i <= n; i++)  
              {  
                  for (j = 1; j <= b; j++)  
                  {  
                      if (j == v[i])  
                          m[i][j] = 1;  
                      else if (j < v[i])  
                          m[i][j] = m[i-1][j];  
                      else if (m[i-1][j] || m[i-1][j - v[i]])  
                          m[i][j] = 1;  
                      else  
                          m[i][j] = 0;  
                  } 
             
              }  
              result = m[n][b];  
           
          }  
          printf ("Teste %d\n%c\n\n", iCaso, result ? 'S' : 'N');  
          iCaso++;  
      }  
      
      return 0;  
    }  
