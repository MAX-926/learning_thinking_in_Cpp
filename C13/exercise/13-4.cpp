#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

const int length = 26;

ofstream out("13-4.out");

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
        friend ostream& operator<<(ostream& os, const Counted* c)
        {
            return os << "id: " << c->id << endl;
        }
};
int Counted::count = 0;

int main()
{
    vector<Counted*> vc;
    Counted* p = 0;
    for(int i = 0; i < length; i++)
    {
        vc.push_back(new Counted);
    }
    for(int i = 0; i < length; i++)
    {
        out << vc[i];
    }
    for(int i = 0; i < length; i++)
    {
        p = vc[i];
        delete p;
    }
    return 0;
}