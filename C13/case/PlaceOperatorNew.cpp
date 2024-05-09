//:C:13:PlaceOperatorNew.cpp
// Placement with operator new()
#include<cstddef> //Size_t
#include<iostream>
using namespace std;

class X
{
        int i;
    public:
        X(int ii = 0):i(11)
        {
            cout << "this = " << this << endl;
        }
        ~X()
        {
        cout << "X::~X(): " << this << endl;
        }
        void* operator new(size_t, void* loc)
        {
            return loc;
        }
};

int main()
{
    int l[10];
    cout << "l = " << l << endl;
    X* xp = new(l) X(47);
    xp->X::~X();// Explicit destructor call
    // Only use with placement!
}///:~