#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class SymStack
{
    private:
        enum{size = 10};
        //char symbol
        char sym[size];
        int top;
    public:
        SymStack():top(-1){memset(sym, 0, sizeof(char)*size);}
        ~SymStack(){/*cout << "destruct SymStack\n";*/}
        int getTop()const {return top; /*cout << top << endl;*/}
        //栈基本操作：push(),pop(),seek()
        char pop(){if(top >= 0){char tmp = sym[top]; --top; return tmp;}else {cout << "SymStack is empty\n"; return sym[top];}}
        void push(char op){if(++top < size) sym[top] = op;else {--top; cout << "SymStack is full\n"; return;}}
        char seek()const {if(top >= 0) return sym[top];else {cout << "SymStack is empty\n"; return ' ';}}

};

class ValStack
{
    private:
        enum{size = 10};
        double val[size];
        int top;
    public:
        ValStack():top(-1){memset(val, 0, sizeof(double)*size);}
        ~ValStack(){/*cout << "destruct ValStack\n";*/}
        void getTop()const {cout << top << endl;}
        //栈基本操作:push(),pop(),seek()
        double pop(){if(top >= 0){double tmp = val[top]; --top; return tmp;}else {cout << "ValStack is empty\n"; return 0.0;}}
        void push(double num){if(++top < size) {val[top] = num; return;}else {--top;cout << "ValStack is full\n"; return;}}
        double seek()const {if(top >= 0) return val[top];else{cout << "ValStack is empty\n";return 0.0;}}
};

class Exp_cal
{
    private:
        string exp;    
        SymStack ss;
        ValStack vs;
        double result;

        int s_judger(char);
        int getPriority(char);
        double sub_cal(char, double, double);
        void cal();
    public:
        Exp_cal(string expr):exp(expr), ss(), vs(), result(0.0){}
        ~Exp_cal(){}
        void run(){cal();}
        double getResult()const {return result;}
};

int Exp_cal::s_judger(char s)// 运算符返回0，'('返回1，数字输入返回2，')'返回-1
{
    if(s == '+' || s == '-' || s == '*' || s == '/') return 0;// 判断是符号则返回0
    // else if(s == '(') return 1;// 是'('则返回1
    else if((int)s <= 9 && (int)s >= 0) return 2;// 判断是数字则返回2
    // else {/*cout << "wrong input: " << s << endl;*/ return -1;}// 判断是)则返回-1
    else return -1;
}

int Exp_cal::getPriority(char s)
{
    switch(s)
    {
        case '+': return 0;
        case '-': return 0;
        case '*': return 1;
        case '/': return 1;
    }
}

void Exp_cal::cal()
{
    //4*(3+2)/5
    // 4+3*5*6
    // 4*3+5*3

    for(int i = 0; i < exp.length(); i++)
    {
        int tag = s_judger(exp[i]);
        switch(tag) // 0:op, 1:(, 2:num, -1:)
        {
            case 0:
                if(ss.getTop() == -1) {ss.push(exp[i]); break;}
                if(getPriority(ss.seek()) >= getPriority(exp[i]))
                {
                    double lv, rv;
                    char op = ss.pop();
                    rv = vs.pop();
                    lv = vs.pop();
                    vs.push(sub_cal(op, lv, rv));
                    ss.push(exp[i]);
                    break;
                }
                else {ss.push(exp[i]); break;}
            // case 1: ss.push(exp[i]);
            case 2: vs.push((int)exp[i]);
                    if(i == exp.length()-1)
                    {
                        double lv, rv;
                        rv = vs.pop();
                        lv = vs.pop();
                        vs.push(sub_cal(ss.pop(), lv, rv));
                    } 
            // case -1: 
        }
    }
    result = vs.pop();
}

double Exp_cal::sub_cal(char op, double lv, double rv)
{
    switch(op)
    {
        case '+': return lv + rv;
        case '-': return lv - rv;
        case '*': return lv * rv;
        case '/': if(rv != 0) return lv / rv; else {cout << "RV EQUAL TO ZERO! Wrong rv\n";}
    }
}

int main()
{
    //a test for SymStack and ValStack
    // SymStack ss;
    // ss.getTop();
    // ss.push('M');
    // cout << ss.seek() << endl;
    // ss.getTop();
    // ss.pop();
    // ss.getTop();
    // ss.pop();
    // ss.push('A');
    // cout << ss.seek() << endl;
    // ss.getTop();
    // ss.pop();
    // ss.getTop();

    // ss.push('X');
    // ss.push('A');
    // ss.push('M');
    // for(int i = 0; i < 3; i++)
    // {
    //     cout << ss.pop();
    // }

    // ValStack vs;
    // vs.getTop();
    // vs.push(26);
    // cout << vs.seek() << endl;
    // vs.getTop();
    // vs.pop();
    // vs.getTop();
    // vs.pop();
    // vs.push(27);
    // cout << vs.seek() << endl;
    // vs.getTop();
    // vs.pop();
    // vs.getTop();
    // vs.pop();
    // for(int i = 0; i < 11; i++)
    // {
    //     ss.push('m');
    // }
    // for(int i = 0; i < 11; i++)
    // {
    //     cout << ss.pop() << endl;
    // }

    string exp;
    cin >> exp;
    // cout << exp;
    Exp_cal ec(exp);
    ec.run();
    cout << ec.getResult();
}