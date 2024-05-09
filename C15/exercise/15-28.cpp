class X
{
    public:
        virtual ~X(){/*cout << "~X()\n";*/}
};

class Y:public X{};

int main()
{
    Y y;
}