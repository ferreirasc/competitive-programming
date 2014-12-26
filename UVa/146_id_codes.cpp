#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main(void)
{
	char codigo[110];
	for(;;)
	{
		scanf("%s", codigo);
		if(codigo[0]=='#')return 0;
		bool op = next_permutation(codigo, codigo+strlen(codigo));
		if(op==true)printf("%s\n", codigo);
		else printf("No Successor\n");
	}
	return 0;
}
