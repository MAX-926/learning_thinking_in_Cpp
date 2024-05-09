//:C15:AddingVirtuals.cpp
// Adding virtuals in derivation
#include<iostream>
#include<string>
using namespace std;

class Pet
{
        string pname;
    public:
        Pet(const string& petName):pname(petName){}
        virtual string name()const = 0;
        virtual string speak()const = 0;
};
string Pet::name()const{return pname;}

// class Cat:public Pet
// {
//         string cname;
//     public:
//         string name()const{return Pet::name();}
//         string speak()const{return Pet::name() + " says 'meow!'";}
//         string name()const{}
// };

class Dog:public Pet
{
        string dname;
    public:
        Dog(const string& petName):Pet(petName), dname(petName){}
        // New virtual function in the Dog class:
        virtual string sit()const{return Pet::name() + " sits";}
        string speak()const
        {
            //Override
            return Pet::name() + " says 'Bark!'";  
        }
        // string name()const{return name;}
        string name()const{return Pet::name();}
};

int main()
{
    Pet* p[] = {new Dog("Silver"), new Dog("Bob")};
    cout << "p[0]->speak() = " << p[0]->speak() << endl;
    cout << "p[1]->speak() = " << p[1]->speak() << endl;
    // //! cout << "p[1]->sit() = "
    // //!      << p[1]->sit() << endl; // Illegal
}///:~