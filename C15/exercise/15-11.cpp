#include<iostream>
#include<vector>
using namespace std;

class Aircraft
{
    public:
        virtual ~Aircraft() = 0;
        virtual const char* what()const = 0;
        virtual void take_off() = 0;
        virtual void landing() = 0;
};
Aircraft::~Aircraft(){}

class Helicopter:public Aircraft
{
    public:
        const char* what()const{return "Helicppter";}
        void take_off(){cout << "Helicopter take off!\n";}
        void landing(){cout << "Helicopter landing!\n";}
        ~Helicopter(){cout << "Destroy helicopter\n";}
};

class Plane:public Aircraft
{
    public:
        const char* what()const{return "Plane";}
        void take_off(){cout << "Plane take off!\n";}
        void landing(){cout << "Plane landing!\n";}
        ~Plane(){cout << "Destroy Plane\n";}
};

class Bomber:public Aircraft
{
    public:
        const char* what()const{return "Bomber";}
        void take_off(){cout << "Bomber take off!\n";}
        void landing(){cout << "Bomber landing!\n";}
        ~Bomber(){cout << "Destroy Bomber\n";}
};

int main()
{
    vector<Aircraft*> Tower;
    Tower.push_back(new Helicopter);
    Tower.push_back(new Bomber);
    Tower.push_back(new Plane);
    for(int i = 0; i < 3; i++)
    {
        Tower[i]->what();
        Tower[i]->take_off();
        Tower[i]->landing();
        delete Tower[i];
        Tower.pop_back();
    }
    return 0;
}