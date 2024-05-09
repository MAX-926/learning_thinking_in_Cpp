// #include<stdio.h>

// int A, B;

// main()
// {
//     extern int A, B;
//     A = 13, B = 8;
//     printf("A:%d, B:%d", A, B);
// }

// // int A, B;

// #include<stdio.h>

// #define OK 100

// main()
// {
//     printf("OK");
// }

// #include<stdio.h>
// #define max(a, b) a>b?a:b // 宏明后接空格，之后的内容将被识别为宏所要替换的

// main()
// {
//     printf("%d", max(2, 4));
// }

#include<stdio.h>
#define SQ(y) y*y

main()
{
    int a, sq;
    printf("input a number:\n");
    scanf("%d", &a);
    sq = SQ(a+1); //当a=1时， sq = a+1*a+1 == 1+1+1 == 3， 而不是(a+1)*(a+1)
    // printf("%d", sq);
    printf("%d", (a+1)*(a+1));
}