#include<iostream>
using namespace std;


// 温室的功能：
// 1。控制温度 2.控制光照 3.控制水源

class Plant
{
    private:
    public:
        enum status{dry, normal, wet} st;
        Plant():st(normal){}
        virtual const char* what()const = 0;
        status& get_status(){return st;}
        virtual void grow_up() = 0;
        virtual void show_status()const = 0;
        virtual ~Plant(){}
};

class Rose:public Plant
{
    private:
        double age;
    public:
        Rose():Plant(), age(0){}
        void show_status()const
        {
            switch(st)
            {
                case 0:cout << "dry\n";break;
                case 1:cout << "normal\n";break;
                case 2:cout << "wet\n";
            }
            return;
        }
        const char* what()const{return "Rose";}
        void grow_up(){age++;get_status() = dry;}
        ~Rose(){cout << "Deleting a Rose\n";}
};

int main()
{
    Plant* homes[] = {new Rose, new Rose};
    cout << homes[0]->what();
    homes[0]->grow_up();
    homes[0]->show_status();
    cout << endl;
    cout << homes[1]->what();
    homes[1]->show_status();
    return 0;
}