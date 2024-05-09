#include<iostream>

class A
{
    public:
        A(){std::cout << "class A default-constructor\n";}
};

class B
{
    public:
        B(){std::cout << "class B default-constructor\n";};
};

class C:public A
{
    B b;
};

int main()
{
    C c1;
    return 0;
}

// 对于类型C的对象，先调用基类A的默认构造函数，接着调用子对象b的默认构造函数