//:C12:Strings1.cpp
// No auto type conversion
#include "../Require.h"
#include<cstring>
#include<cstdlib>
using namespace std;

class Stringc
{
        string s;
    public:
        Stringc(const string& str = ""):s(str){}
        int strcmp(const Stringc& S)const
        {
            return ::strcmp(s.c_str(), S.s.c_str());
        }
        // ...etc., for every function in string
};

int main()
{
    Stringc s1("hello"), s2("there");
    s1.strcmp(s2);
}///:~