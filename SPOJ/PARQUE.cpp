#include <stdio.h>
#include <string.h>
#include <algorithm>

char X[200];
char Y[200];
char comum[200];
char resposta[400];
int c[300][300],k=0;
int num = 1;

using namespace std;

void lcs(int i,int j){
  if(i!=0 && j!=0){
      if(X[i-1]==Y[j-1]){
        lcs(i-1,j-1);
        comum[k]=X[i-1];
	k++;
      }else if(c[i-1][j] > c[i][j-1]){
        lcs(i-1,j);
      }else{
        lcs(i,j-1);
      }
  }
}

int main(void)
{
	while(1)
	{
		int n,m;
		int i,j,l;
		 
		memset(X,'\0',sizeof(X));
		memset(Y,'\0',sizeof(Y));
		memset(c,0,sizeof(c));
		memset(resposta,'\0',sizeof(resposta));
		memset(comum,'\0',sizeof(comum));		
		scanf("%s",X);
		if(X[0]=='#')break;
		scanf("%s",Y);
		 
		n = strlen(X);
		m = strlen(Y);
		 
		for(i=0;i<=n;i++)
		  c[i][0] = 0;
		 
		for(j=0;j<=m;j++)
		  c[0][j] = 0;
		 
		 
		for(i=1;i<=n;i++)
		  for(j=1;j<=m;j++)
		    if(X[i-1]==Y[j-1])
		      c[i][j] = c[i-1][j-1] + 1;
		    else
		      c[i][j] = max( c[i-1][j] , c[i][j-1]);
		 
		lcs(n,m);
	
		for(i=0,j=0;i<n;i++)
		{
			if(comum[j]==X[i]){X[i]='1';j++;}
		}
	
		for(i=0,j=0;i<m;i++)
		{
			if(comum[j]==Y[i]){Y[i]='1';j++;}
		}
		
		i=0,l=0,k=0,j=0;
		while(1)
		{
			if(X[i] == '1' && Y[j] == '1')
			{
				resposta[k] = comum[l];
				l++;i++;j++;k++;  
			}
			else
			{
				if(X[i]=='1')
				{
					resposta[k] = Y[j];
					j++;k++;
				}
				else
				{
					if(Y[j]=='1')
					{
						resposta[k] = X[i];
						i++;k++;
					}
					else
					{
						resposta[k] = Y[j];
						j++;k++;
					}
				}
			}
			if(i==n)
			{
				while(j<m)
				{
					if(Y[j]!='1')
					resposta[k] = Y[j];
					j++;k++;
				}
				break;
			}
			else
			{
				if(j==m)
				{
					while(i<n)
					{
						if(X[i]!='1')
						resposta[k] = X[i];
						i++;k++;
					}
					break;
				}
			}
		}
		printf("Teste %d\n", num);
		printf("%s\n", resposta);
		printf("\n");		
		num++;
		k=0;	
	}
	return 0;
}