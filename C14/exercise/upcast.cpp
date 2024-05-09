#include<iostream>
#include<string>
using namespace std;

class Norm
{
    private:
        string normName;
    public:
        Norm(string init_name):normName(init_name){}
        void show(){cout << normName << endl;}
};

class Specific
{
    private:
        string specName;
    public:
        Specific(string init_name):specName(init_name){}
        operator Norm(){return Norm(specName);}
        void show(){cout << specName << endl;}
};

void func(Norm n)
{
    n.show();    
}

int main()
{
    Norm n("Norm_obj");
    Specific s("spec_obj");
    func(s);
    return 0;
}