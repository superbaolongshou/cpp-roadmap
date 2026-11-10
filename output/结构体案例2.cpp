#include <iostream>
using namespace std;
#include <string>

struct hero
{
    string name;
    int age;
    char sex;
};
void bubblesort(hero h[], int)
{
    for (int i = 0; i < 5 - 1; i++)
    {
        for (int j = 0; j < 5 - i - 1; j++)
        {
            if (h[j].age > h[j + 1].age)
            {
                hero temp = h[j];
                h[j] = h[j + 1];
                h[j + 1] = temp;
            }
        }
    }
}

int main()
{
    hero h[5]{
        {"liubei", 23, 'm'},
        {"guanyu", 22, 'm'},
        {"zhangfei", 20, 'm'},
        {"zhoayun", 21, 'm'},
        {"diaochan", 19, 'w'}};
    bubblesort(h, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << "name: " << h[i].name << "age: " << h[i].age << "sex: " << h[i].sex << endl;
    }
}