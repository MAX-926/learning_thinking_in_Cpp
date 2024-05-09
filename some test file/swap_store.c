#include"MyTool.h"

main()
{
    int a[10], i;
    for(i = 0; i < 10; i++)
    {
        a[i] = i;
    }
    print_1D_array(a, 10);
    swap_store_1D_array1(a, 10);
    printf("**************************\n");
    print_1D_array(a, 10);
}