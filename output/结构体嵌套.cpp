#include <iostream>
using namespace std;
#include <string>

struct student
{
    string name;
    int age;
    int score;
};
struct teacher
{
    int id;
    string name;
    student stu[3];
};

int main()
{
    teacher t1 = {1, "zhang", {{"zhangsan", 18, 90}, {"lisi", 19, 100}, {"wangwu", 20, 80}}};
    teacher *p = &t1;
    cout << "teacher id:" << p->id << "name:" << p->name << endl;
    cout << "\tstudent name:" << p->stu[0].name << "age:" << p->stu[0].age << "socre:" << p->stu[0].score << endl;
}