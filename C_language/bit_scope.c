#include<Stdio.h>

struct bits
{
    // unsigned a:4;
    unsigned b:9;
};

main()
{
    struct bits b;
    b.b = 31;
    printf("%d", b.b);
}