// 格式化读写函数
#include<stdio.h>
#include<stdlib.h>

struct stu
{
    char name[10];
    int num;
    int age;
    char addr[15];
}boya[2], boyb[2], *pp, *qq;

int main()
{
    FILE *fp;
    char ch;
    int i;
    pp = boya;
    qq = boyb;
    if(!(fp = fopen("stu_list.txt", "wt+")))
    {
        printf("\nerror in opening file stu_list...");
        getchar();
        exit(1);
    }
    printf("\ninput data:");
    for(i = 0; i < 2; i++)
    {
        scanf("%s %d %d %s", pp->name, &pp->num, &pp->age, pp->addr);
        pp++;
    }
    // fwrite(boya, sizeof(struct stu), 2, fp);
    pp = boya;// 使用指针变量前要检查其值是否与预期情况相符
    for(i = 0; i < 2; i++, pp++)
        fprintf(fp, "%s %d %d %s\n", pp->name, pp->num, pp->age, pp->addr);// 也会引发文件位置指针的移动
        // 假如没有按照正确的格式输出，之后的输出是否会乱套？
    rewind(fp);
    // fread(qq, sizeof(struct stu), 2, fp);
    for(i = 0; i < 2; i++, qq++)
    {
        fscanf(fp, "%s %d %d %s", qq->name, &qq->num, &qq->age, qq->addr);// 也会引发文件位置指针的移动
        // 假如没有按照正确的格式读取，之后的输出是否会乱套？
    }
    qq = boyb;
    printf("\n\nname\tnumber    age     addr\n");
    for(i = 0; i < 2; i++, qq++)
    {
        printf("%s\t%5d %7d      %s\n", qq->name, qq->num, qq->age, qq->addr);
    }
    fclose(fp);
    return 0;
}

// Summary: fprintf(FILE*, "format", ...), 将给出的变量按格式输出到fp指向的文件
//          fscanf(fp, "format", ...)， 将fp指向的文件，按格式取出内容，输出到给出的变量中
// 与fread与fwrite相比较，有“分块”的概念；前者将内存试做字节块进行操作，后者将内存视作存在类型的字节块进行处理！！！