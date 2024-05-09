#include<iostream>
#include<string>
using namespace std;

class Base
{
        string name;
    public:
        virtual void show(){cout << name << endl;}
        Base(string bname):name(bname){}
        friend void outputName(Base);
};

class Derived:public Base
{
        string name;
    public:
        void show(){cout << name << endl;}
        Derived():Base("Base"), name("Derived"){}
        friend void outputName(Derived);
        operator Base(){return Base(*this);}
};

// class Unexpected
// {
//         string name;
//     public:
//         Unexpected(string uname):name(uname){}
//         operator Base(){return Base(this->name);}
//         void show(){cout << name << endl;}
// };

void outputName(Base b){cout << b.name;}
void outputName(Derived d){cout << d.name;}

void func(Base b)
{
    // d.Derived::show();
}

int main()
{
}