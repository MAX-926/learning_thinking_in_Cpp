// #include<stdio.h>

// main()
// {
//     int i = 0;
//     TAG:if(i <= 10) // 本质：是从0到10的判断，只是输出有所变化
//     {
//         printf("%d\n" ,++i);
//         goto TAG; 
//     }
// }

#include<stdio.h>

main()
{
    int i = 0, sum = 0;
    i = 1;
    loop: if(i <= 100)
    {
        sum += i;
        i++;
        goto loop;
    }
    printf("%d", sum);
}