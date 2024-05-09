#include<stdio.h>
void move(int, char, char, char);

main()
{
    move(3, 'a', 'b', 'c');
}

void move(int n, char x, char y, char z)
{
    if(n == 1) printf("%c -> %c\n", x, z);
    else
    {
        move(n-1, x, z, y);
        printf("%c -> %c\n", x, z);
        move(n-1, y, x, z);
    }
}