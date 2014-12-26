#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int musica[100000], dif2[100000], dif[100000], cont=0;
char tecla[3];

int *compute_prefix_function(int *pattern, int psize)
{
	int k = -1;
	int i = 1;
	int *pi = (int *)malloc(sizeof(int)*psize);
	if (!pi)
		return NULL;

	pi[0] = k;
	for (i = 1; i < psize; i++) {
		while (k > -1 && pattern[k+1] != pattern[i])
			k = pi[k];
		if (pattern[i] == pattern[k+1])
			k++;
		pi[i] = k;
	}
	return pi;
}

int kmp(int *target, int tsize, int *pattern, int psize)
{
	int i;
	int *pi = compute_prefix_function(pattern, psize);
	int k = -1;
	if (!pi)
		return -1;
	for (i = 0; i < tsize; i++) {
		while (k > -1 && pattern[k+1] != target[i])
			k = pi[k];
		if (target[i] == pattern[k+1])
			k++;
		if (k == psize - 1) {
			free(pi);
			return i-k;
		}
	}
	free(pi);
	return -1;
}

int main(void)
{
    int M, T, i, j, flag;
    while(1)
    {
    scanf("%d %d", &M, &T);
    if(M==0 && T==0)return 0;
    
    for(i=0;i<M;i++)
    {
    scanf("%s", &tecla);
    if(tecla[0] == 'A' && (tecla[1]!='#' && tecla[1]!='b'))musica[i]=10;
    if((tecla[0] == 'A' && tecla[1]=='#') || (tecla[0]=='B' && tecla[1]=='b'))musica[i]=11;
    if((tecla[0] == 'B' && (tecla[1]!='#' && tecla[1]!='b')) || (tecla[0]=='C' && tecla[1]=='b'))musica[i]=12;
    if((tecla[0] == 'C' && (tecla[1]!='#' && tecla[1]!='b')) || (tecla[0] == 'B' && tecla[1]=='#'))musica[i]=1;
    if((tecla[0] == 'C' && tecla[1]=='#') || (tecla[0]=='D' && tecla[1]=='b'))musica[i]=2;
    if(tecla[0] == 'D' && (tecla[1]!='#' && tecla[1]!='b'))musica[i]=3;
    if((tecla[0] == 'D' && tecla[1]=='#') || (tecla[0]=='E' && tecla[1]=='b'))musica[i]=4;
    if((tecla[0] == 'E' && (tecla[1]!='#' && tecla[1]!='b')) || (tecla[0]=='F' && tecla[1]=='b'))musica[i]=5;
    if((tecla[0] == 'F' && (tecla[1]!='#' && tecla[1]!='b')) || (tecla[0] == 'E' && tecla[1]=='#'))musica[i]=6;
    if((tecla[0] == 'F' && tecla[1]=='#') || (tecla[0]=='G' && tecla[1]=='b'))musica[i]=7;
    if(tecla[0] == 'G' && (tecla[1]!='#' && tecla[1]!='b'))musica[i]=8;
    if((tecla[0] == 'G' && tecla[1]=='#') || (tecla[0]=='A' && tecla[1]=='b'))musica[i]=9;
    memset(tecla, '\0', sizeof(tecla));
    }
    
     for(i=0;i<(M-1);i++)
    {
    if(abs(musica[i]-musica[i+1])>6)dif[i]=12-abs(musica[i]-musica[i+1]);
    else dif[i]=abs(musica[i]-musica[i+1]);
    }
    
    memset(musica, 0, sizeof(musica));
    
    for(i=0;i<T;i++)
    {
    scanf("%s", &tecla);
    if(tecla[0] == 'A' && (tecla[1]!='#' && tecla[1]!='b'))musica[i]=10;
    if((tecla[0] == 'A' && tecla[1]=='#') || (tecla[0]=='B' && tecla[1]=='b'))musica[i]=11;
    if((tecla[0] == 'B' && (tecla[1]!='#' && tecla[1]!='b')) || (tecla[0]=='C' && tecla[1]=='b'))musica[i]=12;
    if((tecla[0] == 'C' && (tecla[1]!='#' && tecla[1]!='b')) || (tecla[0] == 'B' && tecla[1]=='#'))musica[i]=1;
    if((tecla[0] == 'C' && tecla[1]=='#') || (tecla[0]=='D' && tecla[1]=='b'))musica[i]=2;
    if(tecla[0] == 'D' && (tecla[1]!='#' && tecla[1]!='b'))musica[i]=3;
    if((tecla[0] == 'D' && tecla[1]=='#') || (tecla[0]=='E' && tecla[1]=='b'))musica[i]=4;
    if((tecla[0] == 'E' && (tecla[1]!='#' && tecla[1]!='b')) || (tecla[0]=='F' && tecla[1]=='b'))musica[i]=5;
    if((tecla[0] == 'F' && (tecla[1]!='#' && tecla[1]!='b')) || (tecla[0] == 'E' && tecla[1]=='#'))musica[i]=6;
    if((tecla[0] == 'F' && tecla[1]=='#') || (tecla[0]=='G' && tecla[1]=='b'))musica[i]=7;
    if(tecla[0] == 'G' && (tecla[1]!='#' && tecla[1]!='b'))musica[i]=8;
    if((tecla[0] == 'G' && tecla[1]=='#') || (tecla[0]=='A' && tecla[1]=='b'))musica[i]=9;
    memset(tecla, '\0', sizeof(tecla));
    }
    
    for(i=0;i<(T-1);i++)
    {
    if(abs(musica[i]-musica[i+1])>6)dif2[i]=12-abs(musica[i]-musica[i+1]);
    else dif2[i]=abs(musica[i]-musica[i+1]);
    }
    
    flag = kmp(dif, (M-1), dif2, (T-1));
    if(flag>=0)printf("S\n");
    else printf("N\n");
    }
    return 0;
}


