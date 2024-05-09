//:C15:VirtualsInDestructors.cpp
// Virtual calls inside destructors
#include<iostream>
using namespace std;

class Base
{
    public:
        virtual ~Base()
        // ~Base()
        {
            cout << "~Base1()\n";
            f();
        }
        virtual void f(){cout << "Base::f()\n";}
};

class Derived:public Base
{
    public:
        ~Derived(){cout << "~Derived()\n";f();}
        void f(){cout << "Derived::f()\n";}
};

class Derived1:public Derived
{
    public:
        ~Derived1(){cout << "~Derived1()\n";f();}
        void f(){cout << "Derived1::f()\n";}
};

int main()
{
    Base* bp = new Derived1;// Upcast
    delete bp;
}///:~

// Result:
// Explanation: 析构函数内部不支持虚机制（因为类型信息不可靠，可能会调用到已经被析构的成员，有安全问题），所以将调用本地的f()
// Derived1::f()
// ~Derived()
// Derived::f()
// ~Base1()
// Base::f()