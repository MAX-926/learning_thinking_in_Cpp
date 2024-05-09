// 2x^2 + 4x +2
#include<stdio.h>
#include<math.h>
typedef struct Result
{
    double x1;
    double x2;
} Groots;

Groots* equation_slover(double a, double b, double c, Groots* re)// ax^2 + bx + c
{
    double delta = pow(b ,2) - 4.0*a*c;
    if(delta < 0)
    {
        printf("equation has no groot\n");
        return 0;
    }
    else
    {
        re->x1 = (-b + sqrt(delta))/(2*a);
        re->x2 = (-b - sqrt(delta))/(2*a);
        return re;
    }
}

main()
{
    Groots g;
    double a, b, c;
    printf("please input a, b, c:\n");
    scanf("a=%lf,b=%lf,c=%lf", &a, &b, &c);
    if(equation_slover(a, b, c, &g)) 
    printf("Result of this equation(%lfx^2+%lfx+%lf=0) is:\nx1 = %lf\nx2 = %lf\n",a, b, c, g.x1, g.x2 );
    return 0;
}