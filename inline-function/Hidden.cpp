//:C09:Hidden.cpp
// Hidden activities in inlines
#include<iostream>
using namespace std;

class Member
{
    private:
        int i, j, k;
    public:
        Member(int x = 0):i(x), j(x), k(x){}
        ~Member(){cout << "~Member()" << endl;} 
};

class WithMembers
{
    private:
        Member  q, r, s;// Have constructor
        int i;
    public:
        WithMembers(int ii):i(ii){}
        ~WithMembers(){cout << "~WithMembers()" << endl;}
};

int main()
{
    WithMembers wm(1);
}///:~