#include<iostream>
using namespace std;
class Simple
{
    private:
        int i;
    public:
        Simple(int ii):i(ii){cout << "i: " << i << " " << "class Simple's constructor was called\n";}
        ~Simple(){cout << "i: " << i << " " << "class Simple's destructor was called\n";}
};

int main(void){Simple s(26);return 0;}