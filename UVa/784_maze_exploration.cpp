#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

char mapa[1000][1000];

void brute(int i,int j)
{
    if(mapa[i][j]==' '||mapa[i][j]=='*')
    {
        mapa[i][j]='#';
        brute(i+1,j);
        brute(i,j+1);
        brute(i-1,j);
        brute(i,j-1);
    }
}

int main(void)
{
	int n;
	scanf("%d", &n);
	getchar();
	for(int k=0;k<n;k++)
	{
		memset(mapa,'\0',sizeof(mapa));
		int i = 0;
		int pos_x, pos_y;
		while(1)
		{
			char buffer[20000];
			gets(buffer);
			if(buffer[0]!='_')
			{
				int tam = strlen(buffer);
				for(int j=0;j<tam;j++)
				{
					if(buffer[j]=='*')
					{
						pos_x = i;
						pos_y = j; 
					}
					mapa[i][j] = buffer[j];
				}
			}
			else
			{
				brute(pos_x,pos_y);

				for(int p=0;p<i;p++)
				{
					printf("%s\n", mapa[p]);
				}
				printf("%s\n", buffer);
				break;
			}
			i++;
		}

	}
	return 0;
}
