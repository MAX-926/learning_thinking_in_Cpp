//:C14:FName2.cpp
// Subtyping solves the problem
#include"../../Require.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class FName2:public ifstream
{
    private:
        string fileName;
        bool named;
    public:
        FName2():named(false){}
        FName2(const string& fname):fileName(fname), ifstream(fname.c_str())
        {
            assure(*this, fileName);
            named = true;
        }
        string name() const {return fileName;}
        void name(const string& newName){if(named) return;/*don't overwrite*/ fileName = newName; named = true;}
};

int main()
{
    FName2 file("FName2.cpp");
    assure(file, "FName2.cpp");
    cout << "name: " << file.name() << endl;
    // string s;
    // getline(file, s);// These works too!
    // file.seekg(-200, ios::end);
    file.close();
}///:~
// 使用繼承的方式，相當於在爲父類擴展新的功能
// 使用組合，則希望使用該對象的某些功能