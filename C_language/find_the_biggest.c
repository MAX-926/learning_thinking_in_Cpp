#include<stdio.h>
#define d1 3
#define d2 4

main()
{
    int a[d1][d2] = {{3, 16, 87, 65}, {4, 32, 11, 108}, {10, 25, 12, 37}};
    int b[3];
    int i;
    void find_the_biggest(int (*)[d2], int*);
    find_the_biggest(a, b);
    for(i = 0; i < 3; i++)
    {
        printf("%d ", b[i]);
    }
}

void find_the_biggest(int (*a)[d2], int* b)
{
    int i, j, max;
    for(i = 0; i < d1; i++)
    {
        max = a[i][0];
        for(j = 0; j < d2; j++)
        {
            if(max < a[i][j]) max = a[i][j];
        }
        b[i] = max;
    }
}