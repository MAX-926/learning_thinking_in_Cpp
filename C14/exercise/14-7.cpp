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
};

class Derived1:public Base
{
    public:
        void g() const{}
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
    // int x = d1.f();
    // d1.f(s);
    Derived2 d2;
    d2.f();// 通过程序的输出可以看出，f()是Derived2的版本
    // x = d2.f();
    // ! d2.f(s); // string version hidden
    Derived3 d3;
    d3.f();  // 通过程序的输出可以看出，f()是Derived3的版本
    // ! x = d3.f(); // return int version hidden
    Derived4 d4;
    d4.f(0); // 从编译器报错就可以看出，基类的f()不能通过d4调用
    // ! x = d4.f(); // f() veriosn hidden
    // x = d4.f(1);
}///:~