#include<iostream>
using namespace std;

class Top
{
    public:
        Top(){cout << "Top()\n";}
        ~Top(){cout << "~Top()\n";}
};

class Middle:public Top
{
    public:
        Middle(){cout << "Middle()\n";}
        ~Middle(){cout << "~Middle()\n";}
};

class Bottom:public Middle
{
    public:
        Bottom(){cout << "Bottom()\n";}
        ~Bottom(){cout << "~Bottom()\n";}
};

int main()
{
    Bottom b;
    return 0;
}

//“栈式”构造，从基类开始，直到最低层级的派生类型，再从最低层级的类型逐步向更高的抽象层次析构