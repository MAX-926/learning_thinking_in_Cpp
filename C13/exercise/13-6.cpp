#include<iostream>
#include<vector>
#include<fstream>
#include"../case/PStash.h"

using namespace std;

const int length = 26;

ofstream out("13-6.out");

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
    // vector<Counted*> vc;
    // Counted* p = 0;
    // for(int i = 0; i < length; i++)
    // {
    //     vc.push_back(new Counted);
    // }
    // for(int i = 0; i < length; i++)
    // {
    //     out << vc[i];
    // }
    // for(int i = 0; i < length; i++)
    // {
    //     p = vc[i];
    //     p->f();
    //     delete p;
    // }

    PStash countedStash;
    for(int i = 0; i < 26; i++)
    {
        countedStash.add(new Counted);
        ((Counted*)countedStash[i])->f();
    }
    int i = 0;
    while(i < 26)
    {
        Counted* tp = (Counted*)countedStash.remove(i);
        delete tp;
        i++;
    }
    return 0;
}