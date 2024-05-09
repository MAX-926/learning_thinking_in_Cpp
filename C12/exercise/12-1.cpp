#include<iostream>
using namespace std;

class Simple
{
    private:
        int i;
    public:
        Simple(int ii = 0):i(ii){}
        Simple& operator++(){++i; return *this;}
        const Simple operator++(int){Simple s = i; i++; return s;}
        friend ostream& operator<<(ostream& os, const Simple& s){return os << "s.i: " << s.i << endl;}
};

int main()
{
    Simple s;// Simple s(0);
    // int s = 0;
    // cout << "s++: " << endl;
    // cout << s++;
    // cout << "++s: " << endl;
    // cout << ++s;
    cout << "((s++)++)++: " << endl;
    cout << ((s++)++)++;// 使用在基本数据类型就会出错。“lvalue required as increment operand”
    // cout << "s: " << endl;
    // cout << s;
    // cout << "++(++(++s)): ";
    // cout << ++(++(++s));
    return 0;
}