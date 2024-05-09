#include<iostream>
using namespace std;

class Pointer
{
    private:
        void* ptr;
    public:
        Pointer(void* init_ptr):ptr(init_ptr){}
        ~Pointer(){}
        // 定义自己的operator=，解决编译器生成的operator=使得同一块存储区域，有不同的别名的问题。（？）
        Pointer& operator=(const Pointer& p)
        {
            //检查自赋值
            if(this !=  &p)
            {
                ptr = p.ptr;
                return *this;
            }
        }
        friend ostream& operator<<(ostream& os, const Pointer& p){return os << "ptr: " << p.ptr << endl;}
};

int main()
{
    int i = 0;
    Pointer p1(&i);
    Pointer p2 = p1;
    cout << p1 << p2;
}