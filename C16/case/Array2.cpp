//:C16:Array2.cpp
// Non-inline template definition
#include"../../Require.h"
template<class T>
class Array
{
        enum{size = 100};
        T A[size];
    public:
        T& operator[](int index);
};

template<class T>
T& Array<T>::operator[](int index)
{
    require(index >= 0 && index < 100, "Index out of range")
    {
        return A[index];
    }
}

int main()
{
    Array<float> fa;
    fa[0] = 1.414;
}///:~
