#include <stdio.h>

int mov()
{
    return 1;
}


int main(void)
{
    int x1,y1,x2,y2,i=0;
    for(;;)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if(x1==0 && y1==0 && x2==0 && y2==0)return 0;
        if(x1>8 || x1<=0 || y1>8 || y1<=0 || x2>8 || x2<=0 || y2>8 || y2<=0)return 0;
        
        if(x1 == x2 && y1 == y2){
              printf("%d\n", i);
              i=1;
              }
              
        if((x1 == x2 && y2 != y1) || (x1!=x2 && y2==y1)){
               printf("%d\n", mov());
               i=1;
               }
        
        if((x1!=x2) && (y1!=y2))
        {
        i=0;
        if(x2>x1 && y2>y1)
                {
        while((x1<8 && y1<8) && (x1!=x2 && y1!=y2))
                    {
                        x1++;
                        y1++;
                        if(x1==x2 && y1==y2)
                        {
                        printf("%d\n", mov());
                        i++;
                        break;
                        }
                    }
                    }
                    
        if(x2<x1 && y2<y1)
                {
                    while((x1>1 && y1>1) && (x1!=x2 && y1!=y2))
                    {
                        x1--;
                        y1--;
                        if(x1==x2 && y1==y2)
                        {
                        printf("%d\n", mov());
                        i++;
                        break;
                        } 
                    }
                }
                
        if(x2>x1 && y2<y1)
                {
                    while((x1<8 && y1>1) && (x1!=x2 && y1!=y2))
                    {
                        x1++;
                        y1--;
                        if(x1==x2 && y1==y2)
                        {
                        printf("%d\n", mov());
                        i++;
                        break;
                        }
                         
                    }
                }
                
        if(x2<x1 && y2>y1)
                {
                    while((x1>1 && y1<8) && (x1!=x2 && y1!=y2))
                    {
                        x1--;
                        y1++;
                        
                        if(x1==x2 && y1==y2)
                        {
                        printf("%d\n", mov());
                        i++;
                        break;
                        } 
                    }
                }
                }
        
             if(i==0)printf("%d\n", mov()+1);
             
             i=0;
             
}
        return (0);
}