// Linear equation solver: solves ax + b = 0 using pass-by-reference

#include <stdio.h>

int solve_linear(double a, double b, double *x)
{
    if(a != 0)
    {
        *x = -b / a; // Unique solution x = -b/a
        return 0;
    }
    else if(b != 0)
    {
        return 1; // Impossible (no solution)
    }
    else
    {
        return 2; // Indeterminate (infinite solutions)
    }
}

int main(void)
{
    double a, b, root;
    int result;

    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);

    result = solve_linear(a, b, &root);

    if(result == 0)
        printf("Solution: x = %.2lf\n", root);
    else if(result == 1)
        printf("The equation is impossible (no solution).\n");
    else
        printf("The equation is indeterminate (infinite solutions).\n");

    return 0;
}
