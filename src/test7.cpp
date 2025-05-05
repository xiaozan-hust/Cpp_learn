#include <iostream>
#include <string>
#include "operator.h"

using namespace std;

int main(){
    happy h1;
    cout << h1.m_A << "\t" << h1.m_B << endl;
// 运算符重载 + 号
    /*
    happy h2 = h1 + 10; // 相当于 operator+(h1, 10);
    happy h3 = h2 + h1; // 相当于 operator+(h2, h1);
    happy h4 = h1.operator+(h2); // 相当于 h1 + h2
    cout << h2.m_A << "\t" << h2.m_B << endl;
    cout << h3.m_A << "\t" << h3.m_B << endl;
    cout << h4.m_A << "\t" << h4.m_B << endl;
    */
// 运算符重载 << 
    /*
    cout << h1 << endl;
    cout << h1 << "hello world" << endl;
    */
// 运算符重载 ++
    /*
    cout << h1++ << endl;
    cout << ++h1 << endl;
    */

    return 0;
}