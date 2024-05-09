#include<stdio.h>

main()
{
    double a, b, c, max, tmp;
    printf("please input three num:\n");
    scanf("a=%lf,b=%lf,c=%lf", &a, &b, &c);
    max = a>(tmp = c>b?c:b)?a:tmp;
    printf("max is: %lf", max);
}