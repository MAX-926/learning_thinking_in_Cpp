//:14:Combined.cpp
// Inheritance & composition

#include<iostream>
using namespace std;

class A
{
        int i;
    public:
        A(int ii):i(ii){cout << "A()\n";}
        ~A(){cout << "~A()\n";}
        void f() const{}
};

class B
{
        int i;
    public:
        B(int ii):i(ii){cout << "B()\n";}
        ~B(){cout << "~B()\n";}
        void f() const {}
};
class C:public B
{
        A a;
    public:
        C(int ii):B(ii), a(ii){cout << "C()\n";}
        ~C(){cout << "~C()\n";}// Calls ~A() and ~B()
        void f() const 
        {
            a.f();
            B::f();
        }
};

class D:public B
{
        C c;
    public:
        D(int ii):B(ii), c(ii){cout << "D()\n";}
        ~D(){cout << "~D()\n";}
};


int main()
{
    // C c(47);
    D d(47);
    return 0;
}///:~
// B->B->A->C->D