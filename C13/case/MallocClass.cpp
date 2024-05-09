//:C:13:MallocClass.cpp
// Malloc with class objects
// What you'd have to do if not for "new"
#include"../../Require.h"
#include<cstdlib>// malloc() & free()
#include<cstring>// memset()
#include<iostream>

using namespace std;

class Obj
{
        int i, j, k;
        enum{sz = 100};
        char buf[sz];
    public:
        void initialize()
        {
            // can't use constructor
            cout << "initializing Obj" << endl;
            i = j = k = 0;
            memset(buf, 0, sz); 
        }
        void destroy()const {cout << "destroying Obj" << endl;}
};

int main()
{
    Obj* obj;
    obj = (Obj*)malloc(sizeof(Obj));
    require(obj != 0);
    (*obj).initialize();
    // ...something later:
    (*obj).destroy();
    free(obj);
    return 0;
}