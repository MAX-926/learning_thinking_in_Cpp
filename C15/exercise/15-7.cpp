#include<iostream>
#include<vector>
using namespace std;

class Rodent
{
    public:
        virtual ~Rodent(){cout << "Deleting Rodent\n";}
        virtual void eat()const = 0;
        virtual  void move()const = 0;
};

class Mouse:public Rodent
{
    public:
        void eat()const{cout << "Mouse::eat\n";}
        void move()const{cout << "Mouse::move\n";}
        ~Mouse(){cout << "Deleting Mouse\n";}
};

class Gerbil:public Rodent
{
    public:
        void eat()const{cout << "Gerbil::eat\n";}
        void move()const{cout << "Gerbil::move\n";}
        ~Gerbil(){cout << "Deleting Gerbil\n";}
};

class Hamster:public Rodent
{
    public:
        void eat()const{cout << "Hamster::eat\n";}
        void move()const{cout << "Hamster::move\n";}
        ~Hamster(){cout << "Deleting Hamster\n";}
};

void func(Rodent& r)
{
    r.eat();
    r.move();
}

int main()
{
    // Rodent* ra[] = 
    // {
    //     new Mouse,
    //     new Gerbil,
    //     new Hamster,
    // };
    vector<Rodent*> ra;
    ra.push_back(new Mouse);    
    ra.push_back(new Gerbil);    
    ra.push_back(new Hamster);    
    for(int i = 0; i < 3; i++)
    {
        ra[i]->eat();
        ra[i]->move();
        delete ra[i];
        ra.pop_back();
    }
}