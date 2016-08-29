#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 500000000

int main(int argc, const char * argv[]) {

    int i;
    int suma = 0;
    double inicio, operaciones, total;


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

    inicio = omp_get_wtime();

    i = 0;
    #pragma omp parallel private(i) reduction(+:suma)
    {
        #pragma omp for
        for (i = 0; i < N; i++) {
            a[i] = a[i] + b[i];
        }
    }

    operaciones = omp_get_wtime();

    free(a);
    free(b);

    total = omp_get_wtime();

    printf("%f\t%f\ts\n", operaciones-inicio, total-inicio);
    //printf("Tiempo operaciones = %f \n", fin-operaciones);
    return 0;
}
