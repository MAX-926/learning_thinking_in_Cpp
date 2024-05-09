#include<stdio.h>
void output(int *, int);

main()
{
    int a[] = {-6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8};
    int len = sizeof(a)/sizeof(*a);
    output(a, len);
}

void output(int* a, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(a[i] > 0) printf("%d", a[i]);
    }
}