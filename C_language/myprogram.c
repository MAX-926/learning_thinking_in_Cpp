// #include<stdio.h>
// #include<math.h>

// main()
// {
//     double x, s;
//     printf("input number\n");
//     scanf("%lf", &x);
//     s = sin(x);
//     printf("Sine of %lf is %lf", x, s);
// }

// #include<stdio.h>

// int max(int a, int b);
// main()
// {
//     int x, y, z;//變量聲明
//     int max(int a, int b);//函數聲明
//     printf("input two numbers:\n");
//     scanf("%d %d", &x, &y);
//     z = max(x, y);
//     printf("maxmum=%d", z);
// }
// int max(int a, int b)
// {
//     return a > b?a:b;
// }

// #include<stdio.h>

// main()
// {
//     double result = 0;
//     int i;
//     for(i = 1; i <= 100; i++)
//     {
//         if(i % 2 != 0)
//             result = result + 1.0/i;
//         else result = result - 1.0/i;
//     }
//     printf("result is %lf", result);
// }

// #include<stdio.h>
// #include<math.h>

// main()
// {
    // float a = 33333.33333;
    // double b = 33333.33333333333333
    // int x = 2147483648;
    // printf("%d", x);
    // printf("%f\n%f",a, b);
// }

// #include<stdio.h>

// main()
// {
//     // printf("MAX\nMAX\b\bAX\b\b\b");//\b 在該行倒退一格,退滿行所在内容數，則刪除行
//     // printf("M\nMAX\rb");//\r重定位到該行開頭
//     // printf("a\fb");//換頁， 類似換行
//     // printf("\a");
//     int a, b, c;
//         a = 5, b = 6, c = 7;
//         printf("  ab  c\tde\rf\n");//f ab  c de
//         printf("hijk\tL\bM\n");    //hijk M
//                                    //
// }

// #include<stdio.h>

// main()
// {
//     float PI = 3.1415926;
//     int s, r = 5;
//     s = r * r * PI;
//     printf("s = %d", s); 
// }

// #include<stdio.h>

// main()
// {
//     float f = 5.75;
//     printf("(int)f = %d, f = %f\n", (int)f, f);
// }

// #include<stdio.h>

// main()
// {
//     // printf("\n\n%d,%d\n", 20/7, -20/7);
//     // printf("%f,%f\n", 20.0/7, -20.0/7);
//     // printf("%d", 100 % 3);
// }

// #include<stdio.h>

// main()
// {
//     int i = 8;
//     printf("%d", ++i);// i == 9
//     printf("%d\n", --i);// i == 8
//     printf("%d\n", i++);// i == 9,输出8
//     printf("%d\n", i--);// i == 8, 输出9
//     printf("%d\n", -i++); // i == 9, 输出-8
//     printf("%d\n", -i--); // i == 8, 输出-9
// }

// #include<stdio.h>
// #include<assert.h>
// main()
// {
    // int i = 5, j = 5, p, q;
    // p = (i++) + (i++) + (i++);// re = 18, i = 8 5+6+7
    // q = (++j) + (++j) + (++j) + (++j);// 7 + 7 + 8???
    // re = 21, j = 8 6+7+8
    // printf("%d, %d, %d, %d", p, q, i, j);// 13, 21, 8, 8
    // printf("%d", q);
// }

// #include<stdio.h>

// main()
// {
//     int a, b = 322;
//     float x, y = 8.88;
//     char c1 = 'k', c2;
//     a = y;// a = 8
//     x = b;// 322.
//     a = c1;// a = 107
//     c2 = b;// 322的低8位存入从c2
//     printf("%d, %f, %d, %c", a, x, a, c2);
// }

// #include<stdio.h>
// #include<assert.h>
// main()
// {
//     int a = 2, b = 4, c = 6, x, y;
//     y = (x = a + b), (b + c);
//     // y = a,b;
//     // assert(y == 10);
//     printf("y = %d, x = %d", y, x);// y = 10, x = 6
// }

// #include<stdio.h>

// main()
// {
//     int a = 1, b = 2, y;
//     // y = a, b;// 逗号优先级最低
//     printf("%d", y);
// }

// #include<stdio.h>

// main()
// {
//     // putchar(getchar());
//     printf("%c", getchar());
// }

// #include<stdio.h>

// main()
// {
//     int index = 0;
//     while(index++ < 10)
//     {
//         int sam;
//         sam = 10 * index + 2;
//         printf("sam = %d\n", sam);
//     }
// }
//

// #include<stdio.h>

// main()
// {
//     size_t intsize;
//     intsize = sizeof(int);
//     printf("%zd", intsize);
// }

// #include<stdio.h>
// main()
// {
//     char a = 'c';
//     // printf("%zd", sizeof(float));
//     printf("%2c", a);
// }

// #include<stdio.h>
// main()
// {
//     int i = 1;
//     printf("%d %d", ++i, ++i);// printf语句是一个序列点，C只保证在序列点结束之前完成对i的自增操作，并没有规定一个操作顺序
// }