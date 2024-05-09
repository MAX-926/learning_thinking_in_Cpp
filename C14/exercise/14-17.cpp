#include<iostream>
using namespace std;

class Base
{
    public:
        Base(){cout << "Base()\n";}
        ~Base(){cout << "~Base()\n";}
};

class Inheritance_1:private Base
{
    public:
        operator Base(){cout << "i1::operator Base()\n"; return Base(*this);}
};

class Inheritance_2:protected Base
{
    public:
        operator Base(){cout << "i2::operator Base()\n"; return Base(*this);}
};

void converse(Base& b){}

int main()
{
    Inheritance_1 i1;
    Inheritance_2 i2;
    converse(i1);
    converse(i2);
}