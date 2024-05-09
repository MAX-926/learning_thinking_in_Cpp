//:C16:StackTemplate.h
// Simple Stack template
#ifndef STACKTEMPLATE_H
#define STACKTEMPLATE_H
#include"../../Require.h"
template<class T>
class StackTemplate
{
        enum{ssize = 100};
        T stack[ssize];
        int top;
    public:
        StackTemplate():top(0){}
        void push(const T& element)
        {
            require(top < ssize, "Too many push()es");
            stack[top++] = element;
            return;
        }
        T pop()
        {
            require(top > 0, "Too many pop()s");
            return stack[--top];
        }
        int size(){return top;}
};


#endif // STACKTEMPLATE_H ///:~