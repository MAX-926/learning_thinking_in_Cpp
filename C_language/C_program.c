// #include<stdio.h>
// main()
// {
//     int a, b, c;
//     printf("please input a b c:\n");
//     scanf("%d %d %d", &a, &b, &c);
//     printf("%d %d %d", a, b, c);
// }

// #include<stdio.h>
// main()
// {
//     int a = 26;
//     float b = 26E10;
//     scanf("%d %e", &a, &b);
//     printf("%d %e", a, b);
// }

// #include<stdio.h>
// main()
// {
    // int a, b, c;
    // printf("input: a b c\n");
    // scanf("%d %*d %d", &a, &b, &c);//输入1 2 3时，2被跳过，3将被赋给b（跳过输入流的一个值）
    // printf("%d %d %d\n", a, b, c);
    // printf("%d", '&');//1&23
    // int a, b;
    // scanf("%4d%4d", &a, &b);
    // printf("%d %d\n", a, b);
    // char a, b;
    // scanf("%c, %c", &a, &b);
    // printf("%c %c",  a, b);
    // int a;
    // scanf("%ld", &a);
    // printf("%d", a);
    // printf("\nint:%zd\nchar:%zd\nfloat:%zd\ndouble:%zd\nlong int:%zd", sizeof(int), sizeof(char), sizeof(float), sizeof(double), sizeof(long int));
// }

// #include<stdio.h>

// main()
// {
//  int i, a[10];
//  for(i = 0; i < 10; i++)
//  {
//     scanf("%d", &a[i]);
//  }
//  int max = a[0];
//  for(i = 0; i < 10; i++)
//  {
//     if(max < a[i]) max = a[i];
//  }
//  printf("max num is %d", max);
//  return 0;
// }

//冒泡排序

// #include<stdio.h>

// main()
// {
//     int a[10] = {-1, 2, 4, 6, 8, 9, 10, 38, 49, 36};
//     int i;
//     void bubble_sort(int*, int);
//     bubble_sort(a, 10);
//     for(int i = 0; i < 10; i++)
//     {
//         printf("%d\n", a[i]);
//     }
//     return 0;
// }

// // 为每一个位置找一个合适的值：
// // 第一层for用来遍历每一个位置，第二层for用来比较需要比较的值(当前位置之后的值)，得到该位置的合适值
// void bubble_sort(int *a, int length)
// {
//     int i, j;
//     for(i = 0; i < length; i++)
//     {
//         for(j = i+1; j < length; j++)
//         {
//             if(a[i] < a[j])
//             {
//                 int tmp;
//                 tmp = a[i];
//                 a[i] = a[j];
//                 a[j] = tmp;
//             }
//         }
//     }
// }

// 张(80, 75, 92), 王(61, 65, 71), 李(59, 63, 70), 赵(85， 87， 90)， 周(76, 77, 85)
