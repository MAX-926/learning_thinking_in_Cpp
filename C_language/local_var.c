#include<stdio.h>

main()
{
    int k = 8;
    {
        int k = 9;
        printf("inner k: %d\n", k);
    }
    printf("out k: %d\n", k);
}