#include<iostream>
#include"../../C9/case/Stack4.h"
#include<fstream>
using namespace std;

ofstream out("13-7.out");

class Counted
{
    private:
        int id;
        static int count;
    public:
        Counted():id(count++)
        {
            out << "id: " << id << endl;
            out << "it's being created\n";
        }
        ~Counted()
        {
            out << "id: " << id << endl;
            out << "it's being destroyed\n";
        }
        void f(void){out << "some message\n";}
        friend ostream& operator<<(ostream& os, const Counted* c)
        {
            return os << "id: " << c->id << endl;
        }
};
int Counted::count = 0;

int main()
{
    Stack s;
    void* data;
    for(int i = 0; i < 26; i++)
    {
        s.push(new Counted);
        ((Counted*)s.peak())->f();
    }
    while(data = s.pop())
    {
        delete (Counted*)data;
    }
    return 0;
}