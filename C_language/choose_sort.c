#include<stdio.h>
#include"../MyTool.h"
#include<assert.h>

void choose_sort(double [], int);

main()
{
    double array[] = {0.0, -2.0, -5.0, 2.0, 6.0, 7.0, -5.0, -1.0, 33.0, 64.0};
    print_1D_array_d(array, GETSIZE(array));
    // assert(GETSIZE(array) == 10);
    choose_sort(array, GETSIZE(array));
    print_1D_array_d(array, GETSIZE(array));
}

void choose_sort(double array[], int len)
{
    int i, j;
    double tmp;
    for(i = 0; i < len; i++)
    {
        for(j = i+1; j < len; j++)
        {
            if(array[i] < array[j])
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
    return;
}