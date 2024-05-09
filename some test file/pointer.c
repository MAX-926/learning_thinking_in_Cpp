// // #include<stdio.h>

// // main()
// // {
// //     // int *p = 1000;// 编译器报告无法从类型int转换到类型int*
// //     // int a, b = &a;// 编译器报告不能从类型int*转换到类型int
// // }
// // #include<stdio.h>
// // main()
// // {
// //     // int a = 10;
// //     // printf("%d", *&a);
// //     const char* c;
// //     c = "C Language";
// //     printf("%s", c);
// // }
// // #include<stdio.h>
// // typedef int* intp;
// // main()
// // {
// //     int a = 1, b = 2;
// //     intp pa, pb;
// //     pa = &a;
// //     pb = &b;
// //     printf("%d %d", *pa, *pb);
// // }

// #include<stdio.h>

// // main()
// // {
// //     int a[10], i;
// //     for(i = 0; i < 10; i++)
// //         a[i] = i;
// //     for(i = 0; i < 5; i++)
// //         printf("a[%d] = %d\n", i, a[i]);
// // }

// // main()
// // {
// //     int a[10], i;
// //     for(i = 0; i < 10; i++)
// //         *(a+i) = i;
// //     for(i = 0; i < 10; i++)
// //         printf("a[%d] = %d\n", i, *(a+i));
// // }

// // main()
// // {
// //     int a[10], i, *p;
// //     p = a;
// //     for(i = 0; i < 10; i++)
// //         p[i] = i;
// //     for(i = 0; i < 10; i++)
// //         printf("a[%d] = %d\n", i, *(p+i));
// // }

// // main()
// // {
// //     int a[10], I, *p = a;
// //     for(I = 0; I < 10;)
// //     {
// //         *p = I;
// //         printf("a[%d] = %d\n", I++, *p++);
// //     }
// // }

// //数组倒序存储
// main()
// {
//     int a[10], i;
//     for(i = 0; i < 10; i++)
//     {
//         a[i] = i;
//     }
//     // Swap
//     void swap(int*, int);
//     swap(a, 10);
//     for(i = 0; i < 10; i++)
//         printf("a[%d] = %d\n", i, a[i]);
// }

// void swap(int *a, int len)
// {
//     int i, j = len - 1, tmp;
//     for(i = 0; i < (int)i/2; i++, j--)
//     {
//         tmp = a[i];
//         a[i] = a[j];
//         a[j] = tmp;
//     }
// }

// 使用指针数组表示二维数组
// #include<stdio.h>

// main()
// {
//     int a1[2] = {1, 2}, a2[2] = {3, 4}, a3[2] = {5, 6};
//     int* ap[3] = {a1, a2, a3};
//     int i, j;
//     for(i = 0; i < 3; i++)
//         for(j = 0; j < 2; j++)
//             printf("ap[%d][%d] = %d\n", i, j, ap[i][j]);
// }

// 二维数组的指针
// #include<stdio.h>

// main()
// {
//     int a[2][1] = {1, 2};
//     int (*p)[1];
//     p = a;
//     int i, j;
//     for(i = 0; i < 2; i++)
//         for(j = 0; j < 1; j++)
//             printf("a[%d][%d] = %d\n", i, j, p[i][j]);
// }

// #include<stdio.h>

// main()
// {
//     const char* p[3] = {"MAX", "max"};
//     // char* p_unc[3] = {"MAX", "max"};
// }