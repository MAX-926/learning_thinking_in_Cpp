#include<stdio.h>
#include<stdlib.h>
typedef struct Stu
{
    int ID;
    int age;
    struct Stu* next;
} STU;
void create(STU*, int);
int main()
{
    STU stu, *head = &stu;
    create(head, 3);
    int i;
    STU* now = head;
    for(i = 0; i < 3; i++)
    {
        printf("ID     age\n");
        scanf("%d %d", &(now->ID), &(now->age));
        now = now->next;
        fflush(stdin);
    }
    // now->ID = 1913125;
    // now->age = 18;
    // now = now->next;
    // now->ID = 1913126;
    // now->age = 19;
    // now = now->next;
    // now->ID = 1913127;
    // now->age = 20;
    now = head;
    while(now)
    {
        printf("ID:%d age:%d\n", now->ID, now->age);
        now = now->next;
    }
    return 0;
}

void create(STU* head, int len)
{
    int i;
    // head = (STU*)malloc(sizeof(STU));
    STU* pre = head;
    for(i = 1; i < len; i++)
    {
        pre->next = (STU*)malloc(sizeof(STU));
        pre->next->next = NULL;
        pre = pre->next;
    }
}