#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int indices[100000];
char data1[100000];
char data2[100000];

int main(void)
{
	int n, j=0, u=0, t=0;
	scanf("%d", &n);
	getchar();
	while(u<n)
	{
		char *k;
		map<int, string> mapa;
		getchar();
		gets(data1);
		k = strtok(data1, " ");
		while(k!=NULL)
		{
			indices[j] = atoi(k);
			k = strtok(NULL, " ");
			j++;
		}

		gets(data2);
		if(u>0)printf("\n");
		k = strtok(data2, " ");

		while(k!=NULL)
		{
			string s1 = k;
			mapa[indices[t]] = s1; 
			k = strtok(NULL, " ");
			t++;
		}

		for(int i=1;i<=t;i++)cout << mapa[i] << endl;
		u++;
		mapa.clear();
		t = 0; j = 0;
	}
	return 0;
}


