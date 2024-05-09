#include<stdio.h>
#include<stdlib.h>
main()
{
    FILE *fp = NULL;
    if(!(fp = fopen("fwo.txt", "wt+")))
    {
        printf("\nerror on opening file fwo.txt");
        printf("\nstrike any key to exit.");
        getchar();
        exit(1);
    }
    char msg, ch;
    // char msg[20], ch;
    // scanf("%s", msg);
    msg = getchar();
    while(msg != '\n')
    {
    fputc(msg, fp);
    msg = getchar();
    }

    rewind(fp);// !!!將文件的位置指針移至文件開頭

    while((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }
    fclose(fp);
}

// #include<stdio.h>
// #include<stdlib.h>
// main()
// { 
//     FILE *fp;
//     char ch; 
//     if((fp=fopen("fwo.txt","wt+"))==NULL)
//     { 
//         printf("Cannot open file strike any key exit!");
//         getchar();
//         exit(1);
//     }
//     printf("input a string:\n");
//     ch=getchar();
//     while (ch!='\n')
//     {
//         fputc(ch,fp);
//         ch=getchar();
//     }
//     rewind(fp);
//     ch=fgetc(fp);
//     while(ch!=EOF)
//     {
//         putchar(ch);
//         ch=fgetc(fp);
//     }
//     printf("\n");
//     fclose(fp);
// }