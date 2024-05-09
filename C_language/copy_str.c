#include<stdio.h>

void cpystr(char *pss, char *pds);

main()
{
    // char *pss, *pds, st[20];
    // // scanf("%s", pss);
    // pss = st;
    // scanf("%s", st);// 不能直接往指针变量写字符串，需要先将字符指针变量绑定字符数组才可以用scanf("%s", st)写
    // cpystr(pss, pds);
    // printf("%s", pds);

    static char st[] = {"C Language"};
    printf("%s", st);
}

void cpystr(char *pss, char *pds)
{
    while((*pds++ = *pss++));
}

// void cpystr(char *pss, char *pds)
// {
//     int i = 0;
//     while(pss[i] != '\0')
//     {
//         pds[i] = pss[i];
//         i++;
//     }
// }