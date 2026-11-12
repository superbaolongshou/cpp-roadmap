// 1、引用必须要初始化
// int &b;//错误的
// 2、引用一旦初始化后，就不可以更改了
#include <iostream>
using namespace std;

int main()
{

    int a = 10;
    int &b = a;
    int c = 20;
    b = c; // x
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    cout << "c:" << c << endl;

    return 0;
}