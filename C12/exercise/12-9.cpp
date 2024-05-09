#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

//stringstreams, fstream/ cin, cout

class Simple
{
    private:
        char member;
    public:
        Simple(char m = 'm'):member(m){}
        ~Simple(){}
        friend ostream& operator<<(ostream& os, const Simple& s){return os << "Simple.memner: " << s.member << endl;}
        friend istream& operator>>(istream& is, Simple& s){is >> s.member;return is;}
};

int main()
{
    Simple s;
    cin >> s;
    cout << s;
}

