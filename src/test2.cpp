#include <iostream>
#include <math.h>
#include <string>

using namespace std;

//函数
    //声明
    int max(int a, int b);
    //定义
    int max(int a, int b)
    {
        return a > b ? a : b;
    }


int main()
{
    int num1 = 100;
    int num2 = 150;
    int num_max = max(num1, num2);
    cout << num_max << endl;

    system("pause");
    
    return 0;
}




