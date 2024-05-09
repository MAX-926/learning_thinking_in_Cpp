#include<iostream>
using namespace std;

class A
{
  friend A& operator=(const A& a){}// 编译器提示operator=必须是成员函数
};

int main()
{}