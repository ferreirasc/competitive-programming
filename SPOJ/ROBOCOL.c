#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char mapa[101][101];
int cont = 0;

int main(void)
{
int n, m, i, j, controle, x, y;
char char2, orienta;

for(;;)
{
scanf("%d %d %d", &n, &m, &controle);
if(n==0 && m==0 && controle==0)return 0;

for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
scanf("\n%c", &char2);
if(char2=='.')mapa[i][j]=char2;
if(char2=='*')mapa[i][j]=char2;
if(char2=='#')mapa[i][j]=char2;
if(char2=='N' || char2=='S' || char2=='L' || char2=='O')
{
mapa[i][j]='.';
orienta = char2;
x = i;
y = j;
}
}
}


getchar();

for(i=0;i<controle;i++)
{
scanf("\n%c", &char2);
if(char2=='D')
{
if(orienta=='N')orienta = 'L';
else
if(orienta=='L')orienta = 'S';
else	
if(orienta=='S')orienta = 'O';
else	
if(orienta=='O')orienta = 'N';
}

if(char2=='E')
{
if(orienta=='N')orienta = 'O';
else
if(orienta=='L')orienta = 'N';
else
if(orienta=='S')orienta = 'L';
else
if(orienta=='O')orienta = 'S';
}
if(char2=='F')
{
if(orienta=='N')
{
if((x-1)>=0)
{
if(mapa[x-1][y]!='#')
{
if(mapa[x-1][y]=='*')
{
cont++;
mapa[x-1][y]='.';
x = x-1;
}
else
{
x = x-1;
}
}
}
}

if(orienta=='S')
{
if((x+1)<=(n-1))
{
if(mapa[x+1][y]!='#')
{
if(mapa[x+1][y]=='*')
{
cont++;
mapa[x+1][y]='.';
x = x+1;
}
else
{
x = x+1;
}
}
}
}

if(orienta=='O')
{
if((y-1)>=0)
{
if(mapa[x][y-1]!='#')
{
if(mapa[x][y-1]=='*')
{
cont++;
mapa[x][y-1]='.';
y = y-1;
}
else
{
y = y-1;
}
}
}
}

if(orienta=='L')
{
if((y+1)<=(m-1))
{
if(mapa[x][y+1]!='#')
{
if(mapa[x][y+1]=='*')
{
cont++;
mapa[x][y+1]='.';
y = y+1;
}
else
{
y = y+1;
}
}
}
}	
}	

}

printf("%d\n", cont);
cont = 0;
memset(mapa, '\0', sizeof(mapa)); 
}	
return 0;
}
