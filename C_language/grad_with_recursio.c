#include<stdio.h>
long int grad(long int);
main()
{
    int i;
    printf("input a Integer:\n");
    scanf("%d", &i);
    printf("grad(i) = %ld", grad(i));
}
// 寻找可重复计算的项！！！这里是n*(n-1)
// 画出执行流程！！！
//4*grad(3)
//  3*grad(2)
//    2*grad(1)  

//递归计算阶乘
long int grad(long int n)
{
    //n*(n-1)*(n-2)*(n-3)*...*3*2*1
    if(n == 1) return 1;
    return n*grad(n-1);
}