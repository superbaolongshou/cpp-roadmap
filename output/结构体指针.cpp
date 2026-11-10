#include <iostream>
using namespace std;

struct student
{
    string name;
    int age;
    int score;
};

int main()
{
    student stu = {"张三", 19, 90};
    student *p = &stu;
    cout << "姓名：" << p->name << "年龄：" << p->age << "成绩：" << p->score << endl;
    cout << "姓名：" << stu.name << "年龄：" << stu.age << "成绩：" << stu.score << endl;
}