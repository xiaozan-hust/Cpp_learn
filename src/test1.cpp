#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define day 7
const int hour = 24;
int main()
{
//该行代码用于保证输出中文不乱码
    system("chcp 65001");

//输出及sizeof()
    /*
    cout << "Hello world" << endl;
    cout << "Hello Cpp" << endl;
    cout << "一周共有： " << day << "天" << endl;
    cout << "一天共有： " << hour << "小时" << endl;
    cout << "int类型所占内存空间为: " << sizeof(int) << endl;
    cout << "int类型所占内存空间为: " << sizeof(hour) << endl;
    //宏定义所占内存空间随具体的值而变化
    cout << "宏定义所占内存空间为: " << sizeof(day) << endl;
    cout << "double类型所占内存空间为: " << sizeof(double) << endl;
    */

//浮点数类型：单精度float&双精度double
    /*
    float f1 = 3.14f;
    float f2 = 3e2;
    float f3 = 3e-2;
    double d1 = 3.14;
    cout << f1 << endl;
    cout << f2 << endl;
    cout << f3 << endl;
    cout << d1 << endl;
    */

//字符型变量
    /*
    //字符型变量在赋值时需要添加单引号
    //字符型变量实质上是将字符对应的ASCII码放入到存储单元
    //相应的，也可以直接将ASCII码值赋给字符型变量
    char ch = 'a';
    cout << ch << endl << sizeof(ch) << endl;
    cout << (int)ch << endl;
    char ch1 = 97;
    cout << ch1 << endl;
    */

//转义字符
    /*
    //转义字符，用于表示一些不能显示出来的ASCII码
    cout << "\\" << endl; //反斜杠
    cout << "\tHello" << endl; //Tab键（制表符）
    cout << "\n" << endl; //换行
    cout << "Hello" << endl;
    */

//字符串变量
    /*
    //C语言风格
    //C++风格
    char str[] = "abc 123";
    string str1 = "abc 123";
    cout << str <<endl;
    cout << str1 << endl;
    */

//布尔型变量
    /*
    //输出1，0
    bool flag = true;
    bool flag1 = false;
    cout << flag << endl;
    cout << flag1 << endl;
    */

//输入
    /*
    int a;
    cin >> a;
    cout << a << endl;
    */

//运算符
//算数运算符：++ -- + - * / %
//赋值运算符：= -= += *= /= %= 
//比较运算符：== != < > <= >= 
//逻辑运算符：! && ||
    /*
    int a1 = 10;
    int b1 = ++a1 * 10;
	cout << b1 << endl;

    int a2 = 10;
    int b2 = a2++ * 10;
	cout << b2 << endl;
    */

//if语句
    /*
    float score;
    float award;
    float overall_score;
    cout << "请输入加权成绩: " << endl;
    cin >> score;
    cout << "请输入加分分数: " << endl;
    cin >> award;
    overall_score = score + award*0.3;
    cout << "您的最终综合成绩为：" << overall_score << endl;
    if (overall_score >= 91.5)
    {
        cout << "恭喜您, 预计可以获得2023年研究生推免资格!" << endl;
    }
    else if (overall_score >= 91)
    {
        cout << "哥们,你有点悬啊!" << endl;
    }
    else 
    {
        cout << "寄咯,你小子保不上研了!" << endl;
    }
    */

//三目运算符
    /*
    int a = 10;
    int b = 20;
    int c = 0;
    //a为真，则执行b，否则执行c
    c = a ? b : c;
    cout << c << endl;
    
    (a > b ? a : b) = 100;
    cout << a << endl << b << endl << c << endl;
    */

//switch语句(只能是整型或字符型)
    /*
    int score;
    char flag;
    cout << "请输入电影评分: " << endl;
    cin >> score;
    cout << "请输入标志变量：" << endl;
    cin >> flag;

    switch (flag)
    {
        case '1':
            cout << "置1" << endl;
            break;
        case '0':
            cout << "置0" << endl;
            break;
        default:
            cout << "输入不正确" << endl;
    }

    switch (score)
    {
        case 10:
        case 9:
            cout << "经典" << endl;
            break;
        case 8:
            cout << "非常好" << endl;
            break;
        case 7:
        case 6:
            cout << "一般般" << endl;
            break;
        default:
            cout << "烂片" << endl;
            break;
    }
    */

//while循环语句
    /*
    int num = 0;
    int sum = 0;
    while(num <= 100)
    {
        cout << "num = " << num << endl;
        sum += num;
        num++;
    }
    cout << "0到" << num << "的总和为：" << sum << endl;
    */

//do...while循环语句
    /*
    int num = 100;
    int hundreds;
    int tens;
    int units;
    int new_sum;
    int i = 0;
    do
    {
        hundreds = num/100;
        tens = (num - hundreds*100)/10;
        units = num%10;
        // cout << "百位数：" << hundreds << "十位数：" << tens << "个位数：" << units << endl;
        //'^'为按位异或运算符，不是幂运算符
        // new_sum = hundreds^3 + tens^3 + units^3;
        new_sum = pow(hundreds, 3) + pow(tens, 3) + pow(units, 3);
        if(new_sum == num)
        {
            cout << "第" << i << "个" << "水仙花数为：" << num << endl;
            i++;
        } 
        num++;
    } while (num < 1000);
    */

//for循环语句
    /*
    for(int i = 1; i <= 100; i++)
    {
        if((i%10 == 7)||(i/10 == 7)||(i%7 == 0))
        {
            cout << "敲桌子" << endl;
        }
        else 
        {
            cout << i << endl;
        }
    }
    */

   /*
   for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << "* " ;
        }
        cout << endl;
    }
    */

   /*
   for(int i = 1; i < 10; i++)
   {
        for(int j = 1; j <= i; j++)
        {
            cout << j << "x" << i << "=" << j*i << " ";
        }
        cout << endl;
   }
   */

//break和continue
    /*
    for(int i = 1; i < 10; i++)
    {
        if(i % 2 == 0)
        {
            continue;
        }
        cout << i << endl;
    }

    for(int i = 1; i < 10; i++)
    {
        if(i % 2 == 0)
        {
            break;
        }
        cout << i << endl;
    }
    */

//goto
    /*
    cout << "1" << endl;

    goto FLAG;

    cout << "2" << endl;
    cout << "3" << endl;

    FLAG:
    cout << "4" << endl;
    */

//数组
    /*
    // int score1[10];
    int score2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int score3[] = {2, 4, 1, 5, 3};

    for(int i = 0; i < 10; i++)
    {
        // cout << score1[i];
        cout << score2[i];
        cout << score3[i] << endl;
    }
    */

   /*
   int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

   cout << "整个数组所占内存空间为：" << sizeof(arr) << endl;
   cout << "每个元素所占内存空间为：" << sizeof(arr[0]) << endl;
   cout << "数组的元素个数为：" << sizeof(arr) / sizeof(arr[0]) << endl;
   
   cout << "数组首地址为：" << arr << endl;
   cout << "数组中第一个元素的地址为：" << &arr[0] << endl;
   cout << "数组中第二个元素的地址为：" << &arr[1] << endl;
    */

//冒泡排序
    /*
    int arr[9] = {4, 2, 8, 0, 5, 7, 1, 3, 9};
    int trans;
    //共有9个数字，只许进行8次排序，故i < 8，共进行0 1 2 3 4 5 6 7 共8次
    for(int i = 0; i < 8; i++)
    {
        //第一次排序时，j+1应该为arr中最后一位，即arr[8]，故j最大取7
        for(int j = 0; j < 9-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                trans = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = trans;
            }
        }
    }
    for(int i = 0; i < 9; i++)
    {
        cout << arr[i] <<endl;
    }
    */

//二维数组
    /*
    int arr2_1[2][3] = 
    {
        {0, 1, 2},
        {2, 1, 0}
    };

    int arr2_2[2][3] = {0, 1, 2, 2, 1, 3};

    //定义二维数组时如果初始化了数据，可以省略行数
    int arr2_3[][3] = {0, 2, 1, 3, 2, 1};

    cout << "二维数组的大小为：" << sizeof(arr2_1) << endl;
    cout << "二维数组的一行的大小为：" << sizeof(arr2_1[0]) << endl;
    cout << "二维数组的行数为：" << sizeof(arr2_1) / sizeof(arr2_1[0]) << endl;
    cout << "二维数组的列数为：" << sizeof(arr2_1[0]) / sizeof(arr2_1[0][0]) << endl;
    cout << "二维数组中每个元素的大小为：" << sizeof(arr2_1[0][0]) << endl;

    cout << "二维数组的首地址为：" << arr2_1 << endl;
    cout << "二维数组的第一行地址为" << arr2_1[0] << endl;
    cout << "二维数组的第二个元素地址为：" << &arr2_1[0][1] << endl;

    // string names[3] = {"张三", "李四", "王五"};
    char names[3] = {'a', 'b', 'c'};
    cout << names[1] << endl;
    */


    system("pause");
    return 0;
    
}