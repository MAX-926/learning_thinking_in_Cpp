//:C:13:ArrayOperatorNew.cpp
// Operator new for arrays
#include<new>
#include<fstream>
#include<vector>
using namespace std;
ofstream trace("ArrayOperatorNew.out");

class Widget
{
        enum{sz = 10};
        int i[sz];
        // int o_i;
        // static int index;
        static vector<Widget*> addr_w;
    public:
        class MemoryChecker;
        friend MemoryChecker;
        class MemoryChecker
        {    
            public:
            ~MemoryChecker()
            {
                trace << endl << "Widget::addr_w中的指针数目: " << addr_w.size() << endl;
            }
        };
        Widget(){trace << "*";}
        ~Widget(){trace << "~";}
        void* operator new(size_t sz)
        {
            trace << "Widget::new: " << sz << " bytes" << endl;
            void *tp = ::new char[sz];
            addr_w.push_back((Widget*)tp);
            // index++;
            // ((Widget*)tp)->o_i = index;
            return tp;
        }
        void operator delete(void* p)
        {
            trace << "Widget::delete" << endl;
            int i = 0;
            while(((Widget*)p) !=  addr_w[i])
            {
                i++;
            }
            addr_w.erase(addr_w.begin()+i);
            ::delete p;
        }
        void* operator new[](size_t sz)// sz即为待创建的对象数据所占用的字节数
        {
            trace << "Widget::new[]: " << sz << " bytes" << endl;
            void *tp = ::new char[sz];
            addr_w.push_back((Widget*)tp);
            // index++;
            // ((Widget*)tp)->o_i = index;
            return tp;
        }
        void operator delete[](void* p)
        {
            trace << "Widget::delete[]" << endl;
            int i = 0;
            while(((Widget*)p) !=  addr_w[i])
            {
                i++;
            }
            addr_w.erase(addr_w.begin()+i);
            ::delete []p;
        }
};
vector<Widget*> Widget::addr_w;
// int Widget::index = 0;

int main()
{
    // trace << "new Widget " << endl;
    // Widget* w = new Widget;// 调用类的operator new
    // trace << "\ndelete Widget" << endl;
    // delete w;// 调用类的operator delete
    // trace << "\nnew Widget[25]" << endl;
    // Widget* wa = new Widget[25];
    // trace << "\ndelete []Widget" << endl;
    // delete []wa;
    Widget* wp = new Widget;
    Widget* wpa = new Widget[26];
    Widget::MemoryChecker m;// 用友元类管理指针数组
    delete wp;
    delete []wpa;
}///:~