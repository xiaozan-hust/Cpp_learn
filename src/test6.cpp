#include <iostream>
#include <math.h>
#include <string>
#include "class.h"

using namespace std;

/*
//全局变量
int g_a = 10;
int g_b = 10;

//全局常量
const int c_g_a = 10;
const int c_g_b = 10;
*/

/*
int* func()
{
    int a = 10;
    return &a;
}
*/

int* func()
{
    //利用new创建的数据，会返回该数据对应的类型的指针
    //与&相比，new创建的数据的特点在于由程序员手动开辟，手动释放
    int *a = new int(10);
    return a;
}

//引用传递
void mySwap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//引用作为函数返回值
int& test01()
{
    static int a = 10;
    return a;
}

//常量引用
void showValue(const int &a)
{
    // a++; // 不允许修改
    cout << a << endl;
}

//函数默认参数
int funcAdd(int a, int b = 10, int c = 10);
int funcAdd(int a, int b, int c)
{
    return a+b+c ;
}

//函数占位参数
void func2(int a, int)
{
    cout << "这是一个含占位参数的函数。" << endl;
}

//函数重载
//
void func3()
{
    cout << "func()的调用！" << endl;   
}

void func3(int a)
{
    cout << "func(int a)的调用！" << endl;
}

void func3(double a)
{
    cout << "func(double a)的调用！" << endl;
}

void func3(double a, int b)
{
    cout << "func(double a, int b)的调用！" << endl;
}

void func3(int a, double b)
{
    cout << "func(int a, double b)的调用！" << endl;
}

