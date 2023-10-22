#include <stdio.h>
#include <stdlib.h>

#define N_MAX 200000

#define IFILENAME "data6.txt"
#define OFILENAME "out-c6.txt"

typedef
struct pair_ {
    int value;
    int index;
} pair;

int cmp(const void *a_, const void *b_) {
    const pair *a = a_;
    const pair *b = b_;
    return a->value - b->value;
}

int main() {
    int n_skulpt = 0;
    int x_ideal_ice = 0;
    long t_min = 0;
    pair b[N_MAX];

    FILE *ifo = fopen(IFILENAME, "r");

    fscanf(ifo, "%d%d%ld", &n_skulpt, &x_ideal_ice, &t_min);

    printf("%d\n", n_skulpt);

    int a = 0; 
    for(int j = 0; j < n_skulpt; j++) {
        fscanf(ifo, "%d", &a);
        b[j].value = abs(a - x_ideal_ice);
        b[j].index = j + 1;
    }

    qsort(b, n_skulpt, sizeof(pair), cmp);

    FILE *ofo = fopen(OFILENAME, "w");

    int k;
    for(k = 0; k < n_skulpt; k++) { 
        t_min -= b[k].value;
        if(t_min < 0) break;
    }
    fprintf(ofo, "%d\n", k);

    for(int i = 0; i < k; i++) {
        fprintf(ofo, "%d ", b[i].index);
    }
    
    fprintf(ofo, "\n");

    fclose(ifo);
    fclose(ofo);
}
