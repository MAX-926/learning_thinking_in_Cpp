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
        Simple operator+(const Simple& s){return Simple(i + s.i);}
        Simple operator-(const Simple& s){return Simple(i - s.i);}
        friend ostream& operator<<(ostream& os, const Simple& s){return os << "i: " << s.i << endl;}
};

int main()
{
    Simple a(1), b(2), c(3);
    cout << a + b - c;
}