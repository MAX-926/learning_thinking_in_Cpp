//:C12:AutomaticTypeConversion.cpp
// Tpye conversion constructor
#include<iostream>
using namespace std;

class One
{
    public:
        One(){}
};

class Two
{
    public:
        Two(const One&){}
};

void f(Two){cout << "Wants a Two, has a One\n";}

int main()
{
    One one;
    f(one);// Wants a Two, has a One
}///:~