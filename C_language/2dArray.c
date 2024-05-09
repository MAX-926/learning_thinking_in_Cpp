#include<stdio.h>
#include<string.h>

main()
{
    // int a[2][2] = {{1, 1}, {0, 0}};
    // int i, j;
    // for(i = 0; i < 2; i++)
    // {
    //     for(j = 0; j < 2; j++)
    //     {
    //         printf("%d ", a[i][j]);
    //         if(j == 1)
    //             printf("\n");
    //     }
    // }

    // char c[] = "MAX";
    // printf("%s", c);// 使用printf函数输出字符串时，传入字符数组名 

    //字符数组的输入与输出
    // char st[15];
    // scanf("%s", st);// 使用scanf函数输入字符串时不能传入空格，不然空格会作为字符串的结尾
    // printf("%s", st);

    // char st1[6], st2[6], st3[6];
    // scanf("%s%s%s", st1, st2, st3);
    // printf("%s %s %s", st1, st2, st3);

    // char st[15];
    // gets(st);// 可以输入空格，不会将空格作为字符串终结符。
    // puts(st);

    // char st1[10] = "maxmax", st2[5] = "MAX";
    // strcat(st1, st2);// 将st1与st2进行连接，并取消st1的终结符，连接在st1中发生
    // puts(st1);

    // char st1[15], st2[4] = "MAX";
    // strcpy(st1, st2); // 将st2的内容拷贝到数组st1里
    // puts(st1);

    // char st1[] = "MAX", st2[] = "max", st3[] = "MAx";
    // printf("%d", strcmp(st3, st1));// strcmp函数将st1与st2逐字符进行比较(以ascii的值为基准)，若st1>st2，则函数返回1；若st1 = st2,则函数返回 0， 若st1 < st2，则函数返回-1

    // int k;
    // static char st1[15], st2[] = "C Language";
    // printf("input a string:\n");
    // gets(st1);
    // k = strcmp(st1, st2);
    // if(k == 0){printf("st1 == st2\n");}
    // if(k > 0){printf("st1 > st2\n");}
    // if(k < 0){printf("st1 < st2\n");}

    // int k;
    // static char st1[15] = "C language";
    // printf("%d", k = strlen(st1));

    
}