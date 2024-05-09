//:C:13:NewHandler.cpp
// Changing the new-handler
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<new>

using namespace std;

ofstream out("NewHandler.out");

int count = 0;

void out_of_memory()
{
    cerr << "memory exhausted after " << count << " allocations!" << endl;
    exit(1);
}


int main()
{
    set_new_handler(out_of_memory);
    while(1)
    {
        count++;
        new int[1000];// Exhausted memory
        out << "count: " << count << endl;
    }
}///:~

// Result: 14.126928 GB
