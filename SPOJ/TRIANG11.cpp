#include <stdio.h>
#include <math.h>


int main ()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a == b && b == c)
	{
		printf("a\n");
	}
	else
	{
		if(a> b && a > c)
		{
			if(a >= b + c)
			{
				printf("n\n");
			}
			else
			{
				if( a*a > b*b + c*c)
				{
					printf("o\n");
				}
				else
				{
					if( a*a < b*b + c*c)
					{
						printf("a\n");
					}
					else
					{
						printf("r\n");			
					}
				}
			}
		}
		else 
		{
			if(b > a && b > c)
			{
				if( b >= a + c)
				{
					printf("n\n");
				}
				else
				{
					if( b*b > a*a + c*c)
					{
						printf("o\n");
					}
					else
					{
						if( b*b < a*a + c*c)
						{
							printf("a\n");
						}
						else
						{
							printf("r\n");				
						}
					}
				}
			}
			else 
			{
				if(c >= a + b)
				{
					printf("n\n");
				}
				else
				{
					if( c*c > b*b + a*a)
					{
						printf("o\n");
					}
					else 
					{
						if( c*c < b*b + a*a)
						{
							printf("a\n");
						}
						else
						{
							printf("r\n");			
						}
					}
				}
			}
		}
	}
	return 0;
}