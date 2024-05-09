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
        ~Derived(){cout << "~Derived()\n";}
        void f(){cout << "Derived::f()\n";}
};

class Derived1:public Derived
{
    public:
        ~Derived1(){cout << "~Derived1()\n";}
        void f(){cout << "Derived1::f()\n";}
};

int main()
{
    Base* bp = new Derived1;// Upcast
    delete bp;
}///:~