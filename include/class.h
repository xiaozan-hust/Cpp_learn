#include <iostream>
#include <math.h>

using namespace std;

const double PI = 3.1415926;

//类定义后必须要加分号
class Circle
{
public:
    //属性
    int m_r;

    //行为
    double getPerimeter()
    {
        return 2 * PI * m_r;
    }

};

class Student
{
public:
    //属性
    string name;
    int id;

    //行为
    void setName(string m_name)
    {
        name = m_name;
    }

    void setId(int m_id)
    {
        id = m_id;
    }

    void showStudent()
    {
        cout << "该学生的姓名为：" << name << " 该学生的ID为: " << id << endl;
    }
};

//体会设置成员不同权限的作用
class Person
{
//首先将成员全部设置为private
private:
    string m_name;
    int m_age = 20;
    string m_ID;

//创建函数去“获得”读、写权限
public:
    //m_name可读可写
    void setName(string name)
    {
        m_name = name;
    }

    string getName()
    {
        return m_name;
    }

    //m_age只可读
    int getAge()
    {
        return m_age;
    }

    //m_ID只可写
    void setID(string ID)
    {
        m_ID = ID;
    }

};

class Cube
{
public:
    //Cube类的长宽高
    int m_L;
    int m_W;
    int m_H;

    //计算Cube的面积和体积
    int getArea()
    {
        return 2*(m_L*m_H + m_L*m_W + m_H*m_W);
    }
    
    int getVolume()
    {
        return m_H*m_L*m_W;
    }

};

class superman01
{
public:
    //构造函数
    superman01()
    {
        cout << "构造函数的调用！" << endl;
    }

    //析构函数
    ~superman01()
    {
        cout << "析构函数的调用！" << endl;
    }
};

void superman01_test()
{
	superman01 super1;
};

class superman02
{
public:
    //无参（默认）构造函数
    superman02()
    {
        cout << "调用无参（默认）构造函数！" << endl;
    }

    //有参构造函数
    superman02(int a)
    {
        age = a;
        cout << "调用有参构造函数！" << endl;
    }

    //拷贝构造函数（有参构造）  （引用？？？）
    superman02(const superman02 &p)
    {
        age = p.age;
        cout << "调用拷贝构造函数！" << endl;
    }

    ~superman02()
    {
        cout << "调用析构函数!" << endl;
    }

public:
    int age;

};

//构造函数的调用方法
void superman02_test01()
{
    //调用无参（默认）构造函数
    superman02 super01;

    //调用有参构造函数（括号法） 最常用
    superman02 super02(10);
    superman02 super03(super02);

    //调用有参构造函数（显式法）
    superman02 super04 = superman02(10);
    superman02 super05 = superman02(super04);

    //调用有参构造函数（隐式转换法）
    superman02 super06 = 10;
    superman02 super07 = super06;

}

//拷贝构造函数调用时机
//1、使用一个已经创建完毕的对象来初始化一个新对象
void superman02_test02()
{
    //使用一个已经创建完毕的对象来初始化一个新对象
    superman02 super08(10);
    superman02 super09(super08);    //括号法

    superman02 super10;
    super10 = super09;      //赋值操作，并不调用拷贝构造函数
                            //赋值是全部复制，拷贝构造函数不一定完全拷贝
}

//2、值传递的方式给函数参数传值
void doWork(superman02 super1) {}
//相当于superman02 super1 = super;
void superman02_test03()
{
    superman02 super;
    doWork(super);
}

//3、以值方式返回局部对象
superman02 doWork2()
{
    superman02 super1;
    return super1;
}

void superman02_test04()
{
    superman02 super = doWork2();
}

