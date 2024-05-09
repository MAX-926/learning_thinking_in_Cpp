#include<stdio.h>
#define FD "%d, %d, %d\n"

main()
{
    int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int* pa[3] = {a[0], a[1], a[2]};
    int* p = a[0];
    int i;
    for(i = 0; i < 3; i++)
    {
        printf(FD, a[i][2-i], *a[i], *(*(a+i)+i));
        // 3 1 1
        // 5 4 5
        // 7 7 9
    }
    for(i = 0; i < 3; i++)
    {
        printf(FD, *pa[i], p[i], *(p+i));
        // 1 1 1
        // 4 2 2
        // 7 3 3
    }
}