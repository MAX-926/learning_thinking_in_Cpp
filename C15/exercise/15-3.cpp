#include<iostream>
using namespace std;

class Shape
{
    public:
        Shape(){draw();}// 构造函数中不支持虚机制：类型信息不完全；析构函数中不支持虚机制：类型信息不可靠
        virtual ~Shape(){}
        virtual void draw() = 0;
};
void Shape::draw(){cout << "Shape::draw()\n";}

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
        // Square(){draw();}
        void draw(){cout << "Square::draw(){}\n";}
};

void func(Shape &s)
{
    s.draw();
}

int main()
{
    // Circle* c = new Circle; Square* s = new Square; Triangle* t = new Triangle;
    // Shape* sa[] = {c, s, t};
    // for(int i = 0; i < 3; i++)
    //     sa[i]->draw();
    // Shape s;
    Circle c;
    func(c);
    return 0;
}