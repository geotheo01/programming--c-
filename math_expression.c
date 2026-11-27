// Math Expression Evaluator: evaluates an algebraic formula with powers and fractions

#include <stdio.h>
#include <math.h>

// Function that calculates the formula and stores the result in *x
// Returns 1 on success, -1 on math error (division by zero)
int calculate_formula(double a, double b, double *x)
{       
    // Check for division by zero across all denominators
    if (a + b != 0 && a != b && b != 0)
    {
        *x = (a / (a + b)) * (b / (a - b)) + (pow(a, a + b) / pow(b, a - b));
        return 1; // Success
    }
    else
    {
        return -1; // Math error (division by zero)
    }
}

int main(void)
{
    double a, b, x;
    int status;

    printf("Enter a: ");
    scanf("%lf", &a);

    printf("Enter b: ");
    scanf("%lf", &b);

    status = calculate_formula(a, b, &x);

    if (status == 1)
    {
        printf("The result is: %.4lf\n", x);
    }
    else
    {
        printf("Math Error: Division by zero is not allowed.\n");
    }

    return 0;
}
