#include <stdio.h>
#define MAXSTR 21

int lestring(char s[][MAXSTR], int max)
{
    int i = 0;
    char letra;

    
    for (i = 0; i < (max - 1); i++) {
	letra = fgetc(stdin);

	
	if ((letra == '\n') && (i == 0)) {
	    i = i - 1;
	    continue;
	}

	
	if (letra == '\n')
	    break;
	s[0][i] = letra;
    }

    /* Finaliza a string */
    s[0][i] = 0;

    return (i);
}


int main()
{
    int n, x, i, t, j, aux[MAXSTR];
    scanf("%d %d", &n, &x);
    if(x<1 || n<x || n>100)return(0);
    char nome[n][MAXSTR];
    for(i=0;i<n;i++)lestring(nome[i], MAXSTR);
    for(j=0; j<n; j++)
    {
    for(i=j+1;i<n; i++)
    {
    if(strcmp(nome[j], nome[i]) > 0)
    {
    strcpy(aux, nome[j]);
    strcpy(nome[j], nome[i]);
    strcpy(nome[i], aux);
    }
    }
    }
    printf("%s\n", nome[x-1]);
    
    return (0);
}