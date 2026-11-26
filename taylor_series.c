// Taylor series expansion to calculate sin(x)

#include <stdio.h>
#include <math.h>

#define Pi 3.141592653589793
#define Akr 1e-6

int main(void)
{
    int N;
    int pros, par;
    double rad;
    double cur, sum;

    do
    {
        printf("Enter angle in degrees (0...360): ");
        scanf("%d", &N);
    } 
    while (N < 0 || N > 360);

    // Convert degrees to radians
    rad = N * Pi / 180.0;
    
    cur = rad;
    sum = cur;
    par = 3;
    pros = -1;

    do
    {
        cur = cur * rad * rad / (par * (par - 1));
        sum += cur * pros;
        pros *= -1;
        par += 2;
    } 
    while (cur > Akr);

    printf("The sine of %d degrees is: %lf\n", N, sum);
    printf("math.h sin(%d) check:      %lf\n", N, sin(rad));

    return 0;
}
