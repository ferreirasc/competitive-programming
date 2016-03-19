#include <stdio.h>

int main(void)
{
	int n,a,b,c,d,e, i;
	
	for(;;)
	{
	
		scanf("%d", &n);
		if(n<1 || n>255 || n==0)return(0);

		for(i=0;i<n;i++)
		{
			scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
			if(a<0 || a>255 || b<0 || b>255 || c<0 || c>255 || d<0 || d>255 || e<0 || e>255)return(0);
			if(a>127 && a<=255 && b>127 && b<=255 && c>127 && c<=255 && d>127 && d<=255 && e<=127 && e>=0)printf("E\n");
			else
			if(a>127 && a<=255 && b>127 && b<=255 && c>127 && c<=255 && d<=127 && d>=0 && e>127 && e<=255)printf("D\n");
			else
			if(a>127 && a<=255 && b<=127 && b>=0 && c>127 && c<=255 && d>127 && d<=255 && e>127 && e<=255)printf("B\n");
			else
			if(a>127 && a<=255 && b>127 && b<=255 && c<=127 && c>=0 && d>127 && d<=255 && e>127 && e<=255)printf("C\n");
			else
			if(a<=127 && a>=0 && b>127 && b<=255 && c>127 && c<=255 && d>127 && d<=255 && e>127 && e<=255)printf("A\n");
			else
			printf("*\n");
		
		}
	
	}

	return (0);
}
