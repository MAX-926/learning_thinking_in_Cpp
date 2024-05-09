#include<iostream>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<fstream>
using namespace std;

class Pos_new
{
    private:
        enum{sz = 100};
        int array[sz];// place holder
        static vector<string> vs; 
    public:
        Pos_new(){memset(array, 0, sz);}
        ~Pos_new(){}
        void* operator new(size_t sz, string s)
        {
            vs.push_back(s);
            return malloc(sz);
        }
        void print(void)
        {
            ofstream os("13-14.out");
            os << vs[0];
        }

};
vector<string> Pos_new::vs;
int main()
{
    Pos_new* pp = new("first try") Pos_new;
    pp->print();
}