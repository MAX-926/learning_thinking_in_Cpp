//:C12:OperatorOverloadingConversion.cpp
class Three
{
    private:
        int i;
    public:
        Three(int ii = 0, int = 0):i(ii){}
};

class Four
{
    private:
        int x;
    public:
        Four(int xx):x(xx){}
        operator Three()const{return Three(x);}// 没有返回值，类型即为要转换的目标类型
};

void g(Three){}

int main()
{
    Four four(1);
    g(four);
    g(1);// Calls Three(1, 0) 存在从int型1到类型Three的转换
}///:~

// #include<iostream>
// using namespace std;

// class Simple
// {
//     private:
//         int i;
//     public:
//         Simple(char){}
//         ~Simple(){}
//         void show(){cout << i;}
// };

// void func(Simple){cout << "func() was called\n";}

// int main()
// {
//     Simple s('m');
//     func(s);
//     func('m');//在类的构造函数中添加可能的接受类型，这将允许从该可能的接受类型到类型的自动类型转换
//     return 0;
// }

// 总结：使用构造函数进行类型转换不能打造基本数据类型的转换；使用运算符重载可以实现用户自定义类型到基本数据类型的转换。 