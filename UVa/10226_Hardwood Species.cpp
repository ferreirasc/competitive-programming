#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
#include <string.h>

using namespace std;

map<string, double> mapa;
map<string, double>::iterator it;
char name[40];

int main(void)
{
	int cases;
	double cont = 0;
	scanf("%d\n\n", &cases);
	for(int i=0;i<cases;i++)
	{
		while(gets(name))
		{
			if(strlen(name)==0)break;
			if(mapa.find(name) != mapa.end())
			{
				mapa[name]++;
			}
			else
			{
				mapa[name] = 1;
			}
			memset(name,'\0',sizeof(name));
			cont++;
		}

		for(it = mapa.begin();it!=mapa.end();++it)
		{
			it->second = it->second / cont * 100;
			printf("%s %.04lf\n", it->first.c_str(), it->second);
		}
		cont = 0;
		memset(name,'\0',sizeof(name));
		if(i!=(cases-1))
		{
			mapa.clear();
			printf("\n");
		}
	}
	return 0;
}
