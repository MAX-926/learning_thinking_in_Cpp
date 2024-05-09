#include<stdio.h>
#include<stdlib.h>
typedef struct Stu
{
    char name[10];
    int age;
} STU;

int main()
{
    STU* sp = (STU*)calloc(3, sizeof(STU));
    STU* head = sp;
    int i;
    for(i = 0; i < 3; i++)
    {        
        scanf("%s %d",sp->name, &(sp->age));
        sp++;
        fflush(stdin);
    }
    printf("name\t\t\tage\t\t\n");
    sp = head;
    for(i = 0; i < 3; i++)
    {
        printf("%s\t\t%d\n", sp->name, sp->age);
        sp++;
    }
    free(head);
    return 0;
}