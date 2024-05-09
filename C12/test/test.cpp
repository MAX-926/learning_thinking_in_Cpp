#include<iostream>
#include<sstream>
#include<cstring>
using namespace std;

class MAX
{
    private:
        enum{sz = 2};
        int aha[sz];
        int age;
        char sex;
    public:
        MAX(int age_i, char sex_i):age(age_i), sex(sex_i){memset(aha, 0, sizeof(int)*sz);}
        ~MAX(){}
        friend ostream& operator<<(ostream& os, const MAX& m)
        {
            for(int i = 0; i < m.sz; i++)
            {
                if(i == 0) os << "aha: ";
                os << m.aha[i] << " ";
                if(i == 1) os << endl;
            }
            os << "age: " << m.age << endl << "sex: " << m.sex << endl;
            return os;
        }
        friend istream& operator>>(istream& is, MAX& m);
};

istream& operator>>(istream& is, MAX& m)
{
    for(int i = 0; i < m.sz; i++)
    {
        is >> m.aha[i];
    }
    is >> m.age >> m.sex;
    return is;
}

int main(void)
{
    MAX m(23, 'm');
    cout << m;
    stringstream input("25 26 30s");//自己会检查input string流的内容以正确赋值？
    input >> m;
    cout << m;
    return 0;
}