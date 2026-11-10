#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

// 联系人结构体
struct person
{
    string m_name;
    int m_sex;
    int m_age;
    string m_phone;
    string m_address;
};
// 通讯录结构体
struct addressbooks
{
    person personArray[MAX];
    int size; // 记录当前通讯录中人数
};

// 菜单界面
void showMenu()
{
    cout << "1.添加联系人" << endl;
    cout << "2.显示联系人" << endl;
    cout << "3.删除联系人" << endl;
    cout << "4.查找联系人" << endl;
    cout << "5.修改联系人" << endl;
    cout << "6.清空联系人" << endl;
    cout << "0.退出通讯录" << endl;
}
// 1.添加联系人
void add(addressbooks *abs)
{
    // 判断通讯录是否已满
    if (abs->size == MAX)
    {
        cout << "通讯录已满" << endl;
        return;
    }
    else
    {
        // 添加联系人
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[abs->size].m_name = name;
        // 添加性别
        cout << "请输入性别：" << endl;
        cout << "1.男" << endl;
        cout << "2.女" << endl;
        int sex = 0;
        while (true)
        {
            string input;
            cin >> input;

            // 判断输入是不是 "1" 或 "2"
            if (input == "1" || input == "2")
            {
                sex = stoi(input); // 将 string 转换为 int
                abs->personArray[abs->size].m_sex = sex;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入：" << endl;
            }
        }
        // 添加年龄
        cout << "请输入年龄：" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->size].m_age = age;
        // 添加电话
        cout << "请输入电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->size].m_phone = phone;
        // 添加地址
        cout << "请输入地址：" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->size].m_address = address;
        // 更新通讯录
        abs->size++;
        cout << "添加成功" << endl;
        system("pause");
        system("cls");
    }
}
// 2.显示联系人
void show(addressbooks abs)
{
    if (abs.size == 0)
    {
        cout << "暂无联系人" << endl;
    }
    else
    {
        for (int i = 0; i < abs.size; i++)
        {
            cout << "姓名:" << abs.personArray[i].m_name << "\t"
                 << "性别:" << (abs.personArray[i].m_sex == 1 ? "男" : "女") << "\t"
                 << "年龄:" << abs.personArray[i].m_age << "\t"
                 << "电话:" << abs.personArray[i].m_phone << "\t"
                 << "地址:" << abs.personArray[i].m_address << endl;
        }
    }
    system("pause");
    system("cls");
}
// 3.1删除前先检测有没有这个人
int isExist(addressbooks *abs, string name)
{
    for (int i = 0; i < abs->size; i++)
    {
        if (abs->personArray[i].m_name == name)
        {
            return i;
        }
    }
    return -1;
}
// 3.2删除
void deletePerson(addressbooks *abs)
{
    cout << "输入要删除的联系人:" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        for (int i = ret; i < abs->size - 1; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->size--;
        cout << "删除成功" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "查无此人" << endl;
    }
}
// 4.查找
void findPerson(addressbooks *abs)
{
    cout << "输入你要查找的联系人：" << endl;
    string name;
    cin >> name;
    // 判断指定联系人是否存在
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "姓名:" << abs->personArray[ret].m_name << "\t"
             << "性别:" << (abs->personArray[ret].m_sex == 1 ? "男" : "女") << "\t"
             << "年龄:" << abs->personArray[ret].m_age << "\t"
             << "电话:" << abs->personArray[ret].m_phone << "\t"
             << "地址:" << abs->personArray[ret].m_address << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}
// 5.修改
void modifyPerson(addressbooks *abs)
{
    cout << "输入你想查找的联系人:" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "姓名:" << abs->personArray[ret].m_name << "\t"
             << "性别:" << (abs->personArray[ret].m_sex == 1 ? "男" : "女") << "\t"
             << "年龄:" << abs->personArray[ret].m_age << "\t"
             << "电话:" << abs->personArray[ret].m_phone << "\t"
             << "地址:" << abs->personArray[ret].m_address << endl;
        string name;
        cout << "输入修改后姓名:";
        cin >> name;
        abs->personArray[ret].m_name = name;

        int sex;
        cout << "输入修改后性别:" << endl;
        cout << "1-->男" << endl;
        cout << "2-->女" << endl;
        while (true)
        {
            string input;
            cin >> input;
            if (input == "1" || input == "2")
            {
                sex = stoi(input);
                abs->personArray[ret].m_sex = sex;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入：" << endl;
            }
        }

        int age;
        cout << "输入修改后年龄:" << endl;
        cin >> age;
        abs->personArray[ret].m_age = age;

        string phone;
        cout << "输入修改后电话:" << endl;
        cin >> phone;
        abs->personArray[ret].m_phone = phone;

        string address;
        cout << "输入修改后地址:" << endl;
        cin >> address;
        abs->personArray[ret].m_address = address;

        cout << "修改完毕" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}
// 清空
void cleanPerson(addressbooks *abs)
{
    abs->size = 0;
    cout << "已清空所有联系人" << endl;
    system("pause");
    system("cls");
}
int main()
{
    int select = 0;
    addressbooks abs; // 创建通讯录结构体变量
    abs.size = 0;     // 初始化通讯录人数为0
    while (true)
    {
        showMenu();
        cin >> select;
        switch (select)
        {
        case 1: // 1.添加联系人
            add(&abs);
            break;
        case 2: // 2.显示联系人
            show(abs);
            break;
        case 3: // 3.删除联系人
            deletePerson(&abs);
            break;
        case 4: // 4.查找联系人
            findPerson(&abs);
            break;
        case 5: // 5.修改联系人
            modifyPerson(&abs);
            break;
        case 6: // 6.清空联系人
            cleanPerson(&abs);
            break;
        case 0: // 0.退出通讯录
            system("pause");
            return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}