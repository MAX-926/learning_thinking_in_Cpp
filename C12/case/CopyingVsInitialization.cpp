//:C12:CopyingVsInitializaion.cpp
class Fi{};

class Fee
{
    public:
        Fee(int){}
        Fee(const Fi&){}
};

class Fo
{
        int i;
    public:
        Fo(int x = 0):i(x){}
        operator Fee()const{return Fee(i);}
};

int main()
{
    Fo fo;
    Fee fee = fo;// 编译器创建一个从fee到fee的拷贝构造函数（因为是创建新的对象，所以不是operator=()）
}///:~