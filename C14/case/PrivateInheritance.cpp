//:C14:PrivateInheritance.cpp
#include<iostream>
using namespace std;

class Pet
{
    private:
        void pri(){cout << "i am Pet::pri()" << endl;}
    public:
        char eat()const{cout << "Pet::eat()" << endl; return 'a';}
        int speak()const{return 2;}
        float sleep()const{return 3.0;}
        float sleep(int)const{return 4.0;}
};

class Goldfish: Pet // Private Inheritance
{
    public:
        // using Pet::pri;// using GroundClass::func_in_public;這個語句可以將私有繼承自基類的public函數在派生類中變得可見可用。
        using Pet::eat;// Name publicizes member
        using Pet::sleep;// Both members exposed
};

int main()
{
    Goldfish bob;
    bob.eat();
    bob.sleep();
    bob.sleep(1);
    //! bob.speak();// Error: private member function
}///:~