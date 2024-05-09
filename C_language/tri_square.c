#include<math.h>
#include<stdio.h>
double a, b, c;
double square, s;

main()
{
    printf("input the length of three edge:\n");
    scanf("a=%lf,b=%lf,c=%lf", &a, &b, &c);
    s = (a+b+c)/2.0;
    square = sqrt(s*(s-a)*(s-b)*(s-c));
    printf("square is:%lf\n", square);
}

//非运算
//算数运算
//关系运算
//&& ||
//赋值运算
    