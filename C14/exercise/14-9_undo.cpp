#include<vector>
using namespace std;

class stringVector:vector<void*>
{
    public:
        void push_back(){}
        void* operator[](int){return }
};

int main()
{
    return 0;
}