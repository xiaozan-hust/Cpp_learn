#include "struct_example1.h"

using namespace std;

//结构体案例一
/*
int main()
{
//该行代码用于保证输出中文不乱码
    system("chcp 65001");

    struct teacher t[3];
    int len = sizeof(t) / sizeof(t[0]);
    struct teacher *p = t;

    // nameDate(p, len);
    //地址传递
    nameDate(t, len);
    printDate(t, len);
    //此时指针p为结构体数组的首地址，相当于t[0]
    //结构体指针的访问形式要用->，故p->name，相当于t[0].name
    //t和p一样，t也表示结构体的首地址，访问形式用->
    //但是对于结构体数组来讲，结构体指针访问的形式涉及到成员变量所占大小，所以并不方便
    cout << p->name << endl;
    cout << t->name << endl;
    cout << t[0].name << endl;

    system("pause");

    return 0;
}
*/

//结构体案例二
int main()
{
    system("chcp 65001");

    struct hero hArray[5] =
    {
        {"刘备", 23, "男"},
        {"关羽", 22, "男"},
        {"张飞", 20, "男"},
        {"赵云", 21, "男"},
        {"貂蝉", 19, "女"}
    };

    int len = sizeof(hArray) / sizeof(hero);
    
    bubbleHero(hArray, len);
    printHero(hArray, len);

    system("pause");

    return 0;
}