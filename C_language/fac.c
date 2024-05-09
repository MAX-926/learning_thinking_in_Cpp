// #include<stdio.h>

// int fac(int n);

// main()
// {
//     printf("%d", fac(5));
// }

// int fac(int n)
// {
//     if(n == 1) return 1;
//     return n*fac(n-1);
// }

#include<stdio.h>
int fac(int n);

main()
{
    int i;
    for(i = 1; i <= 5; i++)
    {
        printf("%d!=%d\n", i, fac(i));
    }
}

int fac(int n)
{
    static int f = 1;// 使用了累计值，要从main的角度看程序的运行结果
    f = f*n;
    return (f);
}