//构造函数的调用规则
void superman02_test05()
{
    superman02 super1;
    //如果不写拷贝构造，编译器会自动添加拷贝构造并进行浅拷贝
    superman02 super2(super1);

    //如果用户提供有参构造，编译器不会提供默认构造函数，只会提供拷贝构造
    superman02 super3;  //如果不提供默认无参构造，将会出错
    superman02 super4(7);   //调用用户提供的有参构造函数
    superman02 super5(super4);  //若用户不提供，则编译器提供

    //如果用户提供拷贝构造，则编译器不提供任何构造函数
    superman02 super6;  //若用户不提供默认无参构造，将会出错
    superman02 super7(7);   //若用户不提供有参构造，将会出错
    superman02 super8(super7);  //调用用户提供的拷贝构造函数
}

class superman03
{
public:
    int m_age;
    int *m_height;

public:
    //默认无参构造函数
    superman03()
    {
        cout << "调用默认无参构造函数！" << endl;
    }

    //有参构造函数
    superman03(int age, int height)
    {
        //利用new创建的数据，会返回该数据对应的类型的指针
        m_age = age;
        //m_height在属性中为指针，故须保存地址
        m_height = new int(height);
        cout << "调用有参构造函数！" << endl;
    }

    //拷贝构造函数
    superman03(const superman03 &p)
    {
        m_age = p.m_age;
        m_height = p.m_height;
        // m_height = new int(*p.m_height);    //二者有何区别呢？
                                               //前者，会在析构函数中报错
        cout << "调用拷贝构造函数" << endl;
    }

    //析构函数
    ~superman03()
    {
        if(m_height != NULL)
        {
            delete m_height;
        }
        cout << "调用析构函数！" << endl;
    }

};

void superman03_test01()
{
    superman03 super1(10, 180);
    superman03 super2(super1);

    cout << "super1的年龄: " << super1.m_age << " 身高： " << *super1.m_height << endl;

	cout << "super2的年龄: " << super2.m_age << " 身高： " << *super2.m_height << endl;
}

class listInit
{
public:
    int m_a;
    int m_b;
    int m_c;

public:
    //传统方式的属性初始化
    /*
    listInit(int a, int b, int c)
    {
        m_a = a;
        m_b = b;
        m_c = c;
        cout << "调用有参构造函数！" << endl;
    }
    */

    //列表方式初始化
    listInit(int a, int b, int c) : m_a(a), m_b(b), m_c(c) 
    {
        cout << "调用列表方式初始化有参构造函数！" << endl;
    }

};

//类对象作为类成员
class phone
{
public:
    string m_num;

public:
    phone()
    {
        cout << "调用phone类的构造函数!" << endl;
    }

    ~phone()
    {
        cout << "调用phone类的析构函数!" << endl;
    }

};

//类对象作为类成员
class people
{
public:
    string m_name;
    phone iphone;

public:
    people()
    {
        cout << "调用people类的构造函数!" << endl;
    }

    ~people()
    {
        cout << "调用people类的析构函数!" << endl;
    }

};

void people_test()
{
    people p1;
}

//静态成员
class superman04
{
public:
    static int m_A; //静态成员变量

    //静态成员变量的特点
    //1、在编译阶段分配内存
    //2、类内声明，类外初始化
    //3、所有对象共享一份数据

    static void func1()
    {
        m_A = 100;
        // m_C = 100;  //错误，不可访问非静态成员变量
        cout << "静态成员函数func1()的调用！" << endl;
    }

    //静态成员函数的特点
    //1、程序共享一个函数
    //2、静态成员函数只能访问静态成员变量

private:
    static int m_B; //静态成员变量
    int m_C;
    static void func2()
    {
        cout << "静态成员函数func2()的调用！" << endl;
    }

};
//类外初始化
int superman04::m_A = 0;
int superman04::m_B = 0;

void superman04_test()
{
    //静态成员的两种访问方式
    //1、通过对象
    superman04 super1;
    superman04 super2;

    cout << super1.m_A << "\t" << super2.m_A << endl;
    super1.func1();
    //super1和super2中的m_A同时改变（本质为一个变量）
    cout << super1.m_A << "\t" << super2.m_A << endl;

    //2、通过类名
    superman04::m_A = 100;
    superman04::func1();
}

