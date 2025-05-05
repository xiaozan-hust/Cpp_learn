#include "struct_example1.h"

//地址传递，与数组作为函数变量相似，此时可以用下标访问
void nameDate(teacher t[], int len)
{
    string tname = "教师";
    string sname = "学生";
    string nameSeed = "ABCDE";

    for(int i = 0; i < len; i++)
    {
        t[i].name = tname + nameSeed[i];
        for(int j = 0; j < 5; j++)
        {
            t[i].stu[j].name = sname + nameSeed[j];
            t[i].stu[j].score = rand() % 61 + 40;
        }
        
    }
};

void printDate(teacher t[], int len)
{
    for(int i = 0; i < len; i++)
    {
        cout << "老师姓名：" << t[i].name << endl;
        for(int j = 0; j < 5; j++)
        {
            cout << "学生姓名：" << t[i].stu[j].name << " 学生分数：" << t[i].stu[j].score << endl;
        }
    }
};

void bubbleHero(hero hArray[], int len)
{
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len - 1 - i; j++)
        {
            if(hArray[j].age > hArray[j+1].age)
            {
                // int temp = hArray[i].age;
                // hArray[i].age = hArray[i+1].age;
                // hArray[i+1].age = temp;  
                struct hero temp;
                temp = hArray[j];
                hArray[j] = hArray[j+1];
                hArray[j+1] = temp;
            }
        }
        
    }
};

void printHero(hero hArray[], int len)
{
    for(int i = 0; i < len; i++)
    {
        cout << hArray[i].name << hArray[i].age << hArray[i].sex << endl;
    }
};
