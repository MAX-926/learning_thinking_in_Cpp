//:C12:Strings2.cpp
// With type conversion
#include"../Require.h"
#include<cstring>
#include<cstdlib>
#include<string>
using namespace std;

class Stringc
{
    private:
        string s;
    public:
        Stringc(const string& str = ""):s(str){}
        operator const char*()const{return s.c_str();}
};

int main()
{
    Stringc s1("hello"), s2("there");
    strcmp(s1, s2);// Standard C function
    strspn(s1, s2);// Any string function
}