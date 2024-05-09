#include<stdio.h>
int s(int);//但声明时必须说明返回值类型

main()
{
    int n;
    printf("please input a num:\n");
    scanf("%d", &n);
    s(n);
    printf("n = %d", n);
}

s(int n)// 若函数的返回值为整型，则定义时可以省略说明
{
    int i;
    for(i = n-1; i >= 1; i--)
    {
        n = n + i;
    }
    printf("%d\n", n);
}