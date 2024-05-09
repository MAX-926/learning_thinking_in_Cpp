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
    fwrite(boya, sizeof(struct stu), 2, fp);
    rewind(fp);
    fread(qq, sizeof(struct stu), 2, fp);
    printf("\n\nname\tnumber    age     addr\n");
    for(i = 0; i < 2; i++, qq++)
    {
        printf("%s\t%5d%7d      %s\n", qq->name, qq->num, qq->age, qq->addr);
    }
    fclose(fp);
    return 0;
}