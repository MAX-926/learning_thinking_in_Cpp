#include<iostream>
using namespace std;

class Base1
{
    public: 
        virtual ~Base1(){}
        virtual void show(){cout << "Base1\n";}
    private:
        int x;
};

class Base2
{
    public: 
        virtual ~Base2(){}
        virtual void show(){cout << "Base2\n";}
    private:
        int y;
};

class Derived:public Base1, public Base2
{
    public:
        void show(){cout << "Derived\n";}
        Derived(){}
    private:
        int z;
};

int main()
{
    Derived d;
    // Base1* b1p = new Base1;
    // Base2* bp2 = new Base2;
    // Derived* dp = new Derived;
    // // cout << sizeof(*b1p);
    // cout << sizeof(*dp);// 得到的派生类有两个虚指针
    // // b1p = dp;
    // // b1p->show();
    // return 0;
}