int main()
{
    system("chcp 65001");

//全局区
    /*
    //局部变量
    int l_a = 10;
    int l_b = 10;

    //局部常量
    const int c_l_a = 10;
    const int c_l_b = 10;

    //静态变量
    static int s_l_a = 10;
    static int s_l_b = 10;
    */

//栈区
    /*
    int *p = func();
    cout << *p << endl;
    delete p;

    //堆区开辟变量
    int *a = new int(15);
    cout << a << endl;
    cout << *a << endl;
    //释放变量
    delete a;

    //堆区开辟数组
    int *arr = new int[10];
    for(int i = 0; i < 10; i++)
    {
        //有没有一种可能，其实指针和数组名并没有区别
        arr[i] = i + 10;
    }
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    //释放数组
    delete[] arr;
    */

//引用
    /*
    int a = 10;
    //利用在定义时，加&，表示引用，作用是给变量起别名
    int &b = a; //必须初始化，一旦初始化后将不可更改引用

    //地址都是一样的
    cout << "a = " << a << " a的地址为: " << &a << endl;
    cout << "b = " << b << " b的地址为: " << &b << endl;

    //同时改变
    b = 100;
    cout << "a = " << a << " a的地址为: " << &a << endl;
    cout << "b = " << b << " b的地址为: " << &b << endl;
    */

//引用传递
    /*
    //引用传递和地址传递是一样的，引用传递的语法更为简单清楚
    int a = 10, b = 20;
    mySwap(a, b);
    cout << "a:" << a << " b:" << b << endl;
    */

//引用作为函数返回值（作用：将函数作为左值）
    /*
    //1.ref作为a的引用，相当于代码: int &ref = a;
    int &ref = test01();
    cout << "ref = " << ref << endl;

    //如果函数作为左值，函数返回必须为引用
    //test01()返回，相当于代码: a = 1000;
    test01() = 1000;
    cout << "ref = " << ref << endl;
    */

//引用的本质
    /*
    //引用的本质为一个指针常量，即const修饰的是指针，指针指向不可改，但是指针指向的值可以更改
    //故而解释了引用一旦定义，不可修改
    int a = 10;
    int &ref = a; //自动转换为int* const ref = &a;
    ref = 20; //自动转换为*ref = 20;
    */

//常量引用
    /*
    //本质就是在修饰指针的情况下又修饰了常量，使常量和指针都不允许修改
    int a = 10;
    // int &ref = 10; //报错，在引用定义时不允许直接赋值
    //const int &ref = 10; //与下等价
    const int &ref = a;
    // ref = 50; //不允许修改

    //此时ref和a都不可修改
    showValue(a);
    showValue(ref);
    */

//函数提高
    /*
    //函数默认参数
    cout << funcAdd(10) << endl;    
    cout << funcAdd(10, 20) << endl;      

    //函数占位参数 --占位参数必须补全
    func2(10, 10);

    //函数重载
    func3();
	func3(10);
	func3(3.14);
	func3(10,3.14);
	func3(3.14 , 10);
    */

//类和对象
    /*
    //圆类
    Circle c1;
    c1.m_r = 5;
    cout << "该圆的周长为：" << c1.getPerimeter() << endl;

    //学生类
    Student s1;
    s1.setName("Tom");
    s1.setId(1);
    s1.showStudent();
    
    //人类
    //设置成员权限的方法为：首先将成员全部设为private，然后创建public的函数去读、写
    Person p1;
    //可读可写
    p1.setName("小胖子");
    cout << "名字可读：" << p1.getName() << endl;

    //可读不可写（只能类内访问）
    // p1.m_age = 20;
    cout << "年龄可读：" << p1.getAge() << endl;

    //可写不可读（只能类内访问）
    p1.setID("01");
    // cout << "ID不可读: " << p1.m_ID << endl;

    //立方体类
    Cube cu1;
    // cu1.m_H = 5;
    // cu1.m_L = 10;
    // cu1.m_W = 15;
    cout << "请输入立方体的长宽高(回车或空格确定): " << endl ;
    cin >> cu1.m_L >> cu1.m_W >> cu1.m_H ; 

    cout << "该立方体的表面积为：" << cu1.getArea() << "   该立方体的体积为：" << cu1.getVolume() << endl;
    */

//构造函数和析构函数
    /*
    //如果我们不提供构造函数和析构函数，编辑器会提供默认构造函数和析构函数
    superman01 super1;    //只调用构造函数
    superman01_test();    //构造函数和析构函数皆调用
    */

//构造函数
    /*
    superman02_test01();
    */

//拷贝构造函数调用的时机
    /*
    //1、使用一个已经创建完毕的对象来初始化一个新对象
    superman02_test02();
    //2、值传递的方式给函数参数传值
    superman02_test03();
    //3、以值方式返回局部对象
    superman02_test04();    //并没有调用拷贝构造函数
    */

//构造函数调用规则（和编译器相关）
    /*
    //1、C++编译器中一个类至少需要三个函数：默认构造函数；默认析构函数；默认拷贝构造函数
    //2、当用户提供有参构造函数后，C++不再提供默认无参构造函数，但会提供默认拷贝构造函数
    //3、当用户提供拷贝构造函数，C++不再提供任何构造函数
    //总结：默认无参构造、有参构造、拷贝构造函数，当用户提供某个函数后，前面的函数编译器将不再提供，如果用户不提供前面的函数，则将报错
    superman02_test05();
    */

//深拷贝与浅拷贝
    /*
    //浅拷贝：简单的赋值拷贝操作
    //深拷贝：在堆区重新申请空间，进行拷贝操作
    //如果属性有在堆区开辟的，就用户自行提供深拷贝函数，防止浅拷贝带来的重复释放堆区的问题
    superman03_test01();
    */

//初始化列表
    /*
    //仅适用于类中属性的初始化（不能用于函数中的赋值）
    listInit l1(1, 2, 3);
    */

//类对象作为类成员
    /*
    //类相当于是自定义的一种变量吧
    //先调用对象成员的构造，再调用本类构造
    //先调用本类析构，再调用对象成员的析构
    people_test();
    */

//静态成员
    /*
    //与静态变量相区分，此处指的是类内成员
    //静态成员就是在成员变量和成员函数前面加上关键字static，称为静态成员
    //分为静态成员变量和静态成员函数
    superman04_test();
    */

//C++对象模型和this指针
    /*
    //1、只有非静态成员变量占对象空间
    //2、this指针无需定义，直接使用，指向被调用的成员函数所属的对象
    //3、this指针的用途：1.当形参和成员变量同名时，可用this指针来区分；2.在类的非静态成员函数中返回对象本身，可使用return *this;
    superman05_test01();
    //空指针
    superman05_test02();
    //const修饰成员函数
    superman05_test03();
    */

//友元
    /*
    //实现让一个函数或者类访问另一个类中的私有成员
    // Building b1;
    // friendFunc(&b1);

    superman05 super;
    super.ffunc2();
    */

    system("pause");
    return 0;

}