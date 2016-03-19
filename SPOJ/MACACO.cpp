#include <stdio.h>
#define MAIOR(x,y) (x > y ? x : y)
#define MENOR(x,y) (x < y ? x : y)

int main()
{
        int numAreas, t = 1, i;
        int x = -10000, y = 10000, u = 10000, v = -10000;
        int _x, _y, _u, _v;
        char c;
        char buff[200];

        /*

           (x, y)       (u, y)
           *---------*
           |         |
                   |         |
                   *---------*
           (x, v)       (u, v)

        */

        for (scanf("%d", &numAreas); numAreas != 0; scanf("%d", &numAreas))
        {
                for (i = 0; i < numAreas; ++i)
                {
                        scanf("%d %d %d %d", &_x, &_y, &_u, &_v);
                       
                        // testa se não tem intersecção
                        if ((_x > u || _u < x) && (_y < v || _v > y))
                        {
                                printf("Teste %d\nnenhum\n\n", t++);
                                for (; i < numAreas; ++i)
                                        gets(buff);
                                goto fim;
                        }

                        x = MAIOR(x, _x);
                        u = MENOR(u, _u);
                        v = MAIOR(v, _v);
                        y = MENOR(y, _y);

                        // testa se o retangulo formado é incoerente
                        if ((x > u) || (y < v))
                        {
                                printf("Teste %d\nnenhum\n\n", t++);
                                for (; i < numAreas; ++i)
                                        while((c = getchar()) != '\n');
                                goto fim;
                        }

                }
                printf("Teste %d\n%d %d %d %d\n\n", t++, x, y, u, v);
                fim:
                x = -10000;
                y = 10000;
                u = 10000;
                v = -10000;
        }
        return 0;
}
