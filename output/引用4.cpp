// 引用做函数的返回值

// 2、函数的调用可以作为左值
#include <iostream>
using namespace std;
// 1、不要返回局部变量的引用
// int &fun1()
//{
//    int a = 1;
//    return a;
//}
int &fun2()
{
    static int a = 1;
    return a;
}
int main()
{
    // int &ref = fun1();

    // cout << "ref=" << ref << endl;
    int &ref2 = fun2();
    cout << "ref2=" << ref2 << endl;
    cout << "ref2=" << ref2 << endl;
    fun2() = 2;
    cout << "ref2=" << ref2 << endl;
    return 0;
}