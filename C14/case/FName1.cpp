//:C14:FName1.cpp
// An fstream with a file name
#include<iostream>
#include<fstream>
#include<string>
#include"../../Require.h"
using namespace std;

class FName1
{
    private:
        ifstream file;
        string fileName;
        bool named;
    public:
        FName1():named(false){}
        FName1(const string& fname):file(fname.c_str()), fileName(fname){assure(file, fileName); named = true;}
        string name() const {return fileName;}
        void name(const string& newName)
        {
            if(named) return;
            fileName = newName;
            named = true;
        }
        operator ifstream&(){return file;}
};

int main()
{
    FName1 file("FName1.cpp");
    cout << file.name() << endl;
    // Error: close() not a member
   //! file.close() 類型轉換不會發生！！！
}///:~