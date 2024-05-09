    //:C14:Car.cpp
// Public composition
#include<iostream>

class Engine
{
    public:
        void start() const {}
        void rev() const {}
        void stop() const {}
};

class Wheel
{
    public:
        void inflate(int psi) const {}
};

class Window
{
    public:
        void rollup() const {}
        void rolldown() const {}
};

class Door
{
    public:
        Window window;
        void open() const {}
        void close() const {}
};

class Car:public Vehicle
{
    public:
        Engine engine;
        Wheel wheel[4];
        Door left, right;// 2-door
        Car():Vehicle(1){}
};

class Vehicle
{
    public:
        Vehicle(int ii){std::cout << "this is Vehicle(int)\n";}
        void func1(){std::cout << "this is func1()\n";}
        void func2(){std::cout << "this is func2()\n";}
};

int main()
{
    Car car;
    car.left.window.rollup();
    car.wheel[0].inflate(72);
}///:~
