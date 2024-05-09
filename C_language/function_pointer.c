#include<stdio.h>
int max(int, int);

main()
{
    int a, b;
    int (*fp)(int, int);
    fp = max;
    scanf("%d%d", &a, &b);
    printf("%d", (*fp)(a, b));
}

int max(int a, int b){return a>b? a:b;}