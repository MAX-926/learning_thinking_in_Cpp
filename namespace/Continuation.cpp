// #include"Header2.h"
// #include<iostream>
// // using namespace MyLib;
// void MyLib::f()
// {
//     std::cout << "f()\n";
// }

// void f()
// {
//     std::cout << "global f()\n";
// }

// int main(void)
// {
//     M::f();
//     f();
// }
namespace 
{
    #include<iostream>
    void f(int)
    {
        std::cout << "f(int)\n";
    }
}
// #include<iostream>
class Simple
{
    private:
        int i;
        friend void f(void);
    public:
        Simple(){i = 0;}
};

void f(void)
{
    std::cout << "f()\n";
}

int main(void)
{
    ::f();
}

