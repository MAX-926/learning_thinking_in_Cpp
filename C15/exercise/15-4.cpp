//:14:Combined.cpp
// Inheritance & composition
#include<iostream>
using namespace std;
class A
{
        int i;
    public:
        A(int ii):i(ii){}
        ~A(){}
        void f() const{cout << "A::f()\n";}
};

class B
{
        int i;
    public:
        B(int ii):i(ii){}
        ~B(){}
        virtual void f() const {cout << "B::f()\n";}
};
class C:public B
{
        A a;
    public:
        C(int ii):B(ii), a(ii){}
        ~C(){}// Calls ~A() and ~B()
        void f() const 
        {
            cout << endl << "C::f()\n";
            a.f();
            B::f();
        }
};

int main()
{
    C c(47);
    B *bp = &c;
    bp->f();
    return 0;
}///:~