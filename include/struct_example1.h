#include <iostream>
#include <math.h>
#include <string>

using namespace std;

struct student
{
    //成员变量
    string name;
    int score;
};

struct teacher
{
    //成员变量
    string name;
    student stu[5];
};

//结构体数组赋值函数
void nameDate(teacher t[], int len);
//结构体数组打印函数
void printDate(teacher t[], int len);

struct hero
{
    //成员变量
    string name;
    int age;
    string sex;
};

//按年龄对结构体数组冒泡排序函数
void bubbleHero(hero hArray[], int len);
//结构体数组打印函数
void printHero(hero hArray[], int len);
