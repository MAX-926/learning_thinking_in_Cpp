// 文件的開關
// FILE *fp = fopen("fileName", "mod");
// mod:3*2*2(共計12種) r/w/a t/b +/

// 文件的讀寫
// fgets(),fputc()
// fgets(), fputs()
// fread(), fwrite()
// fprintf(), fscanf()
// 讀某個文件并輸出

#include<stdio.h>

main()
{
    FILE *fp = NULL;
    fp = fopen("fac.c", "rt");
    char ch;
    while((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }
    fclose(fp);
}