#include<cassert>
#include<iostream>
using namespace std;

class Number
{
    private:
        double member;
    public:
        // 构造函数、拷贝构造函数与析构函数
        Number(const double m = 0.0):member(m){}
        Number(const Number& m){member = m.member;}
        ~Number(){}
        // 增添重载的 + - * / =。需要支持链式表达式
        friend Number operator+(const Number& lv, const Number& rv){return Number(lv.member + rv.member);}
        friend Number operator-(const Number& lv, const Number& rv){return Number(lv.member - rv.member);}
        friend Number operator*(const Number& lv, const Number& rv){return Number(lv.member * rv.member);}
        friend Number operator/(const Number& lv, const Number& rv){assert(rv.member != 0); return Number(lv.member / rv.member);}
        Number& operator=(const Number& rv){member = rv.member;return *this;}
        // 增添一个自动类型转换operator double()
        // operator double(){return double(member);}
        friend ostream& operator<<(ostream& os, const Number& m){return os << "m.member: " << m.member << endl;}
};

int main()
{
    Number n1(0), n2(1), n3(2), n4(3), n5(5);
    // cout << (((n1+n2)-n3)*n4)/n5+0.6 + 26;
    // cout << n1 + 1;
    n1 = 2.6;
    cout << n1;
}