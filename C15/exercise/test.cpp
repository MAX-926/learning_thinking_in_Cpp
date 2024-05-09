// #include<iostream>
// using namespace std;

// class Base
// {
//     public:
//         virtual void name(){cout << "Base\n";}
// };

// class Derived:public Base
// {
//     public:
//         void name(){cout << "Derived\n";}
// };

// void func(Base* bp)
// {
//     bp->name();
// }

// int main()
// {
//     Base b;
//     Derived d;
//     func(&b);
//     func(&d);
//     // b.name();
//     // d.name();

//     return 0;
// }
#include<iostream>
class X
{
    public:
        int func(int){std::cout << "X::func()\n";return 0;}
        static void stfunc(){std::cout << "X::stfunc()\n";}
};

int main()
{
    X x;
    X* px = &x;
    // int (X::*p)(int) = &X::func;
    // (px->*p)(1);
    // (x.*p)(1);
    // x.func(2);
    void(*p)() = &X::stfunc;
    (*p)();
}