#include<stdio.h>

main()
{
    int a, b, c, d, e, f, re;
    a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;
    re = a>b?a:(b>c?b:(c>d?c:(d>e?d:(e>f?e:f) ) ) );// 右结合性
    printf("re = %d\n", re);// re = 6
}