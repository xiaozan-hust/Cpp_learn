//外部引用函数头文件
/*
#include "function.h"

int main()
{
    int num1 = 100;
    int num2 = 200;

    swap1(num1, num2);

    system("pause");
    
    return 0;
}
*/

#include <iostream>
#include <math.h>
#include <string>
#include "function.h"

using namespace std;

int main()
{
    // system("chcp 65001");

//指针
    
    int a = 10;
    int *p = NULL; //定义指针变量，指向的变量为int型, 利用空指针初始化（也可以不初始化）

    p = &a; //指针指向变量a的地址
    cout << "&a = " << &a << endl; //打印出a的地址
    cout << "p = " << p << endl; //打印出指针变量p的值
    cout << "*p = " << *p << endl; //打印出指针变量指向的内存

    cout << "指针变量p的大小为: " << sizeof(p) << endl;
    cout << "指针变量p指向的内存所占大小为: " << sizeof(*p) << endl;
    

//const修饰
    /*
    int a = 10;
    int b = 20;

    //修饰常量，指针指向的值不可更改，但是指针指向可以更改
    const int *p1 = &a;
    p1 = &b;
    // *p1 = b;

    //修饰指针，指针指向的值可以更改，但是指针指向不可更改
    int * const p2 = &a;
    // p2 = &b;
    *p2 = b;

    //既修饰指针，也修饰常量，故二者都不可更改
    const int * const p3 = &a;
    // p3 = &b;
    // *p3 = b;
    */

//指针与数组
    /*
    int arr[] = {1, 2, 3, 4, 5, 6};
    int *p = arr;
    
    for(int i = 0; i < 6; i++)
    {
        cout << *p << endl;
        p++;
    }
    */

//地址传递
    /*
    int a = 10;
    int b = 20;

    swap1(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    swap2(&a, &b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    */

//函数，地址和数组
    /*
    int arr[10] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};
    int len = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, len);
    printArray(arr, len);
    */

//结构体
    /*
    //已在function.h中定义
    
    //结构体变量创建方式一
    struct student stu1;
    stu1.name = "焦绪嘉";
    stu1.age = 22;
    stu1.score = 659;

    cout << "姓名：" << stu1.name << endl << "年龄：" << stu1.age << endl << "分数：" << stu1.score << endl;

    //结构体变量创建方式二
    struct student stu2 = {"焦绪嘉", 22, 659};
    cout << "姓名：" << stu2.name << endl << "年龄：" << stu2.age << endl << "分数：" << stu2.score << endl;
    
    //结构体变量创建方式三
    //直接在定义结构体时创建
    stu3.name = "焦绪嘉";
    stu3.age = 22;
    stu3.score = 659;
    cout << "姓名：" << stu3.name << endl << "年龄：" << stu3.age << endl << "分数：" << stu3.score << endl;
    */

//结构体数组
    /*
    struct student arr[3] = 
    {
        {"张三", 18, 99},
        {"李四", 19, 98},
        {"王五", 20, 100}
    };

    for(int i = 0; i < 3; i++)
    {
        cout << "姓名：" << arr[i].name << " 年龄：" << arr[i].age << " 分数：" << arr[i].score << endl;
    }
    */

//结构体指针
    /*
    struct student stu = {"张三", 10, 100};
    struct student *p = &stu;

    //结构体的指针访问值的形式跟变量的指针访问值的形式是不一样的
    p -> score = 99;
    cout << "姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score << endl;
    */

//结构体嵌套结构体
    /*
    struct teacher t1;
    t1.id = 10000;
    t1.name = "柏拉图";
    t1.age = 50;

    t1.stu.name = "亚里士多德";
    t1.stu.age = 20;
    t1.stu.score = 99;

    cout << "教师 职工编号：" << t1.id << " 姓名：" << t1.name << " 年龄：" << t1.age << endl;
	cout << "辅导学员 姓名：" << t1.stu.name << " 年龄：" << t1.stu.age << " 考试分数：" << t1.stu.score << endl;
    */

//结构体作为函数参数
    /*
    struct student stu;
    stu = {"焦绪嘉", 22, 659};

    //地址传递可以改变主函数中的数据
    printStudent1(stu);
    cout << "主函数中姓名：" << stu.name << " 年龄：" << stu.age << " 分数：" << stu.score << endl;
    printStudent2(&stu);
    cout << "主函数中姓名：" << stu.name << " 年龄：" << stu.age  << " 分数：" << stu.score << endl;
    */

//结构体中使用const
    /*
    //使用const来防止误操作
    //结构体定义不改变，可在函数中或创建结构体变量时使用const
    const struct student stu = {"焦绪嘉", 22, 659};

    // printStudent2(&stu); //不可修改
    // printStudent3(&stu);
    */

//




    // system("pause");
    
    return 0;

}