#include<iostream>
using namespace std;
class Simple
{
    public:
        Simple(){cout << "class Simple's constructor was called\n";}
        ~Simple(){cout << "class Simple's destructor was called\n";}
};

int main(void){Simple s;return 0;}