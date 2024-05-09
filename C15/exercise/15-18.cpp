#include<iostream>
using namespace std;

class Base
{
        int b_data;
    public:
};

class Derived:public Base
{
        int d_data;
    public:
};

void func(Base b)
{
    cout << sizeof(b) << endl;
}

int main()
{
    Derived d;
    func(d);

    // Result:4
    // Explanation: 将派生类对象d传入func时，发生了对象切片,，保留了构成基类所需的部分，
}
