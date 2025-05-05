#include "address.h"

void showMeau()
{
    cout << "**************************" << endl;
    cout << "***** 1、添加联系人 ******" << endl;
    cout << "***** 2、显示联系人 ******" << endl;
    cout << "***** 3、删除联系人 ******" << endl;
    cout << "***** 4、查找联系人 ******" << endl;
    cout << "***** 5、修改联系人 ******" << endl;
    cout << "***** 6、清空联系人 ******" << endl;
    cout << "***** 0、退出通讯录 ******" << endl;
    cout << "**************************" << endl;
}

void addPerson(addressBooks *abs)
{
    if(abs->size == MAX)
    {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }
    else
    {
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[abs->size].name = name;

        string sex;
        cout << "请输入性别：" << endl;
        cin >> sex;
        abs->personArray[abs->size].sex = sex;

        string phonenumber;
        cout << "请输入联系电话：" << endl;
        cin >> phonenumber;
        abs->personArray[abs->size].phonenumber = phonenumber;

        int age;
        cout << "请输入联系人年龄：" << endl;
        cin >> age;
        abs->personArray[abs->size].age = age;

        string addr;
        cout << "请输入联系人地址：" << endl;
        cin >> addr;
        abs->personArray[abs->size].addr = addr;

        abs->size++;

        cout << "添加成功！" << endl;
        system("pause");
        system("cls");
    }
}

void showPerson(const addressBooks abs)
{
    if(abs.size == 0)
    {
        cout << "当前通讯录信息为空！" << endl;
    }
    else
    {
        for(int i = 0; i < abs.size; i++)
        {
            cout << "姓名：" << abs.personArray[i].name << " 年龄：" << abs.personArray[i].age << " 性别：" << abs.personArray[i].sex
            << " 联系电话：" << abs.personArray[i].phonenumber << " 家庭住址：" << abs.personArray[i].addr << endl;
        }
    }
    system("pause");
}


// int searchPerson(addressBooks *abs)
int isPerson(const addressBooks abs)
{
    string name;
    cout << "请输入要删除的联系人名字：" << endl;
    cin >> name;
    for(int i = 0; i < abs.size; i++)
    {
        if(name == abs.personArray[i].name)
        {
            return i;
        }
    }
    cout << "您查找的联系人不存在！" << endl;
    return -1;

}

void removePerson(addressBooks *abs)
{
    int order_num;
    // order_num = searchPerson(abs);
    //注意：由于removePerson的形参为指针，所以传入的abs在该函数内为一个指针
    //而函数searchPerson的形参为变量，故要用解运算*作为实参传入
    order_num = isPerson(*abs);

    if(order_num != -1)
    {
        for(int i = order_num; i < abs->size; i++)
        {
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->size--;
        cout << "删除联系人成功！" << endl;
        system("pause");
    }
    else
    {
        return;
    }

}

void searchPerson(const addressBooks abs)
{
    string name;
    cout << "请输入要查找的联系人名字：" << endl;
    cin >> name;
    for(int i = 0; i < abs.size; i++)
    {
        if(name == abs.personArray[i].name)
        {
            cout << "姓名：" << abs.personArray[i].name << " 年龄：" << abs.personArray[i].age << " 性别：" << abs.personArray[i].sex
            << " 联系电话：" << abs.personArray[i].phonenumber << " 家庭住址：" << abs.personArray[i].addr << endl;
            system("pause");
            return;
        }
    }
    cout << "您查找的联系人信息不存在！" << endl;
    system("pause");
}

void changePerson(addressBooks *abs)
{
    string name;
    cout << "请输入要修改的联系人名字：" << endl;
    cin >> name;
    for(int i = 0; i < abs->size; i++)
    {
        if(name == abs->personArray[i].name)
        {
            string new_name;
            cout << "请输入新联系人姓名：" << endl;
            cin >> new_name;
            abs->personArray[i].name = new_name;

            string new_sex;
            cout << "请输入新联系人性别：" << endl;
            cin >> new_sex;
            abs->personArray[i].sex = new_sex;

            string new_phonenumber;
            cout << "请输入新联系电话：" << endl;
            cin >> new_phonenumber;
            abs->personArray[i].phonenumber = new_phonenumber;

            int new_age;
            cout << "请输入新联系人年龄：" << endl;
            cin >> new_age;
            abs->personArray[i].age = new_age;

            string new_addr;
            cout << "请输入新联系人地址：" << endl;
            cin >> new_addr;
            abs->personArray[i].addr = new_addr;
            
            system("pause");
            return;
        }
    }
    cout << "查无此人！" << endl;
    system("pause");
}

void deleteallPerson(addressBooks *abs)
{
    abs->size = 0;
    abs = 0;
    cout << "已清空全部联系人信息！" << endl;
    system("pause");
}