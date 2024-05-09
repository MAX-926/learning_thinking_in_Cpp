//:C12:CopyWithPointers.cpp
// Solving the pointer aliasing problem by
// duplicating what is pointed to during
// assignment and copy-consturction
#include "E:\thinking in C++\Require.h"
#include<string>
#include<iostream>
using namespace std;

class Dog
{
        string nm;
    public:
        Dog(const string& name):nm(name){ cout << "creating Dog: " << *this << endl;}
        // Systhesized copy-constructor & operator=
        // are correct
        // create a Dog from a Dog pointer:
        Dog(const Dog* dp, const string& msg): nm(dp->nm + msg)
        {
            cout << "Copied dog " <<  *this << " from " << *dp << endl;
        }
        ~Dog(){cout << "deleting Dog: " << *this << endl;}
        void rename(const string& newName)
        {
            nm = newName;
            cout << "Dog renamed to: " << *this << endl;
        }
        friend ostream& operator<<(ostream& os, const Dog& d)
        {
            return os << "[" << d.nm << "]";   
        }
};

class DogHouse
{
        Dog* p;
        string houseName;
    public:
        DogHouse(Dog* dog, const string& house):p(dog), houseName(house){}
        DogHouse(const DogHouse& dh):p(new Dog(dh.p, " copy-constructed")), houseName(dh.houseName + " copy-constructed"){}
        DogHouse& operator=(const DogHouse& dh)
        {
            // Check for self-assignment:检查二者的地址是否一致
            if(&dh != this)
            {
                p = new Dog(dh.p, " assigned");
                houseName = dh.houseName + " assigned";
            }
            return *this;
        }
        void renameHouse(const string& newName)
        {
            houseName = newName;
        }
        Dog* getDog(){return p;}
        ~DogHouse(){delete p;}
        friend ostream& operator<<(ostream& os, const DogHouse& dh)
        {
            return os << "[" << dh.houseName << "] contains " << *dh.p;
        }
};

int main()
{
    DogHouse fidos(new Dog("Fido"), "FidoHouse");
    cout << fidos << endl;
    DogHouse fidos2 = fidos;// Copy-construction
    cout << fidos2 << endl;
    fidos2.getDog()->rename("Spot");
    fidos2.renameHouse("SpotHouse");
    cout << fidos2 << endl;
    fidos = fidos2;// Assignment
    cout << fidos << endl;
    fidos.getDog()->rename("Max");
    fidos2.renameHouse("MaxHouse");
}