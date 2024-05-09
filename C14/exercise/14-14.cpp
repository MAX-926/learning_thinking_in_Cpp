#include<iostream>
#include<string>
using namespace std;

class Traveler
{
        string inside;
    public:
        // constructor
        Traveler(string s):inside(s){}
        // copy-constructor
        Traveler(const Traveler& t){inside = t.inside;}
        // operator=
        Traveler& operator=(const Traveler& t){inside = t.inside; return *this;}

        // output inside
        void output(void){cout << inside << endl;}
};

class Pager
{
        string inside;
    public:
        Pager(string s):inside(s){}
        Pager(const Pager& p){inside = p.inside;}
        Pager& operator=(const Pager& p){inside = p.inside; return *this;}
        // output inside
        void output(void){cout << inside << endl;}
};

class BusinessTraveler:public Traveler
{
        Pager p_memmber;
    public:
        BusinessTraveler():Traveler("s"), p_memmber("p"){}
        BusinessTraveler(string s):Traveler(s), p_memmber(s){}
        BusinessTraveler(const BusinessTraveler& bt):Traveler(bt), p_memmber(bt.p_memmber){}
        BusinessTraveler& operator=(const BusinessTraveler& bt){Traveler::operator=(bt); p_memmber = bt.p_memmber; return *this;}
        // output inside data
        void output(void){cout << "p_member:" << endl; p_memmber.output(); cout << "Traveler:" << endl; Traveler::output();}
};

int main()
{
    BusinessTraveler bt;
    bt.output();
    BusinessTraveler bt1("MAX");
    bt1.output();
    bt = bt1;
    bt.output();
    BusinessTraveler bt2(bt1);
    bt2.output();
    return 0;
}