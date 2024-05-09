#include<iostream>
using namespace std;

class Shape
{
    public:
        virtual ~Shape(){}
        virtual void draw(){cout << "Shape::draw()\n";}
};
// void Shape::draw(){cout << "Shape::draw()\n";}

class Circle:public Shape
{
    public:
        void draw(){cout << "Circle::draw()\n";}
};

class Triangle:public Shape
{
    public:
        void draw(){cout << "Triangle::draw(){}\n";}
};

class Square:public Shape
{
    public:
        void draw(){cout << "Square::draw(){}\n";}
};

int main()
{
    Circle* c = new Circle; Square* s = new Square; Triangle* t = new Triangle;
    Shape* sa[] = {c, s, t};
    for(int i = 0; i < 3; i++)
        sa[i]->draw();
    return 0;
}