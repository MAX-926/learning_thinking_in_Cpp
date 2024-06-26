//:C15:VarientReturn.cpp
// Returning a pointer or reference to a derived
// type during overloading
#include<iostream>
#include<string>
using namespace std;

class PetFood 
{
    public:
        virtual string foodType() const = 0;
};

class Pet
{
    public:
        virtual string type() const = 0;
        virtual PetFood* eats() = 0;
};

class Bird:public Pet
{
    public:
        string type() const { return "Bird";}
        class BirdFood:public PetFood
        {
            public:
                string foodType() const {return "Bird food";}
        };
        // Upcast to base type:
        PetFood* eats(){ return &bf;}
    private:
        BirdFood bf;
};

class Cat:public Pet
{
        // class CatFood:public PetFood
        // {
        //     public:
        //         string foodType() const {return "Birds";}
        // };
    public:
        string type() const { return "Cat";}
        class CatFood:public PetFood
        {
            public:
                string foodType() const {return "Birds";}
        };
        // Return exact type instead:
        CatFood* eats(){return &cf;}
    private:
        CatFood cf;
};

int main()
{
    // Bird b;
    // Cat c;
    // Pet* p[] = {&b, &c};
    // for(int i = 0; i < sizeof p / sizeof *p; i++)
    // {
    //     cout << p[i]->type() << " eats " << p[i]->eats()->foodType() << endl;
    // }
    // // Can return the exact type:
    // Cat::CatFood* cf = c.eats();
    // Bird::BirdFood* bf;
    // // Cannot return the exact type:
    // //! bf = b.eats();
    // // Must downcast:
    // bf = dynamic_cast<Bird::BirdFood*>(b.eats());

    Bird b, *bp = &b, &ba = b;
    Cat c, *cp = &c, &ca = c;
    // pointer
    // cout << bp->type() << endl << bp->eats()->foodType() << endl;
    // cout << cp->type() << endl << cp->eats()->foodType();
    // reference
    cout << ba.type() << endl << ba.eats()->foodType() << endl;
    cout << ca.type() << endl << ca.eats()->foodType();
    return 0;
} ///:~
