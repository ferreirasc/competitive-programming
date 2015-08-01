#include <stdio.h>
#include <stack>
#include <string>
#include <ctype.h>
#include <string.h>

using namespace std;

string answer;
stack<char> eq;

int priority(char c)
{
	switch(c)
	{
		case '+':
			return 0;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
		case '^':
			return 4;
	}
	return -1;
}

int main(void)
{
	int casos;
	scanf("%d", &casos);
	while(casos--)
	{
		char exp[500];
		scanf("%s", exp);
		for(int i=0;i<strlen(exp);i++)
		{
			if(isalpha(exp[i]))
			{
				answer+=exp[i];
			}
			else
			{
				if(eq.empty())
				{
					eq.push(exp[i]);
				}
				else
				{
					if(exp[i] == ')')
					{
						while(!eq.empty() && eq.top() != '(')
						{
							answer+=eq.top();
							eq.pop();
						}
						eq.pop();
					}
					else
					{
						if(priority(exp[i])!=-1)
						{
							while(!eq.empty() && priority(eq.top())!=-1 && priority(eq.top())>=priority(exp[i]))
							{
								answer+=eq.top();
								eq.pop();
							}
						}
						eq.push(exp[i]);
					}
				}
			}
		}
		while(!eq.empty())
		{
			answer+=eq.top();
			eq.pop();
		}

		printf("%s\n", answer.c_str());
		answer.clear();
	}
	return 0;
}
