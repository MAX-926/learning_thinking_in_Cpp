#include<stdio.h>
double square(double);
long int grad(long int);

main()
{
    long int s;
    s = grad(square(2)) + grad(square(3));
    printf("s = %ld", s);
}

// calculate square
double square(double n)
{
    return n*n;
}

// calculate grad
long int grad(long int n)
{
    int i;
    for(i = n - 1; i >= 1; i--)
    {
        n *= i;
    }
    return n;
}