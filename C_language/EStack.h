#ifndef ESTACK_H
#define ESTACK_H

struct SymStack
{
    //符号包括 + - * / ( )
    char Sym[10];
    int top;
};

struct ValStack
{
    //double型数据
    double Val[10];
    int top;
};

struct EStack
{
    //管理两个栈结构
    struct SymStack ss;
    struct ValStack vs;
};

double Expression_calculator(char* expression);

#endif // ESTACK_H