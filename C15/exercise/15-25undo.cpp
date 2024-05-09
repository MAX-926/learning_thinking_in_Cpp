#include<typeinfo>
#include<iostream>
using namespace std;
class Base
{
    public:
        virtual Base* clone(){cout << "Base::clone\n"; return new Base(*this);}
};

class Derived1:public Base
{
    Derived1* clone(){cout << "Derived1::clone\n"; return new Derived1(*this);}
};

class Derived2:public Base
{
    Derived2* clone(){cout << "Derived2::clone\n"; return new Derived2(*this);}
};

int main()
{
    Derived1 d1;
    Derived2 d2;
    Base* ba[] = {&d1, &d2};
    Derived1* dp = (ba[0]->clone());
    // cout << (typeid(ba[0]->clone()) == typeid(Derived1*))?1:0;
    // cout << (typeid(ba[1]->clone()) == typeid(Derived2*))?1:0;
    // ba[1]->clone();
    // cout << typeid(Derived1*).name();
    // cout << typeid(Derived2*).name();
    // // 虚函数的返回值不允许更改，最后实际产生Base类型的指针
    // cout << typeid(ba[0]->clone()).name();
    // cout << typeid(ba[1]->clone()).name();
}