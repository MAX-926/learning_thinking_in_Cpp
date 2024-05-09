//:C16:AutoCounter.h
#ifndef AUTOCOUNTER_H
#define AUTOCOUNTER_H
#include"../../Require.h"
#include<iostream>
#include<set>// Standard C++ Library container
#include<string>

class AutoCounter
{
        static int count;
        int id;
        class CleanupCheck
        {
                std::set<AutoCounter*> trace;
            public:
                void add(AutoCounter* ap)
                {
                    trace.insert(ap);
                }
                void remove(AutoCounter* ap)
                {
                    require(trace.erase(ap) == 1, "Attempt to delete AutoCounter twice");
                }
                ~CleanupCheck(){std::cout << "~Cleanupcheck()\n";require(trace.size() == 0, "All AutoCounter objects not cleaned up");}
        };
        static CleanupCheck verifier;
        AutoCounter():id(count++)
        {
            verifier.add(this);// Register itself
            std::cout << "created[" << id << "]" << std::endl;
        }
        // prevent assignmnet and copy-construction:
        AutoCounter(const AutoCounter&);// 只聲明不實現
        AutoCounter& operator=(const AutoCounter&);
    public:
        // You can only create objects with this:
        static AutoCounter* create(){return new AutoCounter();}
        ~AutoCounter(){std::cout << "destroying[" << id << "]" << std::endl; verifier.remove(this);}
        // Print both objects and pointers:
        friend std::ostream& operator<<(std::ostream& os, const AutoCounter* ac)
        {
            return os << "AutoCounter " << ac->id;
        }
};
#endif // AUTOCOUNTER_H ///:~