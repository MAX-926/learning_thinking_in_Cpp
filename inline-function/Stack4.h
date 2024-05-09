//:C09:Stack4.h
// With inlines
#ifndef STACK4_H
#define STACK4_H

#include<iostream>
using namespace std;

class Stack
{
    private:
        struct Link
        {
            void* data;
            Link* next;
            Link(void* dat, Link* nxt):data(dat), next(nxt){}
            // ~Link(){}
        }* head;
    public:
        Stack(){head == 0;}
        ~Stack()
        {
            if(head != 0)
            {
                cout << "Stack is not empty,please be carefull\n";
            }
        }
        void* pop()
        {
            if(head == 0)
            {
                cout << "Stack is empty\n";
                return 0;
            }
            void* oldDat = head->data;
            Link* newHead = head->next;
            delete head;//書上的方法是取得舊的頭節點的地址，之後直接更新head的值為head->next，之後使用關鍵字delete清除舊的頭節點的内容
            head = newHead;
            return oldDat;
        }
        void* peek()const
        {
            if(head == 0)
            {
                cout << "Stack is empty\n";
                return 0;
            }
            return head->data;
            //return head?head->data:0;
        }
        void push(void* element)
        {
            head = new Link(element, head);//一步到位：不多準備一個tmp指針，直接更新head的值
        }
};

#endif //STACK4_H ///:~