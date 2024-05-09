//:C12:PointerToMemberOperator.cpp
#include<iostream>
using namespace std;

class Dog
{
    public:
        int run(int i)const
        {
            cout << "run\n";
            return i;
        }
        int eat(int i)const
        {
            cout << "eat\n";
            return i;
        }
        int sleep(int i)const
        {
            cout << "sleep\n";
            return i;
        }
        typedef int (Dog::*PMF)(int) const;
        // operator->* must return an object
        // that has an operator():
        class FunctionObject
        {
            private:
                Dog* ptr;
                PMF pmem;
            public:
                // Save the object pointer and member pointer
                FunctionObject(Dog* wp, PMF pm):ptr(wp), pmem(pm)
                {
                    cout << "FunctionObject constructor\n";
                }
                // Make the call using the object pointer
                // and member pointer
                int operator()(int i) const
                {
                    cout << "FunctionObject::operator()\n";
                    return (ptr->*pmem)(i); // Make the call
                }
        };
        FunctionObject operator->*(PMF pmf)
        {
            cout << "operator->*" << endl;
            return FunctionObject(this, pmf);
        }          
};
// class MAX;
// class MAX
// {
//     private:
//         int i;
//     public:
//         int change(int ii){i = ii;}
// };

// typedef int (MAX::*pointer)(int);

// int main()
// {
//     MAX m;
//     pointer p = &MAX::change;
//     cout << m.p(2);
// }

int main()
{
    Dog w;
    Dog::PMF pmf = &Dog::run;
    cout << (w->*pmf)(1) << endl;
    pmf = &Dog::sleep;
    cout << (w->*pmf)(2) << endl;
    pmf = &Dog::eat;
    cout << (w->*pmf)(3) << endl;
}///:~

