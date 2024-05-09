//:C:13:GlobalOperatorNew.cpp
// Overload global new/delete
#include<cstdio>
#include<cstdlib>

// 不使用iostream(诸如cin, cout, cerr...)，是因为它们的实现表示，需要调用new去分配内存，这会导致死锁发生。（重载new后，旧的实现无法使用）

void* operator new(size_t sz)
{
    printf("operator new: %d Bytes\n", sz);
    void* m = malloc(sz);
    if(!m) puts("out of memory");
    return m;
}

void operator delete(void* m)
{
    puts("operator delete");
    free(m);
}

class S
{
    private:
        int i[100];
    public:
        S(){puts("S::S()");}
        ~S(){puts("S::~S()");}
};

int main()
{
    puts("Creating & destroying an int");
    int* p = new int(47);
    delete p;
    puts("Creating & destroying an S");
    S* s = new S;
    delete s;
    puts("Creating & destroying S[3]");
    S* sa = new S[3];
    delete []sa;
}///:~