//:C12:CopyVsInitialization.cpp
class Fi
{
    public:
        Fi(){}
};

class Fee
{
    public:
        Fee(int){}
        Fee(const Fi&){}
};

int main()
{
    //使用拷贝构造函数对新对象进行构造。
    //如果对象是新创建的，则调用拷贝构造函数；否则调用operator=。
    Fee fee = 1;// Fee(int)
    //Fee fee(1);
    Fi fi;
    Fee fum = fi;//Fee(Fi)
    //Fee fum(fi)
}///:~