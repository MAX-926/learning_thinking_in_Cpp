//:C12:NestedSmartPointer.cpp
#include<iostream>
#include<vector>
#include"E:\thinking in C++\inline-function\Require.h"
using namespace std;

class Obj
{
        static int i, j;
    public:
        void f(){cout << i++ << endl;}
        void g(){cout << j++ << endl;}
};
//Static member definitions:
int Obj::i = 47;
int Obj::j = 11;

class ObjContainer
{
        vector<Obj*> a;
    public:
        void add(Obj* o){a.push_back(o);}
        class SmartPointer;
        friend SmartPointer;
        class SmartPointer
        {
            private:
                ObjContainer& oc;
                int index;
            public:
                SmartPointer(ObjContainer& objc):oc(objc){index = 0;}
                bool operator++()
                {
                    if(index >= oc.a.size()){return false;}
                    if(oc.a[++index] == 0){return false;}
                    return true;
                }
                bool operator++(int)
                {
                    return operator++();
                }
                Obj* operator->()const
                {
                    require(oc.a[index] != 0, "Zero value ""returned by SmartPointer::operator->()");
                    return oc.a[index];
                }
                // Functions to provide a smart pointer that
                // points to the begining of the ObjContainer:
        };
        SmartPointer begin()
        {
            return SmartPointer(*this);
        }
};

int main()
{
    const int sz = 10;
    Obj o[sz];
    ObjContainer oc;
    for(int i = 0; i < sz; i++)
    {
        oc.add(&o[i]);
    }
    ObjContainer::SmartPointer sp = oc.begin();
    do
    {
        sp->f();
        sp->g();
    }while(sp++);
}