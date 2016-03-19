#include <stdio.h>
#include <string.h>

using namespace std;

char word[30];
int cont = 0;

bool isprime(int n)
{
	if(n<=1)
		return true;
	for(int i=2;i*i<=n;i++)
		if(n % i == 0)return false;
	return true;
}

int main(void)
{
	while(scanf("%s", word)!=EOF)
	{
		for(int i=0;i<strlen(word);i++)
		{
			if(word[i]>='A' && word[i]<='Z')
				cont = cont + (word[i] - 65 + 27);
			else if(word[i]>='a' && word[i]<='z')
				cont = cont + (word[i] - 97 + 1);
		}
		
		if(isprime(cont))printf("It is a prime word.\n");
		else printf("It is not a prime word.\n");
		cont = 0;
		memset(word,'\0',sizeof(word));
	}
	return 0;
}