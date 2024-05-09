#include<stdio.h>

int main()
{
    enum Weekday{MON,TUE,WEN,THU,FRI,SAT,SUN = 26};// MON,TUE..等这些称为枚举值，枚举值是常量，不能再对其进行赋值(如MON = 6)
    enum Weekday a, b, c;
    a = MON;// 只能把枚举值赋予枚举变量，不能对其赋予数值（除非使用强制类型转换，如a = (enum Weekday）26
    a = (enum Weekday)26;
    printf("%d", a);
}