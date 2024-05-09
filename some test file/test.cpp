// // #include<iostream>
// // using namespace std;

// // class Illegal
// // {
// //     public:
// //         Illegal():message("Illegal"){}
// //         Illegal(char* theMessage){message = theMessage;}
// //         void outputMessage(){cout << message << endl;}
// //     private:
// //         string message;
// // };

// // int abc(int a, int b, int c)
// // {
// //     if(a < 0 || b < 0 || c < 0)
// //     {
// //         throw Illegal("a, b, c must be bigger than 0\n");
// //     }
// //     return a + b + c;
// // }

// // int main()
// // {
// //     abc(0, 0, 0);
// //     return 0;
// // }


// #include<iostream>
// using namespace std;

// class IllegalParameter
// {
//     private:
//         string info;
//     public:
//         IllegalParameter():info("Illegal"){}
//         IllegalParameter(string infos):info(infos){}
//         void show()
//         {
//             cout << info << endl;
//         }
// };

// int abc(int a, int b, int c)
// {
//     if(a < 0) throw IllegalParameter("Parameter a should > 0\n");
//     else return 0;
// }

// int main()
// {
//     try{abc(-1, 1, 1);}
//     catch(IllegalParameter e)
//     {
//         e.show();
//         return 1;
//     }
//     return 0;
// }

#include<iostream>
using namespace std;

// int factorial(int n)
// {
//     // basic part
//     if(n == 1) return 1;
//     // basic part
//     else if(n <= 0) return 1;
//     // 
//     else
//     {
//         return n*factorial(n-1);
//     }
// }

// template<class T>
// T sum(T arr[], int n)
// {
//     T result = 0;
//     for(int i = 0; i < n; i++)
//         result += arr[i];
//     return result;
// }

// template<class T>
// T sum(T arr[], int n)
// {
//     if(n < 0) return 0;
//     else
//     {
//         return arr[n-1] + sum(arr, n-1);
//     }
// }

// template<class T>
// T permutations(T list[], int k, int m)
// {
//     if(k == m)// 输出排列
//     {
//         copy(list, list+m+1, );
//         cout << endl;
//     }
//     else for(int i = k; i <= m; i++)
//     {
//         swap(list[k], list[i]);
//         permutations(list, k+1, m);
//         swap(list[k], list[i]);
//     }
// }

// 非递归程序计算n！

int factorial(int n)
{
    if(n <=0) return 1;
    int re = 1;
    for(int i = 1; i <= n; i++)
        re *= i;
    return re;
}

//青蛙跳台阶
int numberOfSolutions(int n)
{
    if(n == 1) return 1;
    if(n == 2) return 2;
    return numberOfSolutions(n-1) + numberOfSolutions(n-2);
}

//自下而上
int f(int n)
{
    if(n == 1) return 1;
    if(n == 2) return 2;
    int pre = 1;
    int next = 2;
    int result;
    for(int i = 3; i <= n; i++)
    {
        result = pre + next;
        pre = next;
        next = result;
    }
    return result;
}

int main()
{
    // cout << factorial(4);
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // permutations(arr, 0, 9);
    // cout << sum<int>(arr, 0);
    // cout << factorial(-1);
    // for(int i = 0; i < 5; i++)
    // {
    //     int x = 1;
    //     cout << x << endl;
    //     x++;
    // }

    cout << numberOfSolutions(100) << endl;
    cout << f(10);
}
