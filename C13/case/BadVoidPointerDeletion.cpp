//:C:13:BadVoidPointerDeletion.cpp
// Deleting void pointers can cause memory leadks
#include<iostream>

using namespace std;

class Object
{
    private:
        void* data;
        const int size;
        const char id;
    public:
        Object(int, char);
        ~Object();

};
Object::Object(int sz, char c):size(sz), id(c)
{
    data = new char[size];
    cout << "constructong object " << id << ", size = " << size << endl;
}
Object::~Object()
{
    cout << "destructing object " << id << endl;
    delete []data; //delete一個void指針，則只會釋放void指針指向的那塊内存。能夠正確回收内存的原因在於：data所指向的對象足夠簡單（只有一級）
}

int main(void)
{
    Object* a = new Object(40, 'a');
    delete a;
    void* b = new Object(40, 'b');
    delete b;// b，无法通过delete调用其析构函数
    return 0;
}