// 函数重载满足条件:
//  同一个作用域下
//  函数名称相同
// 函数参数类型不同 或者 个数不同或者顺序不同
#include <iostream>
using namespace std;

// void fun()
//{
// cout << "fun1调用" << endl;
//}
// void fun(int a)
//{
//    cout << "fun2调用" << endl;
//}
// void fun(int a, int b)
//{
//     cout << "fun3调用" << endl;
// }
void fun(int b, int a)
{
    cout << "fun4调用" << endl;
}
void fun(int &a)
{
    cout << "func(int &a)调用" << endl;
}

void fun(const int &d)
{
    cout << "func(const int &a)调用" << endl;
}

int main()
{
    // fun();
    fun(10);
    int a = 1;
    fun(a);
    return 0;
}