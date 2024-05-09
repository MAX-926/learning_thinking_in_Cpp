//:C14:InheritStack.cpp
//Specializing the Stack classes
#include"E:\thinking in C++\inline-function\Require.h"
#include"E:\thinking in C++\inline-function\Stack4.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class StringStack:public Stack
{
    public:
        void push(string* str)
        {
            Stack::push(str);
        }
        string* peek()const
        {
            return (string*)Stack::peek();
        }
        string* pop()
        {
            return (string*)Stack::pop();
        }
    ~StringStack()
    {
        string* top = pop();
        while(top)
        {
            delete top;//delete 能够清除data的内容？
            top = pop();
        }
    }
};

int main()
{
    ifstream in("InheritStack.cpp");
    assure(in, "InheritStack.cpp");
    string line;
    StringStack textlines;
    while(getline(in, line))
    {
        textlines.push(new string(line));
    }
    string* s;
    while(s = textlines.pop())
    {
        cout << s << endl;
        delete s;//最后textline的析构函数会再对Stack做一次清空检查
    }
}///:~