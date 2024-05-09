#include<iostream>
#include<new>
#include<cstdlib>
#include<fstream>
using namespace std;

ofstream out("13-11.out");

class Example
{
    private:

    public:
        Example(){out << "Example()\n";}
        ~Example(){out << "~Example()\n";}
        // an Object
        void* operator new(size_t sz)
        {
            out << "operator new\n";
            return malloc(sz);
        }
        void operator delete(void* addr)
        {
            out << "operator delete\n";
            if(!addr){return;}
            free(addr);
            return;
        }
        // an Array
        void* operator new[](size_t sz)
        {
            out << "operator new[]\n";
            return malloc(sz);
        }
        void operator delete[](void* addr)
        {
            out << "operator delete[]\n";
            if(!addr) return;
            free(addr);
            return;
        }
};

int main()
{
    Example* ep = new Example;
    delete ep;
    Example* ea = new Example[26];
    delete []ea;
    return 0;
}
