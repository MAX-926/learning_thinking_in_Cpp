#include<iostream>
using namespace std;

class Simple
{
    private:
        int i;
    public:
        Simple(int ii = 0):i(ii){}
        ~Simple(){}
        Simple& operator+(){return *this;}
        // Simple operator+(const Simple& s){return Simple(i + s.i);}
        friend Simple operator+(const Simple& lv, const Simple& rv);
        // Simple operator-(const Simple& s){return Simple(i - s.i);}
        friend Simple operator-(const Simple& lv, const Simple& rv);
        friend ostream& operator<<(ostream& os, const Simple& s){return os << "i: " << s.i << endl;}
};

Simple operator+(const Simple& lv, const Simple& rv)
{
    return Simple(lv.i + rv.i);
}

Simple operator-(const Simple& lv, const Simple& rv)
{
    return Simple(lv.i - rv.i);
}

int main()
{
    Simple a(1), b(1), c(1);
    cout << a + b - c;
}