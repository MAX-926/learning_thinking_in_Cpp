//:C09:Stash4.h
// Inline funtions
#ifndef STASH4_H
#define STASH4_H
#include<cassert>

class Stash
{
    private:
        int size; // size of each space
        int quantity;// number of storage spaces
        int next;// next empty space
        // dynamically allocated array of bytes
        unsigned char* storage;
        void inflate(int increase);
    public:
        Stash(int sz):size(sz), quantity(0), next(0), storage(0){}
        Stash(int sz, int initQuantity):size(sz), quantity(initQuantity), next(0), storage(0){inflate(initQuantity);}
        ~Stash(){if(storage != 0) delete []storage;}
        int count()const { return next;}
        void* fetch(int index)const
        {
            assert(index >= 0);
            if(index >= next){return 0;}
            return &(storage[index * size]);
        }
        int add(void* element);
};
#endif //STASH4_H ///:~