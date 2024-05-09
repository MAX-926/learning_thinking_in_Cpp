//:C12:IostreamOperatorOverloading.cpp
// Example of non-member overloaded operators
#include"E:\thinking in C++\inline-function\Require.h"
#include<iostream>
#include<sstream>// "String stream"
#include<cstring>
using namespace std;

class IntArray
{
        enum {sz = 5};
        int i[sz];
    public:
        IntArray(){memset(i, 0, sz*sizeof(*i));}
        int& operator[](int x)
        {
            require(x >= 0 && x < sz, "IntArray::operator[] out of range");
            return i[x];
        }
        friend ostream& operator<<(ostream& os, const IntArray& ia); // cout << obj;非成员函数
        friend istream& operator>>(istream& is, IntArray& ia); // obj << obj';
};

ostream& operator<<(ostream& os, const IntArray& ia)
{
    for(int i = 0; i < ia.sz; i++)
    {
        os << ia.i[i];
        if(i != ia.sz - 1)
        {
            os << ", ";
        }
    }
    os << endl;
    return os;
}

istream& operator>>(istream& is, IntArray& ia)
{
    for(int i = 0; i < ia.sz; i++)
    {
        is >> ia.i[i];
    }
    return is;
}
int main()
{
    stringstream input("47 34 56 92 103");
    IntArray I;
    input >> I;
    I[4] = -1;// Use overloaded oprtator[] 
    cout << I;
}