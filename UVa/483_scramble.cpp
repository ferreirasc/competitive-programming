#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sstream>

using namespace std;

int main(void)
{
	string s; 
	char letra;
	while(scanf("%c", &letra)!=EOF)
	{
		if(letra!=' ' && letra!=10)s = s + letra;
		else
		{
				if(letra == ' ')
				{
					s = string(s.rbegin(),s.rend());
					s = s + " ";
					cout << s;
					s.clear();
				}
				else
				{
					if(letra == 10)
					{
						s = string(s.rbegin(),s.rend());
						s = s + "\n";
						cout << s;
						s.clear();
					}
				}
		}		
	}
	return 0;
}
