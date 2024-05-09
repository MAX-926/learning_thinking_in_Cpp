// #define F(x) (x+1)
// #include<iostream>
// int main(void)
// {
//     std::cout << F (1);
//     return 0;
// }

// #define FLOOR(x, b) x>=b?0:1
// if(FLOOR(a&0x0f, 0x07)){}
// if(a&0x0f>=0x07?0:1)//将產生預期之外的結果。&運算符的優先級低於>=

// #include<iostream>

// class X
// {
//     private:
//         int i;
//     public:
//         friend void show(X&);
// };

// inline void show(X &x){std::cout << x.i;}

// int main(void)
// {
//     X x;
//     show(x);
// }

// #include<iostream>

// using namespace std;

// class ThreeDpoint
// {
//     private:
//         double x, y, z;
//     public:
//         inline ThreeDpoint(){x = 0; y = 0; z = 0;}
//         inline ~ThreeDpoint(){}
//         inline void showPosition(){std::cout << "x: " << x << endl << "y: " << y << endl << "z: " << z << endl;}
//         void forward();
//         void forback();
//         void turnleft();
//         void turnright();
//         void standby();
// };

// void ThreeDpoint::forward()
// {
//     x++;
// }

// void ThreeDpoint::forback()
// {
//     x--;
// }

// void ThreeDpoint::standby()
// {
//     system("pause");
// }

// void ThreeDpoint::turnleft()
// {
//     std::cout << "turn left\n";
// }

// void ThreeDpoint::turnright()
// {
//     std::cout << "turn right\n";
// }

// int main()
// {
//     ThreeDpoint d;
//     d.showPosition();
//     d.forward();
//     d.showPosition();
//     d.forback();
//     d.showPosition();
//     d.turnleft();
//     d.turnright();
//     d.standby();
//     return 0;
// }

//:C09:Inline.cpp
// Inline inside classes
// #include<iostream>
// using namespace std;

// class Point
// {
//     private:
//         int i, j, k;
//     public:
//         Point():i(0), j(0), k(0){}
//         Point(int ii, int jj, int kk):i(ii), j(jj), k(kk){}
//         void print(const string& msg = " ")const
//         {
//             if(msg.size() != 0)
//             {
//                 cout << msg << endl;                
//             }
//             cout << "i = " << i << ", "
//                  << "j = " << j << ", "
//                  << "k = " << k << endl;
//         }
// };

// int main(void)
// {
//     Point p, q(1, 2, 3);
//     p.print("value of p");
//     q.print("value of q");
//     return 0;
// }

//:C09:Access.cpp
// Inline access functions

// class Access
// {
//         int i;
//     public:
//         int read() const { return i;}//訪問函數一内聯函數實現
//         void set(int ii) {i = ii;}//設置函數以内聯函數實現
// };

// int main(void)
// {
//     Access A;
//     A.set(100);
//     int x = A.read();
//     return 0;
// }///:~

#include"E:\thinking in C++\Cpptime.h"
#include<iostream>
using namespace std;
int main(void)
{
    Time start;
    for(int i = 1; i < 1000; i++)
    {
        cout << i << ' ';
        if(i % 10 == 0) cout << endl;
    }
    Time end;
    cout << endl;
    cout << "start = " << start.ascii();
    cout << "end = " << end.ascii();
    cout << "delta = " << end.delta(&start);
    // Time clock;
    // std::cout << clock.since1900();
    return 0;
}