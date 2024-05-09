#include<iostream>
using namespace std;

class Stack
{
    private:
        struct Link
        {
            void* data;
            Link* next;
            Link(void* dat, Link* nxt){data = dat; next = nxt;}
        }* head;
    public:
        Stack(){head = 0;}
        ~Stack(){}
        void* pop();
        void* peek();
        void push(void* element);
        void cleanup();
};

void* Stack::pop()
{
    if(head == 0){ cout << "Stack is empty\n"; return 0;}
    void* ele = head->data;
    head = head->next;
    return ele;
}

void* Stack::peek()
{
    if(head == 0){cout << "Stack is empty\n"; return 0;}
    return head->data;
}

void Stack::push(void* dat)
{
    Link* newN = new Link(dat, head);
    head = newN;
    cout << *(string*)dat << " was pushed into the stack\n";
}

void Stack::cleanup()
{
    if(head != 0){cout << "Stack is not empty\n";return;}
    delete head;
}

int main(void)
{
    string arr[] = {"MAX", "max", "jessies"};
    int arrLen =  sizeof(arr) / sizeof(*arr);
    Stack s;
    for(int i = 0; i < arrLen; i++)
    {
        s.push(&arr[i]);
    }
    cout << "waiting to pop all the element in the stack\n";
    for(int i = 0; i < arrLen; i++)
        cout << *(string*)s.pop() << endl;
    return 0;
}