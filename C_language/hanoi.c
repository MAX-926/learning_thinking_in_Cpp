// #include<stdio.h>
// long int hanoi(long int);

// main()
// {
//     printf("%ld", hanoi(3));
// }

// long int hanoi(long int circles)
// {
//     // 1 3 7 15... 
//     // hanoi(n)
//     //      2*hanoi(n-1) + 1
//     //        2*hanoi(n-2) + 1
//     if(circles == 1) return 1;
//     else return 2*hanoi(circles-1) + 1;
// }

#include<stdio.h>

move(int n, char x, char y, char z)
{
    if(n == 1) printf("%c -> %c\n", x, z);
    else
    {
        move(n-1, x, z, y);
        printf("%c -> %c\n", x, z);
        move(n-1, y, x, z);
    }
}

main()
{
    move(4, 'a', 'b', 'c');
}