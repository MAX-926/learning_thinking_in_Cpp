#include<iostream>
using namespace std;

class Matrix;
class Tensor;

class Math
{
    public:
        virtual ~Math(){}
        virtual Math& operator+(Math&) = 0;
        virtual Math& add(Matrix*) = 0;
        virtual Math& add(Tensor*) = 0;
};


class Matrix:public Math
{
    public:
        Math& operator+(Math& rv){return rv.add(this);}
        Math& add(Matrix*){cout << "Matrix + Matrix\n"; return *this;}
        Math& add(Tensor*){cout << "Matrix + Tensor\n"; return *this;}
};

class Tensor:public Math
{
    public:
        Math& operator+(Math& rv){return rv.add(this);}
        Math& add(Matrix*){cout << "Tensor + Matrix\n"; return *this;}
        Math& add(Tensor*){cout << "Tensor + Tensor\n"; return *this;}
};

int main()
{
    Tensor t;
    Matrix m;
    Math* ma[] = {&t, &m};
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            *ma[i] + *ma[j];
        }
    }
}