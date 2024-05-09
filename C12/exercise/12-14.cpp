#include<iostream>
#include<string>
using namespace std;

class Bird
{
    private:
        string m_str;
        static int s_i;
    public:
        Bird(){s_i++; m_str = "Bird #" + to_string(s_i);}
        Bird(const Bird& b){m_str = b.m_str;}
        // ~Bird(){}
        Bird& operator=(const Bird& b){m_str = b.m_str;return *this;}
        friend ostream& operator<<(ostream& os, const Bird& b){ return os << "b.m_str: " << b.m_str << endl;}
};

int Bird::s_i = 0;

// int main()
// {
//     Bird b1, b2, b3;
//     Bird b4 = b1;// copy-constructor
//     b2 = b1;// operator=
//     cout << b1 << b2 << b3 << b4;// operator<<
// }