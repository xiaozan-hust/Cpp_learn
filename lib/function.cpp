#include "function.h"

void swap1(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

//传入函数的为地址
void swap2(int *a, int *b)
{
    int temp;
    temp = *a; //保存地址a中的值
    *a = *b; //将地址b中的值赋给地址a中的值
            //此时地址不变，但是里面的值发生了变化，因此实现了实参的改变
    *b = temp; //将地址a中的值赋给地址b中的值
}

//此处传入形参arr的为实参的数组首地址，它可以像实参数组一样用下标访问数组数据
//在函数的参数传递中int *arr和int arr[]等价
void bubbleSort(int arr[], int len)
{
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = 0; j < len - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

        }
    }
}

//将数组打印
void printArray(int arr[], int len)//int arr[]可以替换为int *arr
{
    for(int i = 0; i < len; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

//结构体作为函数参数——值传递
void printStudent1(student stu)
{
    stu.age = 28;
    cout << "子函数中姓名：" << stu.name << " 年龄：" << stu.age  << " 分数：" << stu.score << endl;
}

//结构体作为函数参数——地址传递
void printStudent2(student *stu)
{
    stu -> age = 28;
    cout << "子函数中姓名：" << stu -> name << " 年龄：" << stu -> age  << " 分数：" << stu -> score << endl;
}

//结构体作为函数参数——const修饰
void printStudent3(const student *stu)
{
    // stu -> age = 28; //不可修改
    cout << "子函数中姓名：" << stu -> name << " 年龄：" << stu -> age  << " 分数：" << stu -> score << endl;
}
