#include<iostream>
using namespace std;

class A
{
    private:
        int i;
    public:
        A(int ii = 0):i(ii){}
        A& operator++(){++i; return *this;}
        A& operator--(){--i; return *this;}
        friend ostream& operator<<(ostream& os, const A& a){return os << "a.i: " << a.i << endl;}
};

int main()
{
    A a;
    cout << ++a << --a;
}