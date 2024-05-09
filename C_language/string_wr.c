#include<stdio.h>
#include<stdlib.h>

// int main()
// {
//     char str[20];
//     FILE *fp;
//     if(!(fp = fopen("fwo.txt", "rt")))
//     {
//         printf("\nerror in opnening file fwo.txt");
//         getchar();
//         exit(1);
//     }
//     fgets(str, 20, fp);// 20表示读出的字符串的字节宽度（包含末尾的'\0'），fgets()函数在读出所规定的字节数之前，若遇见换行符或EOF，则读出结束；函数的返回值为字符数组的首地址
//     printf("%s", str);
// }

int main()
{
    FILE *fp;
    char ch, st[20];
    if(!(fp = fopen("fwo.txt", "at")))
    {
        printf("error in opening file fwo.txt...\n");
        getchar();
        exit(1);
    }
    printf("please input string:\n");
    scanf("%s", st);
    fputs(st, fp);
    rewind(fp);
    ch  = fgetc(fp);
    while(ch != EOF)
    {
        putchar(ch);
        ch = fgetc(fp);
    }
    fclose(fp);
    return 0;
}
