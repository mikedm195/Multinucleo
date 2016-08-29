#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500000000

void suma(int* a,  int* b){
    int i = 0;
    int j = 0;
    for(;i<N;i++)
        a[i] = a[j] + b[i];
}

int main(){

    int* a;
    int* b;

    a = (int*)malloc(N*sizeof(int));
    b = (int*)malloc(N*sizeof(int));

    int i = 0;
    for(;i<N;i++){
        a[i] = i;
        b[i] = i*2;
    }

    clock_t begin = clock();

    suma(a, b);

    clock_t end = clock();
    double time_spent1 = ((double)(end - begin) / CLOCKS_PER_SEC);

    free(a);
    free(b);

    clock_t end2 = clock();
    double time_spent2 = ((double)(end2 - begin) / CLOCKS_PER_SEC);

    printf("%f\t%f\ts\n",  time_spent1, time_spent2);
    //printf("Tiempo total \t%f\n",);

    return 0;
}
