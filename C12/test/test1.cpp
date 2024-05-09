#include<iostream>
#include<cstring>
using namespace std;

class Int_set
{
    private:
        enum{sz = 10};
        int set[sz];
    public:
        Int_set(){memset(set, 0, sizeof(int)*sz);}
        ~Int_set(){}
        void setter(int index, int num){ set[index] = num;}
        void show();
        int& operator[](int index);
};

void Int_set::show()
{
    for(int i = 0; i < sz; i++)
    {
        cout << set[i] << " ";
    }
    cout << endl;
}

int& Int_set::operator[](int index)
{
    if(index < 0 || index > sz-1)
    {
        //
    }
    return sz[index];
}

int main()
{
    Int_set s;
    s.setter(0, 26);
    s.show();
    return 0;
}