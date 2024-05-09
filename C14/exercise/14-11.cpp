#include<iostream>
#include"../../C13/case/PStash.h"
using namespace std;

class Asteroid:public PStash
{
    public:
        int add(Asteroid*);
        Asteroid* operator[](int);
};

int Asteroid::add(Asteroid* element)
{
    // check as if there is enough spcae
    return PStash::add(element);
}

Asteroid* Asteroid::operator[](int index)
{
    return (Asteroid*)PStash::operator[](index);
}
