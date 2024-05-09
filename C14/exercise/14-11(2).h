#include<iostream>
#include"../../C13/case/PStash.h"
using namespace std;

class Asteroid
{
    private:
        PStash ps;
    public:
        Asteroid():ps(){}
        ~Asteroid(){}
        int add(Asteroid* element){ps.add(element);}
        Asteroid* operator[](int index){return (Asteroid*)ps[index];}
        void* remove(int index){return ps.remove(index);}
};

// int Asteroid::add(Asteroid* element)
// {
//     // check as if there is enough spcae
//     return PStash::add(element);
// }

// Asteroid* Asteroid::operator[](int index)
// {
//     return (Asteroid*)PStash::operator[](index);
// }
