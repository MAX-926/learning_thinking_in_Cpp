//:C:13:NoMemory.cpp
// Constructor isn't called if new fails
#include<iostream>
#include<new> // bad_alloc definition
using namespace std;

class NoMemory
{
    public:
        NoMemory(){cout << "NoMemory::NoMemory()\n";}
        void* operator new(size_t sz) throw(bad_alloc)
        {
            cout << "NoMemory::operator new\n";
            throw bad_alloc();// "Out of memory"
        }
};
int main()
{
    NoMemory* nm = 0;
    try
    {
        nm = new NoMemory;
    }catch(bad_alloc)
    {
        cerr << "Out of memory exception" << endl;
    }
    cout << "nm = " << nm << endl;
}///:~
