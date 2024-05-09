#include<stdio.h>
#include<assert.h>

main()
{
    char *cp, st[30];
    int i, counter;
    // assert(counter == 16);
    counter = 0;
    cp = st;
    scanf("%s", cp);
    for(i = 0; cp[i] != '\0'; i++)
    {
        // printf("%c", cp[i]);
        if(cp[i] == 'k') counter++;
    }
    printf("%d", counter);
}