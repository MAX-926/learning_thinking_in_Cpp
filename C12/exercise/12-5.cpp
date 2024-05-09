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
        const Simple operator++(int){Simple s = i; i++; return s;}
        //prefix --
        Simple& operator--(){--i; return *this;}
        //postfix --
        const Simple operator--(int){Simple s = i; i--; return s;}
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

//结论：在实际中为前缀版本使用非常量的意义在于，前缀版本立即改变操作数的值，代码上能立即返回操作数的地址；
//而为后缀版本使用常量的意义在于，代码上后缀版本会返回一个临时变量，这个临时变量不应该被寻址于改变，否则将引入错误与安全问题。