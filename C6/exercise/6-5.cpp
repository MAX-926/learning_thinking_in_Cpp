#include<iostream>
using namespace std;

int main(void)
{
    int i;
    for(i = 0; i <= 10; i++)
    {
        cout << i << endl;
    }
    cout << "*************\n";
    for(int i = 0; i <=10; i++)
    {
        cout << i << endl;
    }
    return 0;
}
//不会有变化，第一个循环计数器i的作用于是整个main函数；第二个循环计数器ii的作用于仅限于第二个for循环代码块里。