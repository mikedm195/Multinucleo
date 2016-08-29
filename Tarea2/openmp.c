#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 50000000

int main(int argc, const char * argv[]) {

    int i;
    int suma = 0;
    double total, operaciones, fin;

    total = omp_get_wtime();

    int* a;
    int* b;

    a = (int*)malloc(N*sizeof(int));
    b = (int*)malloc(N*sizeof(int));

    i = 0;
    #pragma omp parallel private(i)
    {
        #pragma omp for
        for(i = 0;i<N;i++){
            a[i] = i;
            b[i] = i*2;
        }
    }

    operaciones = omp_get_wtime();

    i = 0;
    #pragma omp parallel private(i) reduction(+:suma)
    {
        #pragma omp for
        for (i = 0; i < N; i++) {
            a[i] = a[i] + b[i];
        }
    }

    fin = omp_get_wtime();

    printf("Tiempo total = %f \n", fin-total);
    printf("Tiempo operaciones = %f \n", fin-operaciones);

    free(a);
    free(b);

    return 0;
}
