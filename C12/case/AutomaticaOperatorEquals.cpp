#include<iostream>
using namespace std;

class Cargo
{
    public:
        Cargo& operator=(const Cargo&)
        {
            cout << "inside Cargo::operator=()" << endl;
            return *this;
        }
};

class Truck
{
    Cargo b;
};

class Object
{
        int i;
    public:
        Object(int ii = 0):i(ii){}
        void show(){cout << i << endl;}
};

int main()
{
    // Truck a, b;
    // a = b;// Prints:"inside Cargo::operator=()"
    Object o1, o2(1);
    o1.show();
    o1 = o2;
    o1.show();
}