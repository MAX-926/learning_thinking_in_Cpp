//:C16:TPstash.h
#ifndef TPSTASH_H
#define TPSTASH_H

#include"../../Require.h"
#include<cstring>
// using namespace std;

template<class T, int incre = 10>
class PStash
{
        int quantity;
        int next;
        T** storage;
        void inflate(int increase = incre);
    public:
        PStash():quantity(0), next(0), storage(0){}
        ~PStash();
        int add(T* element);
        T* operator[](int index)const;
        // Remove the reference from this PStash:
        T* remove(int index);
        // Number of element in Stash:
        int count()const{return next;}
};
template<class T, int incre>
int PStash<T, incre>::add(T* element)
{
    if(next >= quantity) inflate(incre);
    storage[next++] = element;
    return next - 1;// Index number
}

// Ownership of remaining pointers:
template<class T, int incre>
PStash<T, incre>::~PStash()
{
    for(int i = 0; i < next; i++)
    {
        if(storage[i]) delete storage[i];// Null pointers OK
        storage[i] = 0;// Just to be safe
    }
    delete []storage;
}

template<class T, int incre>
T* PStash<T, incre>::operator[](int index)const
{
    // if(index < 0 || index >= next) return 0;
    // return storage[next];
    require(index >= 0, "PStash::operator[] index negative");
    if(index >= next) return 0;// To indicate the end
    require(storage[index] != 0, "PStash::operator[] returned null pointer");
    // Produce pointer to desired element:
    return storage[index];
}

template<class T, int incre>
T* PStash<T, incre>::remove(int index)
{
    // Operator[] perform validity checks:
    T* result = this->operator[](index);
    // "Remove" the pointer:
    // delete storage[index];
    if(result != 0) storage[index] = 0;
    return result;
}

template<class T, int incre>
void PStash<T, incre>::inflate(int increase)
{
    const int psz = sizeof(T*);
    T** ns = new T*[quantity + increase];
    memset(ns, 0, psz*(increase+quantity));
    memcpy(ns, storage, quantity*psz);
    // for(int i = 0; i < next; i++)
    //     ns[i] = storage[i];
    delete []storage;// Old storage
    storage = ns;// Point to new memory
    quantity = quantity + increase;
}
#endif // TPSTASH_H