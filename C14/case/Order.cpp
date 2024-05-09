//:C:14:Order.cpp
// Constructor / destructor order

#include<iostream>
#include<fstream>
using namespace std;
ofstream out("order.out");

#define CLASS(ID) class ID{\
public: \
    ID(int){ out << #ID " constructor\n";}\
    ~ID(){out << #ID" destructor\n";}\
};

CLASS(Base1);
CLASS(Member1);
CLASS(Member2);
CLASS(Member3);
CLASS(Member4);
CLASS(Member5);

class Derived1:public Base1
{
        Member1 m1;
        Member2 m2;
    public:
        Derived1(int):m1(1), m2(2), Base1(3){out << "Derived1 constructor\n";}
        ~Derived1(){out << "Derived1 destructor\n";}
};

class Derived2:public Derived1
{
        Member3 m3;
        Member4 m4;
    public:
        Derived2():m3(1), Derived1(2), m4(3){out << "Derived2 constructor\n";}
        ~Derived2(){out << "Derived2 destructor\n";}
};

// class Derived3:public Derived2
// {
//         Member4 m4;
//         Member5 m5;
//     public:
//         Derived3():Derived2(1), m4(2), m5(3){out << "Derived3 constructor\n";}
//         ~Derived3(){out << "Derived3 destructor\n";}
// };

int main()
{
    Derived2 d2;
    return 0;
}

// Base1->m1->m2->Derived1->m3->m4->Derived2->m4->m5->Derived3