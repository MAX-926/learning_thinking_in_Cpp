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
    // // 栈上测试
    // Counted c1, c2;
    // // 堆上测试
    // Counted *cp1, *cp2;
    // cp1 = new Counted;
    // cp2 = new Counted;
    // delete cp2;
    // delete cp1;
    Counted* pa;
    pa = new Counted[2];
    delete []pa;
}
