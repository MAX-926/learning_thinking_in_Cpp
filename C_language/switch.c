#include<stdio.h>

main()
{
    char c = getchar();
    switch(c)
    {
        case 'a': printf("alive\n"); c = 'a'; break;
        case 'b': printf("break\n"); c = 'b'; break;
        case 'c': printf("citra\n"); c = 'c'; break;
        case 'd': printf("delete\n"); c = 'd'; break;
        default: printf("found nothing\n");
    }
    //c编译器视c文件为字节流，所以case后不需要加{}表明语句块
    printf("c = %c", c);
    return 0;
}