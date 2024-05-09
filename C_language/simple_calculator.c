#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

main()
{
    int option = 0;
    double lv = 0.0, rv = 0.0;
    printf("\tThis is a simple calculator\n");
    printf("\twe support you to present 四则运算\n");
    while(TRUE)// !FALSE
    {
        fflush(stdin);
        printf("1:加法\t2.减法\t\n3.乘法\t4.除法\n0.退出\n");
        printf("please input your option\n");
        scanf("%d", &option);
        switch(option)
        {
            case 0: printf("计算器退出\n");fflush(stdin);break;
            case 1:
                fflush(stdin);
                printf("please input two number:\n");
                scanf("lv=%lf,rv=%lf", &lv, &rv);
                printf("Result is %lf\n", lv + rv);
                // printf("press enter to continue...\n");
                system("pause");
                // fflush(stdin);
                break;
            case 2:
                fflush(stdin);
                printf("please input two number:\n");
                scanf("lv=%lf,rv=%lf", &lv, &rv);
                printf("Result is %lf\n", lv - rv);
                // printf("press enter to continue...\n");
                system("pause");
                // fflush(stdin);
                break;
            case 3:
                fflush(stdin);
                printf("please input two number:\n");
                scanf("lv=%lf,rv=%lf", &lv, &rv);
                printf("Result is %lf\n", lv * rv);
                // printf("press enter to continue...\n");
                system("pause");
                // fflush(stdin);
                break;
            case 4:
                TAG:fflush(stdin);
                printf("please input two number:\n");
                scanf("lv=%lf,rv=%lf", &lv, &rv);
                if(rv == 0) {printf("rv can't be ZERO,please try again.\n");goto TAG;}
                printf("Result is %lf\n", lv / rv);
                // printf("press enter to continue...\n");
                system("pause");
                // fflush(stdin);
                break;
            default: 
                printf("you had entered a wrong tag,please try again.\n");
                // printf("press enter to continue...\n");
                system("pause");
        }
        if(option == 0)break;
    }
    return 0;
}