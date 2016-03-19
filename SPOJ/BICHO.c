#include <stdio.h>

int main(void)
{
    int i, m, n, acc=0, mixm, mixn, j;
    double v;
    
        for(;;)
        {
            scanf("%lf %d %d", &v, &m, &n);
            if(v==0 && m==0 && n==0)return 0;
            if(v<(0.01) || v>(1000.00) || n<0 || n>1000000 || m<0 || m>1000000)return 0;
                if(m%10000 == n%10000)
                {
                    acc=3000;
                }
                
                if((m%1000 == n%1000) && acc==0)
                {
                    acc=500;
                }
                
                if((m%100 == n%100) && acc==0)
                {
                    acc=50;
                }
                
                if(acc==0)
                {
                    if(m<100)mixm=m;
                    if(n<100)mixn=n;
                    
                    if(m%100 == 0 || m==0)
                    {
                             mixm=100;
                    }
                    
                    if(n%100 == 0 || n==0)
                    {
                        mixn=100;
                    }
                    
                    if(m%100!=0 && m>100)mixm=m%100;
                    if(n%100!=0 && n>100)mixn=n%100;
                    
                    if((mixm < mixn) && acc==0)
                    {
                        for(j=1;j<=4;j++)
                        {
                            if((mixm)%4!=0)
                            {
                                if(((mixm)+j)==mixn)
                                {
                                acc=16;
                                break;
                                }
                            }
                            else{
                                 break;
                                 }
                                 mixm=mixm+j;
                        }
                    }
                    
                    if((mixm > mixn) && acc==0)
                    {
                        for(j=1;j<=4;j++)
                        {
                            if((mixn)%4!=0)
                            {
                                if(((mixn)+j)==mixm)
                                {
                                acc=16;
                                break;
                                }
                            }
                            else{
                                 break;
                                 }
                            mixn = mixn+j;
                        }
                    }
                
                }
                
                
                printf("%.02lf\n", (v*acc));
                acc=0;
        
        }
        return 0;
}
