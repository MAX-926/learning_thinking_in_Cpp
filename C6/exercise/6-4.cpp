#include<iostream>
using namespace std;

class Simple
{
    private:
    public:
        ~Simple(){cout << "class Simple's destructor was called\n";}
};

int main(void)
{
    int flag = 1;
    while(flag)
    {
        cout << "Into while loop\n";
        Simple s;
        goto X;
        flag = 0;
    }
    cout << "get out while loop\n";
    X:cout << "goto here\n";
}
//C++编译器总是保证对象的构造函数与析构函数在正确的时机被正确调用