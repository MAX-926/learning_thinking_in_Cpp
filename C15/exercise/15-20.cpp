#include<iostream>
#include<ctime>
using namespace std;

class Base
{
    public:
        virtual void vfunc(){/*cout << "Base::vfunc()\n";*/}
        void func(){/*cout << "Base::func()\n";*/}
};

class Derived:public Base
{
    public:
        void vfunc(){/*cout << "Derived::vfunc()\n";*/}
        // void func(){}
};

int main()
{
    Derived d;
    Base* bp = &d;
    clock_t t0 = clock();
    for(int i = 0; i < 10000000; i++)
    {
        bp->vfunc();
    }
    clock_t t1 = clock();
    // cout << t0 << " " << t1 << endl;
    cout << "vfunc cost: " << (double)(t1-t0)/CLOCKS_PER_SEC << endl;
    clock_t t2 = clock();
    for(int i = 0; i < 10000000; i++)
    {
        d.func();
    }
    clock_t t3 = clock();
    // cout << t2 << " " << t3 << endl;
    cout << "func cost: " << (double)(t3-t2)/CLOCKS_PER_SEC << endl;
    // cout << CLOCKS_PER_SEC;
    cout << "differences: " << (double)((t3-t2) - (t1-t0))/CLOCKS_PER_SEC << endl;
    // Result:
    // vfunc cost: 0.041
    // func cost: 0.032
    // differences: -0.009
    // 虚函数调用更费时
}