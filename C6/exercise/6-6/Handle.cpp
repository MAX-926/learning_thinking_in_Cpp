//:C05:Handle.cpp {0}
//Handle implementation
#include"Handle.h"
#include<iostream>
using namespace std;
// Define Handle's implementation
struct Handle::Cheshire
{
    int i;
    Cheshire(){cout << "Cheshire's data member i was defaultly set by 26\n"; i = 26;}
};

Handle::Handle(){cout << "Handle's constructor was called\n"; smile = new Cheshire;}

Handle::~Handle(){cout << "Handle's destructor was called\n"; if(smile != 0) delete smile;}

int Handle::read(){cout << "Cheshire's data member i's value is " << smile->i; return smile->i;}

void Handle::change(int ii){smile->i = ii;}