#include <cstdio>

void eval(int *j, int N) {
    long int tmp = 0;
    if (N == 1) {
        printf("%s\n\n", (j[0] == 0) ? "0" : "nao achei");
        return;
    }
    if (j[0] >= -30 && j[0] <= 30)
        tmp += j[0];
    for (int i = 1; i < N; ++i) {
        if (j[i] >= -30 && j[i] <= 30) {
            if (tmp == j[i]) {
                printf("%ld\n\n", tmp);
                return;
            }
                tmp += j[i];
        }
    }
    printf("nao achei\n\n");
}


int main(int argc, char *argv[]) {
    int N, i=0;
    while (scanf("%d", &N) == 1) {
        int j[N];
        for (int k = 0; k < N; ++k){
            scanf("%d", &j[k]);
        }
        printf("Instancia %d\n", ++i);
        eval(j, N);
    }
    return 0;
}