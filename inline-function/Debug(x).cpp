#define DEBUG(X) cout << #X " = " << X << endl
#define TRACE(s) ceer << #s << endl; s
#define FIELD(a) char* a##_string; int a##_size
#include<iostream>
using namespace std;

int main(void)
{
    FIELD(one);
    FIELD(two);
    FIELD(three);
    // ...
    one_string = "MAX";
    DEBUG(one_string);
    // string line = "MAX";
    // DEBUG(line);
    // for(int i = 0; i < 5; i++)
    // {
        // TRACE(f(i));
    // }
    return 0;
}