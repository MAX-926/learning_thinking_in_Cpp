//:C:14:NameHiding.cpp
// Hiding overloaded names during inheritance
#include<iostream>
#include<string>
using namespace std;

class Base 
{
    public:
        int f() const {cout << "Base::f()\n"; return 1;}
        int f(string) const {return 1;}
        void g(){}
        // 定义h()及其重载版本
        void h(){cout << "h()\n";}
        void h(int){cout << "h(int)\n";}
        void h(char){cout << "h(char)\n";}
};

class Derived1:public Base
{
    public:
        void g() const{}
        void h()
        {
            cout << "Derived1::h()\n";
            // Base::h();
            // Base::h(1);
            // Base::h('m');
        }
};

class Derived2:public Base
{
    public:
        //Redfinition:
        int f() const
        {
            cout << "Derived2::f()\n";
            return 2;
        }
};

class Derived3:public Base
{
    public:
        //Change return type:
        void f() const {cout << "Derived3::f()\n";}
};

class Derived4:public Base
{
    public:  
        //Change argument list:
        int f(int) const {cout << "Derived4::f()\n"; return 4;}
};

int main()
{
    string s("hello");
    Derived1 d1;
    d1.h();
    // d1.Base::h();

    // int x = d1.f();
    // d1.f(s);
    // Derived2 d2;
    // x = d2.f();
    // ! d2.f(s); // string version hidden
    // Derived3 d3;
    // ! x = d3.f(); // return int version hidden
    // Derived4 d4;
    // ! x = d4.f(); // f() veriosn hidden
    // x = d4.f(1);
}///:~