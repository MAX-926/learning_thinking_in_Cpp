//:C15:StaticHierarchyNavigations.cpp
#include<iostream>
#include<typeinfo>
#include<cassert>
using namespace std;

class Shape{public: virtual ~Shape(){}};
class Circle:public Shape{};
class Square:public Shape{};
class Other{};
int main()
{
    Circle c;
    Shape* s = &c;// Upcast: normal and OK
    // More explicit but necessary:
    s = static_cast<Shape*>(&c);
    // (Since upcasting is such a safe and common
    // operation, the cast becomes cluttering!
    Circle* cp = 0;
    Square* sp = 0;
    // Static Navigation of class hierarchies
    // requires extra type information:
    if(typeid(s) == typeid(cp)) // C++ RTTI
        cp = static_cast<Circle*>(s);
    if(typeid(s) == typeid(sp))
        sp = static_cast<Square*>(s);
    if(cp != 0)
        cout << "It's a Circle!" << endl;
    if(sp != 0)
        cout << "It's a Square!" << endl;
    // Static navigation is ONLY an efficiency hack;
    // dynamic_cast is always safer. However:
    // Conveniently gives an error message, while
    Other* op2 = (Other*)s;
    // assert(*op2 == *s);
    // assert(op2 == 0);
    // Other* op3 = dynamic_cast<Other*>(s);
    // assert(op3 != 0);
    // does not
} ///:~