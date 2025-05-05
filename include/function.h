#include <iostream>
#include <math.h>
#include <string>

using namespace std;

//注意：C++标准库中有swap函数的定义

//实现两个数字的交换的函数声明（值传递）
void swap1(int a, int b);
//实现两个数字的求最大值的函数声明
int max(int a, int b);
//实现两个数字的交换的函数声明（地址传递）
void swap2(int *a, int *b);
//实现对数组的冒泡排序
void bubbleSort(int *arr, int len);
//将数组打印
void printArray(int arr[], int len);

//结构体_学生
struct student
{
    //成员列表
    string name;
    int age;
    int score;
};

//结构体_老师
struct teacher
{
    //成员列表
    int id;
    string name;
    int age;
    struct student stu;
};

//结构体作为函数参数——值传递
void printStudent1(student stu);
//结构体作为函数参数——地址传递
void printStudent2(student *stu);
//结构体作为函数参数——const修饰
void printStudent3(const student *stu);
