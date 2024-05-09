#include<iostream>
using namespace std;

class NoConstructor
{
    //
    public:
        NoConstructor(int){}
        ~NoConstructor(){cout << "check as if there was an object created\n";}
};

// static void show(){cout << "show()\n";}

int main(void)
{
    // NoConstructor O;//提示不存在默認構造函數
    // show();
    return 0;
}