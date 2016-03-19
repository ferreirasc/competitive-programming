#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	double D, VF, VG;

	double t1 = 0, t2 = 0;

	while(scanf("%lf %lf %lf ", &D, &VF, &VG) != EOF)
	{
		t1 = 12/VF;
		t2 = sqrt(144 + D*D)/VG;
		//printf("%lf %lf", t1, t2);
	
		if(t1 >= t2)
			printf("S\n");
		else	
			printf("N\n");
	}
	
	return 0;

}