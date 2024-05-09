// #include"MyTool.h"

// main()
// {
//     int array[] = {1, -1, -5, 8, 90, 2, 46, 5, 6, 2};
//     int len = sizeof(array)/sizeof(int);
//     extern int max, min;
//     find_max_min(array, len);
//     printf("max = %d, min = %d", max, min);
// }

#include<stdio.h>
#include"MyTool.h"
main()
{
    int i, a[10];
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    print_1D_array(a, 10);
}