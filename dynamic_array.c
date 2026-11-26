// Dynamic Array Allocation: heap memory allocation and initialization for N doubles

#include <stdio.h>
#include <stdlib.h>

double* create_array(int N, double L)
{
    double *arr;

    arr = (double*) malloc(N * sizeof(double));

    if(arr == NULL)
        return NULL;

    for(int i = 0; i < N; i++)
        arr[i] = L;

    return arr;
}

int main(void)
{
    int N;
    printf("give N: ");
    scanf("%d", &N);

    if(N <= 0)
    {
        printf("Invalid size. N must be greater than 0.\n");
        return 1;
    }

    double L;
    printf("give L: ");
    scanf("%lf", &L);

    double *A;
    A = create_array(N, L);

    if(A == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for(int i = 0; i < N; i++)
        printf("A[%d] = %.2lf\n", i, A[i]);

    free(A);

    return 0;
}
