//:C:13:ArrayOperatorNew.cpp
// Operator new for arrays
#include<new>
#include<fstream>
using namespace std;
ofstream trace("ArrayOperatorNew.out");

class Widget
{
        enum{sz = 10};
        int i[sz];
    public:
        Widget(){trace << "*";}
        ~Widget(){trace << "~";}
        void* operator new(size_t sz)
        {
            trace << "Widget::new: " << sz << " bytes" << endl;
            return ::new char[sz];
        }
        void operator delete(void* p)
        {
            trace << "Widget::delete" << endl;
            ::delete []p;
        }
        void* operator new[](size_t sz)// sz即为待创建的对象数据所占用的字节数
        {
            trace << "Widget::new[]: " << sz << " bytes" << endl;
            return ::new char[sz]; 
        }
        void operator delete[](void* p)
        {
            trace << "Widget::delete[]" << endl;
            ::delete []p;
        }
};

int main()
{
    trace << "new Widget " << endl;
    Widget* w = new Widget;// 调用类的operator new
    trace << "\ndelete Widget" << endl;
    delete w;// 调用类的operator delete
    trace << "\nnew Widget[25]" << endl;
    Widget* wa = new Widget[25];
    trace << "\ndelete []Widget" << endl;
    delete []wa;
}///:~