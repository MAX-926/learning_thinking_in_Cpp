//:C12:ReferenceCounting.cpp
// Reference count, copy-on-write
#include"E:\thinking in C++\Require.h"
#include<string>
#include<iostream>
using namespace std;

class Dog
{
        string nm;
        int refcount;
        Dog(const string& name):nm(name), refcount(1)
        {
            cout << "creating Dog: " << *this << endl;
        }
        // Prevent assignment:
        Dog& operator=(const Dog& rv);// 只声明，不实现：不允许使用operator=的意思
    public:
        // Dogs can only be created on the heap: 通过将类的构造函数私有化，并提供类方法作接口以构造类的实例
        static Dog* make(const string& name)
        {
            return new Dog(name);
        }
        Dog(const Dog& d):nm(d.nm + " copy"), refcount(1)
        {
            cout << "Dog copy-constructor: " << *this << endl;
        }
        ~Dog()
        {
            cout << "Delting Dog: " << *this << endl;
        }
        void attach()// 产生绑定
        {
            ++refcount;
            cout << "Attached Dog: " << *this << endl;
        }
        void detach()// 解除绑定
        {
            require(refcount != 0);
            cout << "Detaching Dog: " << *this << endl;
            // Destroy object if no one is using it:
            if(--refcount == 0) delete this;    
        }
        // Conditionally copy this Dog.
        // Call before modifying the dag, assign
        // resulting pointers to your Dog*.
        Dog* unalias()
        {
            cout << "Unaliasing Dog: " << *this << endl;
            // Don't duplicate if not aliased:
            if(refcount == 1) return this;
            --refcount;
            // Use copy-constructor to duplicate:
            return new Dog(*this);
        }
        void rename(const string& newName)
        {
            nm = newName;
            cout << "Dog renamed to: " << *this << endl;
        }
        friend ostream& operator<<(ostream& os, const Dog& d)
        {
            return os << "[" << d.nm << "], rc = " << d.refcount;
        }
};

class DogHouse
{
    private:
        Dog* p;
        string houseName;
    public:
        DogHouse(Dog* dog, const string& house):p(dog), houseName(house)
        {
            cout << "Created Doghouse: " << *this << endl;
        }
        DogHouse(const DogHouse& dh):p(dh.p), houseName("copy-constructed " + dh.houseName)
        {
            p->attach();
            cout << "DogHouse copy-constructor: " << *this << endl;
        }
        DogHouse& operator=(const DogHouse& dh)
        {
            //Check for self-assignment
            if(&dh != this)
            {
                houseName = dh.houseName + "assigned";
                // Clean up what you are using first:
                p->detach();
                p = dh.p; // Like copy-constructor
                p->attach();
            }
            cout << "DogHouse operator= : " << *this << endl;
            return *this;
        }
        // Decrement refcount, conditionally destroy
        ~DogHouse()
        {
            cout << "DogHouse destructor: " << *this << endl;
            p->detach();
        }
        void renameHouse(const string& newName)
        {
            houseName = newName;
        }
        void unalias(){p = p->unalias();}
        // Copy-on-write, Anytime you modify the
        // contents of the pointer you must
        // first unalias it:
        void renameDog(const string& newName)
        {
            unalias();
            p->rename(newName);
        }
        // ... or when you allow someone else access:
        Dog* getDog()
        {
            unalias();
            return p;
        }
        friend ostream& operator<<(ostream& os, const DogHouse& dh)
        {
            return os << "[" << dh.houseName << "] contains " << *dh.p;
        }
};

// class M
// {
//     private:
//         int i;
//     public:
//         M(int ii = 0):i(ii){}
//         ~M(){}
//         void detach()
//         {
//             delete this;
//         }
// };

int main()
{
    DogHouse fidos(Dog::make("Fido"), "FidoHouse"),
             spots(Dog::make("Spot"), "SpotHouse");   
    cout << "Entering copy-construction" << endl;
    DogHouse bobs(fidos);
    cout << "After copy-construction bobs" << endl;
    cout << "fidos:" << fidos << endl;
    cout << "spots:" << spots << endl;
    cout << "bobs:" << bobs << endl;
    cout << "Entering spots = fidos" << endl;
    spots = fidos;
    cout << "After spots = fidos" << endl;
    cout << "spots:" << spots << endl;
    cout << "Entering self-assignment" << endl;
    bobs = bobs;
    cout << "After self-assignment" << endl;
    cout << "bobs" << bobs << endl;
    // Commnet out the following lines:
    bobs.getDog()->rename("Bob");
    cout << "After rename{\"Bob\"}" << endl;
}///:~