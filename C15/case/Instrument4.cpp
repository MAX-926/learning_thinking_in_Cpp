// Instrument4.cpp
//Extensibility in OOP
#include<iostream>
using namespace std;
enum note{middleC, Csharp, Cflat}; //etc

class Instrument
{
    public:
        virtual void play(note) const {cout << "Instrument::play\n";}
        virtual char* what() const {return "Instrument";}
        // Assume this will modify the object:
        virtual void adjust(int){}
};

class Wind:public Instrument
{
    public:
        void play(note) const {cout << "Wind::play\n";}
        char* what() const {return "Wind\n";}
        void adjust(int){cout << "Wind::adjust(int)\n";}
};

class Percussion:public Instrument
{
    public:
        void play(note) const {cout << "Percussion::play\n";}
        char* what() const {return "Percussion\n";}
        void adjust(int){}
};

class Stringed:public Instrument
{
    public:
        void play(note) const {cout << "Stringed::play\n";}
        char* what() const {return "Stringed\n";}
        void adjust(int){}
};

class Brass:public Wind
{
    public:
        void play(note) const {cout << "Brass::play\n";}
        char* what() const {return "Brass\n";}
};

class Woodwind:public Wind
{
    public:
        void play(note) const {cout << "Woodwind::play\n";}
        char* what() const {return "Woodwind\n";}
};

// Identical function from before:
void tune(Instrument& i)
{
    // ...
    i.play(middleC);
}

// New function:
void f(Instrument& i)
{
    i.adjust(1);
}

// Upcasting during array initialization:
Instrument* A[] = 
{
    new Wind,
    new Percussion,
    new Stringed,
    new Brass
};

int main()
{
    Wind flute;
    Percussion drum;
    Stringed violin;
    Brass flugelhorn;
    Woodwind recorder;
    tune(flute);
    tune(drum);
    tune(violin);
    tune(flugelhorn);
    tune(recorder);
    f(flugelhorn);// 进行多态调用时， 编译器总是保证有函数体与调用对应。这里选择“最近”的（即brass的父类wind的adjust函数体）。
}///:~