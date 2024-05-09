//:C09:Stack4.h
// Witj\h inlines
#ifndef STACK4_H
#define STACK4_H
#include"../../Require.h"
class Stack
{
    private:
        struct Link
        {
            // Data scope
            void* data;
            // Pointer scope
            Link* next;
            // Constructor
            Link(void* dat, Link* nxt):data(dat), next(nxt){}
        } *head;
    public:
        Stack():head(0){}
        ~Stack(){ require(head == 0, "Stack not empty");}
        void push(void *dat){ head = new Link(dat, head);}
        void* pop()
        {
            if(head == 0) return 0;
            Link* oldHead = head;
            head = head->next;
            void *result = oldHead->data;
            delete oldHead;
            return result;
        }
        void* peak(void)
        {
            if(head == 0) return 0;
            return head->data;
        }
};
#endif // STACK4_H ///:~