#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

stack<char> abre, fecha;

int main(void)
{
	int t;
	scanf("%d", &t);
	getchar();
	for(int i=0;i<t;i++)
	{
		char string[250];
		gets(string);
		for(int j=0;j<strlen(string);j++)
		{
			if(string[j]=='(' || string[j]=='[')abre.push(string[j]);
			else if(string[j]==')' || string[j]==']')fecha.push(string[j]);
		
			if(string[j] == ')' && !abre.empty() && abre.top() == '(')
			{
				fecha.pop();
				abre.pop();
			}
			else if(string[j] == ']' && !abre.empty() && abre.top() == '[')
			{
				fecha.pop();
				abre.pop();
			}
		}
		
		if(abre.empty() && fecha.empty())printf("Yes\n");
		else printf("No\n");
		while(!abre.empty())abre.pop();
		while(!fecha.empty())fecha.pop();
	}
	return 0;
}
