#include<iostream>
using namespace std;

class Rodent
{
    public:
        virtual ~Rodent(){}
        virtual void eat()const = 0;
        virtual  void move()const = 0;
};

class Mouse:public Rodent
{
    public:
        void eat()const{cout << "Mouse::eat\n";}
        void move()const{cout << "Mouse::move\n";}
};

class Gerbil:public Rodent
{
    public:
        void eat()const{cout << "Gerbil::eat\n";}
        void move()const{cout << "Gerbil::move\n";}
};

class Hamster:public Rodent
{
    public:
        void eat()const{cout << "Hamster::eat\n";}
        void move()const{cout << "Hamster::move\n";}
};

void func(Rodent& r)
{
    r.eat();
    r.move();
}

int main()
{
    Rodent* ra[] = 
    {
        new Mouse,
        new Gerbil,
        new Hamster,
    };
    for(int i = 0; i < 3; i++)
    {
        ra[i]->eat();
        ra[i]->move();
    }
}