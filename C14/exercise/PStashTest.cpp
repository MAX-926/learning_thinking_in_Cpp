//:C:13:PStashTest.cpp
// {L} PStash
// Test of pointer Stash
// #include "14-11.cpp"
#include"14-11(2).h"
#include "../../Require.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
//     PStash intStash;
//     // 'new' works with built-in type, too. Note
//     // the "pseudo-constructor"syntax:
//     for(int i = 0; i < 25; i++)
//         intStash.add(new int(i));
//     for(int j = 0; j < intStash.count(); j++)
//         cout << "intStash[" << j << "] = "
//              << *(int*)intStash[j] << endl;
//     // Clean up:
//     for(int k = 0; k < intStash.count(); k++)
//     {
//         delete (int*)intStash.remove(k);
//     }

//     ifstream in ("PStashTest.cpp");
//     assure(in, "PStashTest.cpp");
//     PStash stringStash;
//     string line;
//     while(getline(in, line))
//         stringStash.add(new string(line));
//     // Print out the strings:
//     for(int u = 0; stringStash[u]; u++)
//         cout << "stringStash[" << u << "] = "
//              << *(string*)stringStash[u] << endl;
//     // Clean up:
//     for(int v = 0; v < stringStash.count(); v++)
//     {
//         delete (string*)stringStash.remove(v);
//     }

    // Asteroid *ap1 = new Asteroid; 
    // Asteroid *ap2 = new Asteroid;
    // int i = 26;
    // (*ap1).add(ap2);
    // (*ap2).PStash::add(&i);
    // cout << *((int*)((*ap2).remove(0)));
    // void* apv = (*ap1).remove(0);
    // delete (Asteroid*)apv;
    // delete ap1;
    Asteroid as;
}///:~