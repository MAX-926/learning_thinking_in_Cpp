//:C12:this-destroy-itself.cpp
#include<iostream>
using namespace std;

class Simple
{
    private:
        int i;
    public:
        Simple(int ii = 0):i(ii){cout << "calling Simple constructor\n";}
        ~Simple(){cout << "calling Simple destructor\n";}
        void deletion(){delete this;}
};

int main()
{
    Simple* sp = new Simple;
    (*sp).deletion();
    cout << "reached the end\n";
}