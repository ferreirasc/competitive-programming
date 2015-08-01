#include <stdio.h>
#include <stack>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <string>

using namespace std;

stack<char> q;
string v;

int value(char simb)
{
	switch(simb)
	{
		case '-':
			return 1;
		case '+':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
	}
	return -1;
}


int main(void)
{
	int t;
	scanf("%d", &t);
	getchar();
	getchar();
	for(int i=0;i<t;i++)
	{
		char ch[5];
		while(gets(ch) && strlen(ch))
		{
			if(ch[0]<'0' || ch[0]>'9')
			{
				if(ch[0]==')')
				{
					while(!q.empty() && q.top()!='(')
					{
						v+=q.top();
						q.pop();
					}
					q.pop();
				}
				else
				{
					if(!q.empty() && value(ch[0])!=-1)
					{
						if(value(ch[0]) > value(q.top()))
						{
							q.push(ch[0]);
						}
						else
						{
							while(!q.empty() && value(q.top())!=-1 && value(ch[0]) <= value(q.top()))
							{
								v+=q.top();
								q.pop();
							}
							q.push(ch[0]);
						}
					}
					else q.push(ch[0]); 
				}
			}
			else v+=ch[0];
		}
		
		while(!q.empty())
		{
			v+=q.top();
			q.pop();
		}
		
		printf("%s\n", v.c_str());
		if(i!=(t-1))printf("\n");
		v.clear();
	}
	return 0;
}