class Building;
//只有非静态成员变量才属于类的对象上
class superman05
{
public:
    /*
    //非静态成员变量占对象空间
    int m_A;
    //静态成员变量不占对象空间
    static int m_B;
    //成员函数也不占对象空间，所有函数共享一个函数实例
    void func(){}
    //静态成员函数也不占对象空间
    static void func1(){}
    */

    int age;
    //将在常函数中可修改
    mutable int ID;
    //用于友元的构造函数
    superman05();
    //this指针
    superman05(int age)
    {
        //1、当形参和成员变量同名时，可用this指针来区分
        this->age = age;
        cout << "调用构造函数！" << endl;
    }

    superman05 &addSuperman05(superman05 super)
    {
        this->age += super.age;
        //2、返回对象本身
        return *this;
    }

    //空指针
    void showNull()
    {
        cout << "空指针调用一下！" << endl;
    }

    void showSuperman05()
    {
        if(this == NULL)
        {
            return;
        }

        cout << "该对象的age为: " << this->age << endl;
    }

    //const修饰成员函数
    //常函数
    //成员函数后加const后我们称这个函数为常函数
    //常函数内不可以修改成员属性
    //成员属性声明时加关键字mutable后，在常函数中依然可以修改
    //常对象
    //声明对象前加const称该对象为常对象
    //常对象只能调用常函数
    void showConst() const
    {
        // age = 100;   //不可修改
        ID = 1; //与this->ID等同
        //this指针的本质为一个指针常量，指针的指向不可修改
        //如果想让指针指向的值也不可修改，需要声明常函数
    }
    superman05& ffunc();
    superman05& ffunc2();

    ~superman05();

private:
Building *building; //使用前需要先进行Building类的声明

};

void superman05_test01()
{
    superman05 super1(10);
    superman05 super2(20);

    super1.addSuperman05(super2).addSuperman05(super2);
    cout << "super1的age: " << super1.age << endl;
}

//空指针访问成员函数
void superman05_test02()
{
    superman05 *p = NULL;
    p->showNull();
    p->showSuperman05();
}

//const修饰成员函数
void superman05_test03()
{
    const superman05 super(10);    //常量对象
    cout << super.age << endl;  //常对象可访问成员变量
    // super.age = 80;             //常对象不可修改成员变量
    super.ID  =10;              //常对象可修改mutable修饰的成员变量
    //常对象只能调用常函数
    super.showConst();
}

//友元
class Building
{
    //1、全局函数做友元
    friend void friendFunc(Building *building);

    //2、类做友元
    // friend class superman05;

    //3、成员函数做友元
    friend superman05& superman05::ffunc2();

public:
    Building()
    {
        this->m_SittingRoom = "客厅";
        this->m_BedRoom = "卧室";
    }

public:
    string m_SittingRoom;   //客厅
private:
    string m_BedRoom;   //卧室

};

void friendFunc(Building *building)
{
    cout << "调用全局函数做友元！" << endl;
    cout << "全局函数做友元访问私有变量: " << building->m_BedRoom << endl;
    cout << "全局函数做友元访问公有变量: " << building->m_SittingRoom << endl;
    building->m_BedRoom = "卧室（全局函数修改）";
    building->m_SittingRoom = "客厅（全局函数修改）";
    cout << "全局函数做友元访问私有变量: " << building->m_BedRoom << endl;
    cout << "全局函数做友元访问公有变量: " << building->m_SittingRoom << endl;
}
//用于友元的构造函数
superman05::superman05()
{
    building = new Building;
}

//析构函数
superman05::~superman05()
{
    this->age = 0;
    this->ID = 0;
    if(building != NULL)
    {
        delete building;
    }
}
//用于友元的函数测试
superman05& superman05::ffunc()
{
    //注意：构造函数，最好要完成对全部属性的初始化，不然直接调用某个属性的话会出错
    cout << "类做友元访问共有成员：" << building->m_SittingRoom << endl;
    // cout << "类做友元访问私有成员：" << building->m_BedRoom << endl;
    return *this;
}

superman05& superman05::ffunc2()
{
    cout << "类做友元访问私有成员：" << building->m_BedRoom << endl;
    return *this;
}