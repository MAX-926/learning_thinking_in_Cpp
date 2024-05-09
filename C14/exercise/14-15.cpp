#include<iostream>
using namespace std;

class A
{
    public:
        static void static_0(void){cout << "static_0" << endl;}
        static void static_0(int){cout << "static_1" << endl;}
};

class expand:public A
{
    public:
        void static_0(void){cout << "expand::static_0" << endl;}
        void static_0(int){cout << "expand::static_0(int)\n";}
};

int main()
{   
    expand ex;
    ex.static_0();
    ex.static_0(1);
    return 0;
}