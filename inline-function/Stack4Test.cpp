//:C09:Stack4Test.cpp
// {T} Stack4Test.cpp
#include"Stack4.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main(int argc, char* argv[])
{
    //requireArgs(argc, 1);
    ifstream in(argv[1]);
    //assure(in, argv[1]);
    Stack Textlines;
    string line;
    while(getline(in, line))
    {
        Textlines.push(new string(line));
    }
    string* s;
    while((s = (string*)Textlines.pop()) != 0)
    {
        cout << *s << endl;
        delete s;
    }
}///:~