#include<iostream>
using namespace std;

int main(void)
{
    double array[5] = {1.0, 2.0, 3.0, 4.0};
    int arrayLen = sizeof(array) / sizeof(*array);
    for(int i = 0; i < arrayLen; i++)
        cout << array[i] << endl;
    cout << "************************************\n";
    double arr[] = {1.0, 2.0, 3.0, 4.0};
    arrayLen = sizeof(arr) / sizeof(*arr);
    for(int i = 0; i < arrayLen; i++)
        cout << arr[i] << endl;
    return 0;
}