// #include<stdio.h>

// main()
// {
//     void func();
//     func();
// }

// void func()
// {
//     int i = 1;
//     while(i)
//     {
//         scanf("%d", &i);
//         if(i == 2){continue;}
//         printf("%d\n", i);
//     }
//     printf("The end\n");
// }

// #include<stdio.h>
// #include<conio.h>

// main()
// {
//     char c;
//     while(c != 13)
//     {
//         c = getch();
//         if(c == 0x1B) continue;
//         printf("%c\n", c);
//     }
// }


// #include<stdio.h>
// #include<math.h>
// #include<assert.h>

// main()
// {
//     // PI/4 = 1 - 1/3 + 1/5 - 1/7...
//     double re = 0.0;
//     int tag = 0;
//     for(int i = 1; i < 500; i+= 2)
//     {
//         if(tag == 0) {re += 1.0/i; tag = 1; printf("num: %lf was added\n", 1.0/i);continue;}
//         if(tag == 1) {re -= 1.0/i; tag = 0; printf("num: %lf was added\n", -1.0/i);}

//     }
//     printf("Result of \"1 - 1/3 + 1/5 - 1/7...\" is %lf\n", re);
//     return 0;
// }

// #include<stdio.h>
// #define Length 5
// main()
// {
//     int array[Length];// 数组长度必须是整型数据
//     return 0;
// }

// #include<stdio.h>

// main()
// {
//     int i, a[10];
//     for(i = 0; i < 10;)
//     {
//         a[i++] = i;// i++在取到数组变量后就将值增一，所以赋值从1开始，直到10；而不是0~9
//     }
//     for(i = 9; i >= 0; i--)
//     {
//         printf("%d", a[i]);
//     }
// }

// #include<stdio.h>

// main()
// {
//     为一个数组传入从0开始的连续的奇数
//     int odd[10];
//     int i;
//     for(i = 0; i < 10;)
//     {
//         odd[i] = 2*i+++1;
//     }
//     for(i = 0; i < 10; i++)
//     {
//         printf("%d\n", odd[i]);
//     }
//     return 0;
// }
