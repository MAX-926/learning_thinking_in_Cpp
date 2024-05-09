#include<stdio.h>
#include"../MyTool.h"
void print(int [], int);

main()
{
    int array[] = {1, 2, 3};
    print(array, GETSIZE(array));
}

void print(int a[], int len)// 指针变量可以有下标形式， 下标变量也可以有指针形式
{
    int i;
    for(i = 0; i < len; i++)
    {
        printf("a[%d] = %d\n", i, *(a+i));
    }
    return;
}