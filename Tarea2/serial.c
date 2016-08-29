#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50000000

void suma(int* a,  int* b){
    int i = 0;
    int j = 0;
    for(;i<N;i++)
        a[i] = a[j] + b[i];
}

int main(){
    clock_t begin1 = clock();

    int* a;
    int* b;

    a = (int*)malloc(N*sizeof(int));
    b = (int*)malloc(N*sizeof(int));

    int i = 0;
    for(;i<N;i++){
        a[i] = i;
        b[i] = i*2;
    }

    clock_t begin2 = clock();

    suma(a, b);

    clock_t end = clock();
    double time_spent1 = (double)(end - begin1) / CLOCKS_PER_SEC;
    double time_spent2 = (double)(end - begin2) / CLOCKS_PER_SEC;

    printf("Tiempo total \t%f\n", time_spent1);
    printf("Tiempo operaciones \t%f\n", time_spent2);

    free(a);
    free(b);
    return 0;
}
