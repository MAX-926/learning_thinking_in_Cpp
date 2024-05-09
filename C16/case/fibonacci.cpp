//: C16:fibonacci.cpp {O}
#include"../../Require.h"
// 1 1 2 3 5 8 13...
int fibonacci(int n)
{
    const int sz = 100;
    require(n < sz);
    static int f[sz];
    f[0] = f[1] = 1;
    // Scan for unfilled array elements:
    int i;
    for(i = 0; i < sz; i++)
    {
        if(f[i] == 0) break;
    }
    while(i <= n)
    {
        f[i] = f[i-1] + f[i-2];
        i++;
    }
    return f[n];
    // if(n == 1) return 1;
    // if(n == 2) return 1;
    // else if(n > 2) return fibonacci(n-1) + fibonacci(n-2);
}
