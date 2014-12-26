#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int i=0;i<T;i++)
	{
		char secreto[100000], bracelete1[100000];
		scanf("%s %s", secreto, bracelete1);
		string bracelete = bracelete1;
		string bracelete_reverso = string(bracelete.rbegin(), bracelete.rend());
		bracelete_reverso += bracelete_reverso;
		bracelete += bracelete1;
		if(bracelete_reverso.find(secreto)!=string::npos || bracelete.find(secreto)!=string::npos)printf("S\n");
		else printf("N\n");
	}
	return 0;
}
