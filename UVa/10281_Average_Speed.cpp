#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

char info[300];
double dist = 0;
int flag = 0;
double secs = 0, secs_anterior = 0; 
int h, m, s;
double velocidade_atual = 0, aux;
string time2;
string velo;

int main(void)
{
	int i;
	while(scanf("\n%[^\n]s", info)!=EOF)
	{
		for(i=0;i<strlen(info);i++)
		{
			if(info[i]!=' ')
			{
				time2 = time2 + info[i];
			}
			else break;
		}
		
		if (sscanf(time2.c_str(), "%d:%d:%d", &h, &m, &s) >= 2)
		{
  			secs = (h *3600 + m*60 + s);
		}
		
		
		
		if(info[i] == ' ')
		{
		
			for(int j=i+1;j<strlen(info);j++)velo = velo + info[j];
			dist = dist + (velocidade_atual) * (double)((secs - secs_anterior)/3600);
			if(sscanf(velo.c_str(), "%lf", &aux) >= 1)
			{
				velocidade_atual = aux;
			}
		}
		else
		{
			dist = dist + (velocidade_atual) * (double)((secs - secs_anterior)/3600);
			printf("%02d:%02d:%02d %.02lf km\n", h, m, s, dist);
		}
		
		secs_anterior = secs;
		time2.clear();
		velo.clear();
	}
	return 0;
}
