//:C09:ErrTest.cpp
//{T} ErrTest.cpp
// Testing require.h
#include"require.h"
#include<fstream>
using namespace std;

int main(int argc, char* argv[])
{
    int i = 1;
    require(i, "Value must be nonzero");
    requireArgs(argc, 1);
    requireMinArgs(argc, 1);
    ifstream in(argv[1]);
    assure(in, argv[1]);
    ifstream nofile("nofile.xxx");
    ofstream out("tmp.xxx");
    assure(out);
}