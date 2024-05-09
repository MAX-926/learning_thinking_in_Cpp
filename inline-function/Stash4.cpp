//:C09:Stash4.cpp {o}
#include"Stash4.h"
#include<iostream>
#include<cassert>
using namespace std;

const int increase = 100;

int Stash::add(void* element)
{
    if(next >= quantity){inflate(increase); /*quantity += increase;*/}
    int startBytes = next * size;
    unsigned char* ep = (unsigned char*)element;
    for(int i = 0; i < size; i++)
    {
        storage[i + startBytes] = ep[i];
    }
    next++;
    return next-1;
}

void Stash::inflate(int increase)
{
    assert(increase >= 0);
    if(increase == 0) return;
    int newQuantity = quantity + increase;
    int oldBytes = quantity * size;//不是next*size,這樣不會做其他無意義的工作嗎？
    int newBytes = newQuantity * size;
    unsigned char* ns = new unsigned char[newBytes];
    for(int i = 0; i < oldBytes; i++)
    {
        ns[i] = storage[i];
    }
    delete []storage;
    storage = ns;
    quantity = newQuantity;
}///:~