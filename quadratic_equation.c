// Quadratic equation solver: solves ax^2 + bx + c = 0 using discriminant

#include <stdio.h>
#include <math.h>

int solve_quadratic(double a, double b, double c, double *x1, double *x2)
{
    double delta;
    if(a == 0)
    {
        return -1; // Not quadratic
    }

    delta = b * b - 4 * a * c;

    if(delta > 0)
    {
        *x1 = (-b + sqrt(delta)) / (2 * a);
        *x2 = (-b - sqrt(delta)) / (2 * a);
        return 0; // Two real roots
    }
    else if(delta == 0)
    {
        *x1 = -b / (2 * a);
        *x2 = *x1;
        return 1; // One double root
    }
    else
    {
        return 2; // Complex roots (no real roots)
    }
}

int main(void)
{
    double a, b, c, r1, r2;
    int result;

    printf("give a: ");
    scanf("%lf", &a);

    printf("give b: ");
    scanf("%lf", &b);

    printf("give c: ");
    scanf("%lf", &c);

    result = solve_quadratic(a, b, c, &r1, &r2);

    if(result == -1)
        printf("Not a quadratic equation.\n");
    else if(result == 0)
        printf("Two real roots: x1 = %.2lf, x2 = %.2lf\n", r1, r2);
    else if(result == 1)
        printf("One double root: x = %.2lf\n", r1);
    else
        printf("No real roots.\n");

    return 0;
}
