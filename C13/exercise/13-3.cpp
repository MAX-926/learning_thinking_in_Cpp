#include"../case/PStash.h"
#include<iostream>

using namespace std;

class Counted
{
    private:
        int id;
        static int count;
    public:
        Counted():id(count++)
        {
            cout << "id: " << id << endl;
            cout << "it's being created\n";
        }
        ~Counted()
        {
            cout << "id: " << id << endl;
            cout << "it's being destroyed\n";
        }
};
int Counted::count = 0;

int main()
{
    PStash countedStash;
    countedStash.add(new Counted);
    Counted* cp = (Counted*)countedStash.remove(0);
    // 在堆上创建的Counted 对象若超出范围，不调用delete则其析构函数不会被调用
    delete cp;
}