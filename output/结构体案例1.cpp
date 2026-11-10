#include <iostream>
using namespace std;
#include <string>

struct student
{
    string sname;
    int score;
};

struct teacher
{
    string tname;
    student stu[5];
};

void setteacher(teacher t[], int len)
{

    string nameseed = "abcde";
    for (int i = 0; i < len; i++)
    {

        t[i].tname = "teacher";
        t[i].tname += nameseed[i];
        for (int j = 0; j < 5; j++)
        {
            t[i].stu[j].sname = "student";
            t[i].stu[j].sname += nameseed[j];
            t[i].stu[j].score = rand() % 100 + 1;
        }
    }
}
void printInfo(teacher t[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "老师姓名:" << t[i].tname << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "\t学生姓名:" << t[i].stu[j].sname << "成绩:" << t[i].stu[j].score << endl;
        }
    }
}

int main()
{
    // 创建3名老师数组
    teacher t[3];
    // 函数给老师赋值
    int len = sizeof(t) / sizeof(t[0]);
    setteacher(t, len);
    // 函数输出老师数组
    printInfo(t, len);
    return 0;
}