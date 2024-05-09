//:C12:TypeConversionAmbiguity.cpp
class Orange;
class Apple
{
    public:
        operator Orange()const;// Convert Apple to Orange
};

class Orange
{
    public:
        Orange(Apple);// Convert Apple to Orange
};

// 两种构造目标类型的方式：1.以原始类型为输入，直接进行形式参数目标类型的构造（调用目标类型的构造函数）；2、从原始参数直接变换成形式参数类型，再调用拷贝构造函数（调用目标类型的拷贝构造函数）
void f(Orange){}

int main()
{
    Apple a;
    // f(a);
    // ! f(a); // Error: ambiguous conversion
}///:~

// 问题的解决方法：定义单一的，从某类型到另一类型的自动类型转换