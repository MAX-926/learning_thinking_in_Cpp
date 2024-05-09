#include<iostream>
using namespace std;

class Base
{
    public:
        virtual void vfunc(){cout << "Base::vf()\n";}
};

class Derived:public Base
{
    public:
        Derived(Base& b){cout << "Constructor\n";b.vfunc();cout << "behaviour\n";}
        void vfunc(){cout << "Derived::vf()\n";}
        void member_func(Base& b){b.vfunc();}
        void mem(){cout << "mem\n";}
};

int main()
{
    Base b;
    Derived d1(b);
    cout << "*************";
    Derived d2(d1);// 在这里，为构造函数传入Derived时，虚机制不生效（没有输出Derived::vf(),而且构造函数函数体的代码都不执行）
    cout << "\n虚机制生效" << endl;
    d1.member_func(d1);// 虚机制生效
    d2.mem();
    cout << sizeof(d1) << " " << sizeof(d2);
}