#include<iostream>
using namespace std;

class Simple
{
    private:
        int i;
    public:
        Simple(int ii = 0):i(ii){}
        Simple& operator+(){return *this;}
        Simple operator+(const Simple& s){return Simple(i + s.i);}
        void print(){cout << "i: " << i << endl;}
        friend ostream& operator<<(ostream& os, const Simple& s){return os << "i: " << s.i << endl;}
};

int main()
{
    Simple s1(1), s2(1);
    cout << +s1 << endl;
    cout << s1+s2;
}