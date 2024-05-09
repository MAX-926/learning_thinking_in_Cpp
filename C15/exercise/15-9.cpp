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

class BlueHamster:public Hamster
{
    // public:
        ~BlueHamster(){cout << "Deleting BlueHamster\n";}
        void eat()const{cout << "BlueHamster::eat\n";}
        void move()const{cout << "BlueHamster::move\n";}
};

void func(Rodent& r)
{
    r.eat();
    r.move();
}

int main()
{
    Rodent* rp = new BlueHamster;
    rp->eat();
    rp->move();
    delete rp;
    // 堆中的数据不收访问控制管理：因为堆中的数据在运行时建立，此时已没有访问控制的信息了

    // delete rp;
    // BlueHamster bh;
    // bh.eat();
    // bh.move();
}