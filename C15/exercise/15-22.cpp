#include<iostream>
using namespace std;

class Base
{
    public:
        virtual void vfunc(void)const{cout << "Base::vfunc(void)\n";}
        virtual void vfunc(int)const{cout << "Base::vfunc(int)\n";}
        virtual void vfunc(double)const{cout << "Base::vfunc(double)\n";}
};

class Derived:public Base
{
    public:
        void vfunc()const{cout << "Derived::vfunc(void)\n";}
};

int main()
{
    Derived d;
    // Q1:whether we can call all the base-class function through Derived-object?
    d.Base::vfunc();
    d.Base::vfunc(1);
    d.Base::vfunc(1.0);
    // d.vfunc(); !d.vfunc(1) !d.vfunc(1.0)
    Base* bp = &d;
    bp->vfunc();
    bp->Base::vfunc();
    bp->vfunc(1);
    bp->vfunc(1.0);
    cout << "*************\n";
    d.vfunc();
    d.vfunc(1);
    d.vfunc(1.0);
    return 0;
}