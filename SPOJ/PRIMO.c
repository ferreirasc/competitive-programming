    #include <stdio.h>
    #include <math.h>
    
    int main(void)
    {
        int n;
        scanf("%d", &n);
        if(n<0)n*=-1;
    if(n<2147483648)
        {
    if(n==1 || n==0){printf("nao\n");return 0;}
	else if(n<4){printf("sim\n");return 0;}
	else if(n%2==0){printf("nao\n");return 0;}
	else if(n<9){printf("sim\n");return 0;}
	else if(n%3==0){printf("nao\n");return 0;}
	else
	{
        
		int f=5;
		while(f<=sqrt(n))
		{
			if(n%f==0){printf("nao\n");return 0;}
			if(n%(f+2)==0){printf("nao\n");return 0;}
			f=f+6;

		}
		printf("sim\n");
    
	}
	}
	return 0;
    }
