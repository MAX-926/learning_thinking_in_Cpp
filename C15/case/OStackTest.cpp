//:C15:OStackTest.cpp
// {T} OStackTest.cpp
#include "OStack.h"
#include"../../Require.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

ofstream out("o1.out");
// Use multiple inheritance, we want
// both a string and an Object:
class MyString:public string, public Object
{
    public:
        MyString(string s):string(s){}
        ~MyString(){out << "deleting string: " << *this << endl;}
};

int main(int argc, char* argv[])
{
    requireArgs(argc, 1);// File name is argument
    ifstream in(argv[1]);
    assure(in, argv[1]);
    Stack textlines;
    string line;
    while(getline(in, line))
    {
        textlines.push(new MyString(line));
    }
    // Pop some lines from the stack:
    MyString* s;
    for(int i = 0; i < 10; i++)
    {
        if((s = (MyString*)textlines.pop()) == 0)
        break;
        out << *s << endl;
        delete s;
    }
    out << "Letting the destructor do the rest:"
         << endl;
}///:~