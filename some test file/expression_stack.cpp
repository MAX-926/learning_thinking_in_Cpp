// 两个栈：1.符号栈 2.数值栈
#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
// class Number
// {
//     public:
//         Number(double initNum = 0.0):num(initNum){}
//         ~Number(){}
//         double getNum(void){return num;}
//         void setNum(double newNum){num = newNum; return;}
//         Number operator+(const Number& nc){return Number(nc.num + num);}
//         Number operator-(const Number& nc){return Number(num- nc.num);}
//         Number operator*(const Number& nc){return Number(nc.num * num);}
//         Number operator/(const Number& nc){return Number(num / nc.num);}
//     private:
//         double num;
// };

template<class T>
class Stack
{
    public:
        Stack():head(0){}
        ~Stack()
        {
            while(head)
                {
                    Node* tmp1 = head->next;
                    delete head;
                    head = tmp1;
                }
        }
        void push(T dat){head = new Node(dat, head);}
        T pop(void)
        {
            if(!head) return 0;
            T dp = head->data;
            Node* newHead = head->next;
            delete head;
            head = newHead;
            return dp;
        }
        T* peek(){if(!head)return 0; return head->data;}
    private:
        struct Node
        {
            // data
            T data;
            Node* next;
            // method
            Node(T dat, Node* nxt):data(dat), next(nxt){}
        }*head;
};

int calculate(char* exp, int len, Stack<int>* sip, Stack<char>* scp)
{
    for(int i = 0; i < len; i++)
    {
        
    }
}


int main()
{
    // char exp[30];
    // scanf("%s", exp);
    // Stack<int> intStack;
    // Stack<char> symStack;
    // int len = 0;
    // while(exp[len] != '$') len++;
    // for(int i = 0; i < len; i++)

}
    // Stack<Number> s;
    // Number n1(1), n2(2), n3(3);
    // s.push(&n1);
    // s.push(&n2);
    // s.push(&n3);
    // Number* np = 0;
    // while(np = s.pop())
    // {
    //     cout << np->getNum() << endl;
    // }
