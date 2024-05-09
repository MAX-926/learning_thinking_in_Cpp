//:C12:TypeConversionFanout.cpp

#include<iostream>
using namespace std;

class Orange{};
class Pear{};

class Apple
{
    public:
        operator Orange()const;
        operator Pear()const;
};
// Overloaded eat();
void eat(Orange);
void eat(Pear);

// void func(int){cout << "func(int)\n";}
// void func(double){cout << "func(double)\n";}
// void func(char){cout << "func(char)\n";}

int main()
{
    Apple c;
    // func(0.1f);// 会将float转换成double，而不是int。是因为double的变换相较于到int的窄化变化更安全？？？
    // eat(c);
    //! eat(c);
      // Error: Apple -> Orange or Apple -> Pear ???
}///:~


// 基本数据类型的扇出(Fanout)问题
// #include<iostream>
// using namespace std;

// class Simple
// {
//         int i;
//     public:
//         operator int(){}
//         operator string(){}

// };

// void f(int){}
// void f(string){}

// int main()
// {
//     Simple s;
//     f(s);
//     return 0;
// }