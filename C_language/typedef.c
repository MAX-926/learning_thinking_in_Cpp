#include<stdio.h>
typedef char name[20];
main()
{
    name a1, a2, a3;
    gets(a1);
    gets(a2);
    gets(a3);
    printf("%s", a1);
    printf("%s", a2);
    printf("%s", a3);
}