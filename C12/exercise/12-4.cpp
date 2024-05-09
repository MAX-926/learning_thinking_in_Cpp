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
        // import operator++ operator--
        //prefix ++
        Simple& operator++(){++i; return *this;}
        //postfix ++
        Simple operator++(int){Simple s = i; i++; return s;}
        //prefix --
        Simple& operator--(){--i; return *this;}
        //postfix --
        Simple operator--(int){Simple s = i; i--; return s;}
        void print(){cout << "i: " << i << endl;}
        friend ostream& operator<<(ostream& os, const Simple& s){return os << "i: " << s.i << endl;}
};

int main()
{
    Simple s1(0);
    cout << "++s1: " << ++s1 << endl << "s1++: " << s1++ << "s1: " << s1 << endl;
    cout << "******************************" << endl;
    cout << "--s1: " << --s1 << endl << "s1--: " << s1-- << "s1 :" << s1 << endl;
}