// #include<iostream>
// using namespace std;

// class Type
// {
//     private:
//         double i;
//     public:
//         Type(){cout << "Type-default-constructor\n";}
//         Type(const Type& t):i(t.i){cout << "Type-copy-constructor\n";}
//         Type(double ii):i(ii){cout << "Type-constructor\n";}
//         ~Type(){cout << "Type-destructor\n";}
//         void get_i()const{cout << "Type i:" << i << endl;}
//         // operator Simple(){}
// };

// class Simple:public Type
// {
//     private:
//         int i;
//     public:
//         Simple():Type(26){cout << "Simple-default constructor\n";}
//         Simple(int ii):i(ii), Type(26){cout << "Simple-arg-constructor\n";}
//         Simple(const Simple& s):i(s.i), Type(s){cout << "Simple-copy-constructor\n";}
//         ~Simple(){cout << "Simple-destructor\n";}
//         friend ostream& operator<<(ostream&, const Simple&);
// };

// ostream& operator<<(ostream& os, const Simple& s)
// {
//     s.get_i();
//     return os << "Simple:i " << s.i << '\n';
// }

// int main()
// {
//     Simple s(1);
//     Simple& so = s;
//     Simple s1 = so;
//     cout << s1;
//     return 0;
// }

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

// int main()
// {
//     ifstream in("./C_Language/fwo.txt");
//     string line;
//     while(getline(in, line))
//     {
//         cout << line << endl;
//     }

//     return 0;
// }

// int* const p = new int[10];

class E
{
    private:
        static int i;
    public:
        E(){}
        ~E(){}
        void show(){cout << i;}
        void add(){i++;}
        static void show_i(){cout << i << endl;}
};
int E::i = 1;
int main()
{
    E e1, e2;
    // e1.show();
    // cout << endl;
    // e2.show();
    // e1.add();
    // e1.show();
    // cout << endl;
    // e2.show();
    return 0;
}