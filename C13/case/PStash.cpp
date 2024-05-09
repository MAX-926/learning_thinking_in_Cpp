//:C:13:PStash.cpp {O}
// Pointer Stash definitions
#include"PStash.h"
#include"../../Require.h"
#include<iostream>
#include<cstring> // 'mem' functions
using namespace std;

void PStash::inflate(int increase)
{
    const int psz = sizeof(void*);
    void** st = new void*[increase + quantity];
    // for(int i = 0; i < quantity; i++)
    //     st[i] = storage[i];
    memset(st, 0, psz*(increase + quantity));
    memcpy(st, storage, quantity * psz);
    quantity += increase;
    delete []storage;// Old storage
    storage = st;// Point to new memory
}///:~

PStash::~PStash()
{
    for(int i = 0; i < next; i++)
        require(storage[i] == 0, "PStash not cleaned up\n");
    delete []storage;
}

// 函數返回添加的元素的索引
int PStash::add(void* element)
{
    const int inflateSize = 100;
    // check as if there is enough space to store new element
    if(quantity <= next) inflate(inflateSize);// 下一個可用空間超出已有索引範圍
    storage[next++] = element;
    return (next-1);// index number
}

// Operator overloading replacement for fetch
void* PStash::operator[](int index) const
{
    require(index >= 0, "PStash::operator[] index negative");
    if(index >= next) return 0;// to indicate the end
    // Produce pointer to desired element
    return storage[index];
}

void* PStash::remove(int index)
{
    void* v = operator[](index);// 先尝试取出指针，若索引出界，则会启动错误提示
    // "Remove" the pointer:
    if(v != 0) storage[index] = 0;
    return v;
}