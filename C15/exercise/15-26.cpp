//:C15:OStackTest.cpp
// {T} OStackTest.cpp
#include "../case/OStack.h"
#include"../../Require.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

ofstream out("o1.out");

class Myclass
{
        string name;
    public:
        virtual ~Myclass(){out << "deleting Myclass\n";}
        Myclass(string mname):name(mname){}
        string get_name(){return name;}
};

class Myderived:public Myclass, public Object
{
    public:
        ~Myderived(){out << "deleting Myderived: " << this->get_name() << endl;}
        Myderived(string mname):Myclass(mname), Object(){}
        string get_name(){return Myclass::get_name();}
};


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
    // requireArgs(argc, 1);// File name is argument
    // ifstream in(argv[1]);
    // assure(in, argv[1]);
    // Stack textlines;
    // string line;
    // while(getline(in, line))
    // {
    //     textlines.push(new MyString(line));
    // }
    // // Pop some lines from the stack:
    // MyString* s;
    // for(int i = 0; i < 10; i++)
    // {
    //     if((s = (MyString*)textlines.pop()) == 0)
    //     break;
    //     out << *s << endl;
    //     delete s;
    // }
    // out << "Letting the destructor do the rest:"
    //      << endl;

    Stack textlines;
    string line;
    ifstream in("E:\\thinking in C++\\C15\\exercise\\15-26.cpp");
    while(getline(in, line))
    {
        textlines.push(new Myderived(line));
    }
    Myderived* s;
    for(int i = 0; i < 10; i++)
    {
        if((s = (Myderived*)textlines.pop()) == 0)
            break;
        out << s->get_name() << endl;
        delete s;
    }
    out << "Letting the destructor do the rest\n";
}///:~