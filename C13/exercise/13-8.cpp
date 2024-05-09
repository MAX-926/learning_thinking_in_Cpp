#include<iostream>
#include<fstream>
using namespace std;

ofstream out("13-8.out");

class Counted
{
    private:
        int id;
        static int count;
    public:
        Counted():id(count++)
        {
            out << "id: " << id << endl;
            out << "it's being created\n";
        }
        ~Counted()
        {
            out << "id: " << id << endl;
            out << "it's being destroyed\n";
        }
        void f(void){out << "some message\n";}
        friend ostream& operator<<(ostream& os, const Counted* c)
        {
            return os << "id: " << c->id << endl;
        }
};
int Counted::count = 0;

int main()
{
    Counted* ca = new Counted[26];
    delete ca;// 其语法意义是释放ca所指内存，而ca是一个Counted对象的地址，不加方括号无法正确释放这里的对象数组所占用的内存
    // delete []ca;
    return 0;
}