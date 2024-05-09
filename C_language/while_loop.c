#include<stdio.h>
// 用堆积木来理解：i代表了积木的编号，sum是积木的高度，不断叠加i(即积木)，得到叠加n块积木的高度sum
main()
{
    int i = 1, sum = 0;
    while(i <= 100)
    {
        sum += i;//叠积木
        i++;// 取下一块积木
    }
    printf("%d", sum);
}