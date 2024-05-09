//:C15:OStack.h
// Using a single-rooted hierarchy
#ifndef OSTACK_H
#define OSTACK_H

class Object
{
    public:
        virtual ~Object() = 0;
};
inline Object::~Object(){}

class Stack
{
    struct Link
    {
        Object* data;
        Link* next;
        Link(Object* dat, Link* nxt):data(dat), next(nxt){}
    } *head;
    public:
       Stack():head(0){}
       ~Stack()
       {
        while(head)
        {
            delete pop();
        }
       }
       void push(Object* dat)
       {
            head = new Link(dat, head);
       }
       Object* peek() const {return head ? head->data : 0;}
       Object* pop()
       {
        if(head)
        {
            Link* oldHead = head;
            head = head->next;
            Object* information = oldHead->data;
            delete oldHead;
            return information;
        }
        else return 0;
       }
};
#endif // OSTACK_H ///:~