#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int K, xp, yp, i=0, x, y;
	while(scanf("%d", &K))
	{
		if(K==0)return 0;
		scanf("%d %d", &xp, &yp);
		for(i=0;i<K;i++)
		{
			scanf("%d %d", &x, &y);
			if(x==xp || y==yp)printf("divisa\n");
			else
			{
				if(y>yp && x>xp)printf("NE\n");
				else if(y<yp && x>xp)printf("SE\n");
				else if(y<yp && x<xp)printf("SO\n");
				else if(y>yp && x<xp)printf("NO\n");
			}

		}
	}
	return 0;
}