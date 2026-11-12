#include <iostream>
using namespace std;

// 值传递
void swap1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
// 地址传递
void swap2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "2a:" << a << endl;
    cout << "2b:" << b << endl;
}
// 引用传递
void swap3(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a = 1;
    int b = 2;
    // swap1(a, b);
    // swap2(&a, &b);
    swap3(a, b);
    cout << "1a:" << a << endl;
    cout << "1b:" << b << endl;
    return 0;
}