// #include<iostream>
// using namespace std;

// class Simple
// {
//     private:
//         int i;
//     public:
//         Simple(int ii = 0):i(ii){cout << "Simple construction\n";}
//         Simple(const Simple& scp):i(scp.i){cout << "Simple copy-construction\n";}
//         ~Simple(){cout << "Simple destruction\n";}
//         Simple& operator=(const Simple& s){i = s.i; cout << "Simple operator=\n";}
//         friend ostream& operator<<(ostream& os, const Simple& s)
//         {
//             return os << "s.i: " << s.i << endl;
//         }
// };

// int main()
// {
//     // Simple s1, s2(1);
//     // s1 = s2;
//     Simple s1;
//     Simple s2(s1);
//     cout << s1 << s2;
// }

#include<iostream>
using namespace std;

class Simple
{
    private:
        int i;
    public:
        Simple(int ii = 0):i(ii){}
        ~Simple(){}
        Simple(const Simple& s){i = s.i;}// 拷贝构造函数的参数不能是自身的对象的原因：会引发拷贝构造函数的递归调用？
        Simple& func(Simple s){i = s.i; return *this;}
        friend ostream& operator<<(ostream& os, const Simple& s)
        {
            return os << "s.i: " << s.i << endl;
        }
};

int main()
{
    Simple s1, s2(26);
    cout << "s1: " << s1 << "s2: " << s2;
    s1.func(s2);
    cout << "s1: " << s1 << "s2: " << s2;
    return 0;
}